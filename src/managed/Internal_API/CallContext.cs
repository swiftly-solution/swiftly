using System.Collections;
using System.Collections.Concurrent;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using SwiftlyS2.API;

/**
 * This file API is inspired from FiveM's C# resources implementation.
 * All credits go to the CFX.re project located at https://github.com/citizenfx/fivem (https://cfx.re)
 * 
 * Copyright (c) 2014 Bas Timmer/NTAuthority et al.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * This file has been modified from its original form for use in this program
 * under GNU Lesser General Public License, version 2.
 */

namespace SwiftlyS2.Internal_API
{
    [StructLayout(LayoutKind.Sequential)]
    public unsafe struct MapData
    {
        public byte* Keys;
        public byte* Values;
        public int keyType;
        public int valueType;
        public int Length;
    };

    [StructLayout(LayoutKind.Sequential)]
    public unsafe struct ArrayData
    {
        public byte* Elements;
        public int Length;
        public int type;
    }

    [StructLayout(LayoutKind.Sequential)]
    [Serializable]
    public unsafe struct CallData
    {
        public int args_count;
        public int has_return;

        public fixed byte args_data[8 * 64];
        public fixed int args_type[64];

        public fixed byte return_value[8];
        public int return_type;

        public IntPtr ns_ptr;
        public int ns_length;

        public IntPtr func_ptr;
        public int func_length;

        public int call_kind;
    }

    public class CallContext
    {
        [ThreadStatic]
        private static CallContext? _globalScriptContext;

        public static CallContext GlobalScriptContext
        {
            get
            {
                if (_globalScriptContext == null) _globalScriptContext = new CallContext();
                return _globalScriptContext;
            }
        }


        public static Dictionary<Type, int> typesMap = new Dictionary<Type, int>
        {
            { typeof(IntPtr), 1 },
            { typeof(bool), 2 },
            { typeof(byte), 3 },
            { typeof(sbyte), 4 },
            { typeof(char), 5 },
            { typeof(short), 6 },
            { typeof(ushort), 7 },
            { typeof(int), 8 },
            { typeof(uint), 9 },
            { typeof(long), 10 },
            { typeof(ulong), 11 },
            { typeof(float), 12 },
            { typeof(double), 13 },
            { typeof(string), 14 },
            { typeof(Array), 15 },
            { typeof(IDictionary), 16 },
            { typeof(Action), 17 },
            { typeof(ClassData), 18 },
        };

        public unsafe CallContext()
        {
        }

        public unsafe CallContext(CallData* data)
        {
            m_cdata = *data;
        }

        internal CallData m_cdata = new();

        private readonly ConcurrentQueue<Action> finalizers = new ConcurrentQueue<Action> ();
        private readonly object ms_lock = new object();
        internal object Lock => ms_lock;
        internal bool isCleanupLocked = false;

        public void SetCleanupLock(bool state)
        {
            isCleanupLocked = state;
        }

        public void Reset()
        {
            m_cdata.args_count = 0;
            m_cdata.has_return = 0;

            if(!isCleanupLocked)
            {
                while (finalizers.TryDequeue(out var cb))
                {
                    cb();
                }
            }
        }

        [SecurityCritical]
        public unsafe void SetCallKind(CallKind call_kind)
        {
            fixed (CallData* data = &m_cdata)
            {
                data->call_kind = (int)call_kind;
            }
        }

        [SecurityCritical]
        public unsafe void SetFunction(string ns, string func)
        {
            fixed (CallData* data = &m_cdata)
            {
                var b = Encoding.UTF8.GetBytes(ns);

                var ns_ptr = Marshal.AllocHGlobal(b.Length + 1);
                Marshal.Copy(b, 0, ns_ptr, b.Length);
                Marshal.WriteByte(ns_ptr, b.Length, 0);

                data->ns_ptr = ns_ptr;
                data->ns_length = b.Length;

                finalizers.Enqueue(() => Marshal.FreeHGlobal(ns_ptr));

                b = Encoding.UTF8.GetBytes(func);

                var func_ptr = Marshal.AllocHGlobal(b.Length + 1);
                Marshal.Copy(b, 0, func_ptr, b.Length);
                Marshal.WriteByte(func_ptr, b.Length, 0);

                data->func_ptr = func_ptr;
                data->func_length = b.Length;

                finalizers.Enqueue(() => Marshal.FreeHGlobal(func_ptr));
            }
        }

        [SecuritySafeCritical]
        public unsafe void PushArgument(object value)
        {
            fixed (CallData* data = &m_cdata)
            {
                PushObject(value, data);
            }
        }

        [SecurityCritical]
        internal unsafe object PushInternal(object value)
        {
            if(value is string)
            {
                var str = (string)Convert.ChangeType(value, typeof(string));
                var ptr = PushString(str);

                return ptr;
            }
            else if(value is Array)
            {
                var arr = (Array)value;
                if(arr == null) return IntPtr.Zero;

                return PushArray(arr);
            }
            else if(value is IDictionary)
            {
                var arr = (IDictionary)value;
                if (arr == null) return IntPtr.Zero;

                return PushDict(arr);
            }
            else if(value is IntPtr)
            {
                return (IntPtr)Convert.ChangeType(value, typeof(IntPtr));
            }

            return value;
        }

        [SecurityCritical]
        internal unsafe void PushObject(object value, CallData* data)
        {
            if (value == null) value = 0;

            if (value.GetType().IsEnum)
            {
                value = Convert.ChangeType(value, value.GetType().GetEnumUnderlyingType());
                typesMap.TryGetValue(typeof(int), out data->args_type[data->args_count]);
            }

            if (value is string)
            {
                var ptr = PushInternal(value);

                unsafe
                {
                    *(IntPtr*)(&data->args_data[8 * data->args_count]) = (IntPtr)ptr;
                }

                typesMap.TryGetValue(typeof(string), out data->args_type[data->args_count]);
                data->args_count++;
                return;
            }
            else if (value is Array)
            {
                var arr = PushInternal(value);

                unsafe
                {
                    *(IntPtr*)(&data->args_data[8 * data->args_count]) = (IntPtr)arr;
                }

                typesMap.TryGetValue(typeof(Array), out data->args_type[data->args_count]);
                data->args_count++;
                return;
            }
            else if (value is IDictionary)
            {
                var arr = PushInternal(value);

                unsafe
                {
                    *(IntPtr*)(&data->args_data[8 * data->args_count]) = (IntPtr)arr;
                }

                typesMap.TryGetValue(typeof(IDictionary), out data->args_type[data->args_count]);
                data->args_count++;
                return;
            }
            else if (value is IntPtr)
            {
                var ptr = (IntPtr)PushInternal(value);

                unsafe
                {
                    *(IntPtr*)(&data->args_data[8 * data->args_count]) = ptr;
                }

                typesMap.TryGetValue(typeof(IntPtr), out data->args_type[data->args_count]);
                data->args_count++;
                return;
            }
            else if (value is EValue ea)
            {
                PushObject(ea.Value, data);
                return;
            }

            typesMap.TryGetValue(value.GetType(), out data->args_type[data->args_count]);
            if (data->args_type[data->args_count] == 0)
            {
                throw new Exception($"Invalid data type tried to be pushed: {value.GetType().FullName}");
            }

            if (Marshal.SizeOf(value.GetType()) <= 8)
            {
                *(long*)(&data->args_data[8 * data->args_count]) = 0;
                Marshal.StructureToPtr(value, new IntPtr(data->args_data + (8 * data->args_count)), true);
                data->args_count++;
                return;
            }
        }

        [SecurityCritical]
        internal unsafe IntPtr PushDict(IDictionary dict)
        {
            Type[] dictTypes = dict.GetType().GetGenericArguments();
            int count = dict.Count;

            for(int i = 0; i < dictTypes.Length; i++)
            {
                if (dictTypes[i].IsEnum)
                {
                    dictTypes[i] = dictTypes[i].GetEnumUnderlyingType();
                }
            }

            bool isKeyPointer = (dictTypes[0] == typeof(IntPtr) || dictTypes[0] == typeof(string) || dictTypes[0].IsArray || typeof(IDictionary).IsAssignableFrom(dictTypes[0]));
            bool isValuePointer = (dictTypes[1] == typeof(IntPtr) || dictTypes[1] == typeof(string) || dictTypes[1].IsArray || typeof(IDictionary).IsAssignableFrom(dictTypes[1]));

            int keySize = Marshal.SizeOf(isKeyPointer ? sizeof(IntPtr) : dictTypes[0]);
            int valueSize = Marshal.SizeOf(isValuePointer ? sizeof(IntPtr) : dictTypes[1]);

            IntPtr keysArray = Marshal.AllocHGlobal(keySize * count);
            IntPtr valuesArray = Marshal.AllocHGlobal(valueSize * count);

            int valuesCounter = 0;

            int mapDataSize = Marshal.SizeOf(typeof(MapData));
            IntPtr structPtr = Marshal.AllocHGlobal(mapDataSize);

            MapData* p = (MapData*)structPtr.ToPointer();
            
            p->Keys = (byte*)keysArray;
            p->Values = (byte*)valuesArray;
            p->Length = count;

            if(dictTypes[0].IsArray) typesMap.TryGetValue(typeof(Array), out p->keyType);
            else if(typeof(IDictionary).IsAssignableFrom(dictTypes[0])) typesMap.TryGetValue(typeof(IDictionary), out p->keyType);
            else typesMap.TryGetValue(dictTypes[0], out p->keyType);

            if (dictTypes[1].IsArray) typesMap.TryGetValue(typeof(Array), out p->valueType);
            else if (typeof(IDictionary).IsAssignableFrom(dictTypes[1])) typesMap.TryGetValue(typeof(IDictionary), out p->valueType);
            else typesMap.TryGetValue(dictTypes[1], out p->valueType);

            if(p->keyType == 0 || p->valueType == 0)
            {
                throw new Exception($"Invalid key or value type. (Key={dictTypes[0].FullName}, Value={dictTypes[1].FullName})");
            }

            foreach (DictionaryEntry entry in dict)
            {
                if (isKeyPointer)
                {
                    Marshal.WriteIntPtr(keysArray, valuesCounter * keySize, (IntPtr)PushInternal(entry.Key));
                }
                else
                {
                    Marshal.StructureToPtr(PushInternal(entry.Key!), keysArray + (valuesCounter * keySize), false);
                }

                if (isValuePointer)
                {
                    Marshal.WriteIntPtr(valuesArray, valuesCounter * valueSize, entry.Value == null ? IntPtr.Zero : (IntPtr)PushInternal(entry.Value));
                }
                else
                {
                    Marshal.StructureToPtr(entry.Value == null ? 0 : PushInternal(entry.Value), valuesArray + (valuesCounter * valueSize), false);
                }

                valuesCounter++;
            }

            finalizers.Enqueue(() => Marshal.FreeHGlobal(keysArray));
            finalizers.Enqueue(() => Marshal.FreeHGlobal(valuesArray));
            finalizers.Enqueue(() => Marshal.FreeHGlobal(structPtr));

            return structPtr;
        }

        [SecurityCritical]
        internal unsafe IntPtr PushArray(Array array)
        {
            Type? t = array.GetType().GetElementType();
            if (t == null) return IntPtr.Zero;

            if (t.IsEnum)
            {
                t = t.GetEnumUnderlyingType();
            }


            int arrayDataSize = Marshal.SizeOf(typeof(ArrayData));
            IntPtr structPtr = Marshal.AllocHGlobal(arrayDataSize);

            ArrayData* p = (ArrayData*)structPtr.ToPointer();

            bool isPointer = (t == typeof(IntPtr) || t == typeof(string) || t.IsArray || typeof(IDictionary).IsAssignableFrom(t));
            int elementSize = Marshal.SizeOf(isPointer ? typeof(IntPtr) : t);
            IntPtr arrayPtr = Marshal.AllocHGlobal(elementSize * array.Length);

            p->Length = array.Length;
            p->Elements = (byte*)arrayPtr;

            if (t.IsArray) p->type = typesMap.GetValueOrDefault(typeof(Array));
            else if(typeof(IDictionary).IsAssignableFrom(t)) p->type = typesMap.GetValueOrDefault(typeof(IDictionary));
            else typesMap.TryGetValue(t, out p->type);

            var i = 0;
            IEnumerator enums = array.GetEnumerator();
            while(enums.MoveNext())
            {
                if (isPointer)
                {
                    Marshal.WriteIntPtr(arrayPtr, i * elementSize, (IntPtr)PushInternal(enums.Current));
                }
                else
                {
                    Marshal.StructureToPtr(PushInternal(enums.Current), arrayPtr + (i * elementSize), false);
                }
                i++;
            }

            finalizers.Enqueue(() => Marshal.FreeHGlobal(arrayPtr));
            finalizers.Enqueue(() => Marshal.FreeHGlobal(structPtr));
            return structPtr;
        }

        [SecurityCritical]
        internal unsafe IntPtr PushString(string str)
        {
            if(str == null) return IntPtr.Zero;

            var b = Encoding.UTF8.GetBytes(str);

            var ptr = Marshal.AllocHGlobal(b.Length + 1);

            Marshal.Copy(b, 0, ptr, b.Length);
            Marshal.WriteByte(ptr, b.Length, 0);

            finalizers.Enqueue(() => Marshal.FreeHGlobal(ptr));
            return ptr;
        }

        [SecuritySafeCritical]
        public unsafe void SetReturn(object value)
        {
            fixed (CallData* data = &m_cdata)
            {
                SetReturnObject(value, data);
            }
        }

        [SecurityCritical]
        internal unsafe void SetReturnObject(object value, CallData* data)
        {
            if (value == null) value = 0;

            if (value.GetType().IsEnum)
            {
                value = Convert.ChangeType(value, value.GetType().GetEnumUnderlyingType());
                typesMap.TryGetValue(typeof(int), out data->return_type);
            }

            if (value is string)
            {
                var str = (string)Convert.ChangeType(value, typeof(string));
                var ptr = PushString(str);

                unsafe
                {
                    *(IntPtr*)(&data->return_value[8]) = ptr;
                }

                typesMap.TryGetValue(typeof(string), out data->return_type);
                return;
            }
            else if (value is Array)
            {
                unsafe
                {
                    *(IntPtr*)(&data->return_value[8]) = (nint)PushInternal(value);
                }

                typesMap.TryGetValue(typeof(Array), out data->return_type);
                return;
            }
            else if (value is IDictionary)
            {
                unsafe
                {
                    *(IntPtr*)(&data->return_value[8]) = (nint)PushInternal(value);
                }

                typesMap.TryGetValue(typeof(IDictionary), out data->return_type);
                return;
            }
            else if (value is IntPtr)
            {
                var ptr = (IntPtr)Convert.ChangeType(value, typeof(IntPtr));

                unsafe
                {
                    *(IntPtr*)(&data->return_value[8]) = ptr;
                }

                typesMap.TryGetValue(typeof(IntPtr), out data->return_type);
                return;
            }
            else if (value is EValue ea)
            {
                SetReturnObject(ea.Value, data);
                return;
            }

            typesMap.TryGetValue(value.GetType(), out data->return_type);
            if (data->return_type == 0)
            {
                throw new Exception($"Invalid data type tried to be set as return: {value.GetType().FullName}");
            }
            
            if (Marshal.SizeOf(value.GetType()) <= 8)
            {
                *(long*)(&data->return_value[0]) = 0;
                Marshal.StructureToPtr(value, new IntPtr(data->return_value), true);
                return;
            }
        }

        [SecuritySafeCritical]
        public T GetArgument<T>(int index)
        {
            return (T)GetArgument(typeof(T), index);
        }

        [SecurityCritical]
        internal unsafe object GetArgument(Type type, int index)
        {
            fixed (CallData* data = &m_cdata)
            {
                return ReadValue(type, &data->args_data[index * 8]);
            }
        }

        [SecuritySafeCritical]
        public T GetReturn<T>()
        {
            return (T)GetReturn(typeof(T));
        }

        [SecurityCritical]
        internal unsafe object GetReturn(Type type)
        {
            fixed (CallData* data = &m_cdata)
            {
                return ReadValue(type, &data->return_value[0]);
            }
        }

        [SecurityCritical]
        public static unsafe object ReadValue(Type type, byte* ptr)
        {
            if(type == typeof(string))
            {
                var natUTF8 = *(IntPtr*)&ptr[0];

                if (natUTF8 == IntPtr.Zero) return null;

                var len = 0;
                while(Marshal.ReadByte(natUTF8, len) != 0)
                {
                    ++len;
                }

                var buf = new byte[len];
                Marshal.Copy(natUTF8, buf, 0, buf.Length);
                return Encoding.UTF8.GetString(buf);
            }

            if(type.IsEnum)
            {
                return Enum.ToObject(type, (int)ReadValue(typeof(int), ptr));
            }

            if(type.IsArray)
            {
                IntPtr p = *(IntPtr*)ptr;
                ArrayData data = Marshal.PtrToStructure<ArrayData>(p);

                Array? arr = (Array?)Activator.CreateInstance(type, data.Length);
                if (arr == null) return null;

                bool isPointer = (type.GetElementType()! == typeof(IntPtr) || type.GetElementType()! == typeof(string) || type.GetElementType()!.IsArray || typeof(IDictionary).IsAssignableFrom(type.GetElementType()!));
                int elemSize = Marshal.SizeOf(isPointer ? typeof(IntPtr) : type.GetElementType()!);

                for (int i = 0; i < data.Length; i++) arr.SetValue(ReadValue(type.GetElementType()!, &data.Elements[i*elemSize]), i);

                return arr;
            }

            if (typeof(IDictionary).IsAssignableFrom(type))
            {
                IDictionary? dict = Activator.CreateInstance(type) as IDictionary;
                if (dict == null) return null;

                IntPtr p = *(IntPtr*)ptr;
                MapData data = Marshal.PtrToStructure<MapData>(p);

                IntPtr* keys = (IntPtr*)data.Keys;
                IntPtr* values = (IntPtr*)data.Values;

                bool isKeyPointer = (type.GetGenericArguments()[0] == typeof(IntPtr) || type.GetGenericArguments()[0] == typeof(string) || type.GetGenericArguments()[0].IsArray || typeof(IDictionary).IsAssignableFrom(type.GetGenericArguments()[0]));
                int keySize = Marshal.SizeOf(isKeyPointer ? typeof(IntPtr) : type.GetGenericArguments()[0]);

                bool isValuePointer = (type.GetGenericArguments()[1] == typeof(IntPtr) || type.GetGenericArguments()[1] == typeof(string) || type.GetGenericArguments()[1].IsArray || typeof(IDictionary).IsAssignableFrom(type.GetGenericArguments()[1]));
                int valueSize = Marshal.SizeOf(isValuePointer ? typeof(IntPtr) : type.GetGenericArguments()[1]);

                for (int i = 0; i < data.Length; i++)
                {
                    dict.Add(
                        ReadValue(type.GetGenericArguments()[0], &data.Keys[i*keySize]), 
                        ReadValue(type.GetGenericArguments()[1], &data.Values[i*valueSize])
                    );
                }

                return dict;
            }

            if(type == typeof(IntPtr))
            {
                return *(IntPtr*)ptr;
            }

            if(Marshal.SizeOf(type) <= 8)
            {
                var obj = Marshal.PtrToStructure(new IntPtr(ptr), type);
                return obj;
            }

            return null;
        }

        [SecuritySafeCritical]
        public void InvokeFunction()
        {
            if(!isCleanupLocked)
            {
                isCleanupLocked = true;
                InvokeFunctionInternal();
                isCleanupLocked = false;
                return;
            }

            InvokeFunctionInternal();
        }

        [SecurityCritical]
        private void InvokeFunctionInternal()
        {
            unsafe
            {
                fixed (CallData* data = &m_cdata)
                {
                    if (Invoker.MyInvokeNative != null)
                    {
                        IntPtr cdata = new IntPtr(data);

                        Invoker.MyInvokeNative!(cdata);
                    }
                }
            }
        }

        [SecurityCritical]
        public IntPtr AllocatePointer(int elementSize, int count)
        {
            IntPtr ptr = Marshal.AllocHGlobal(elementSize * count);
            finalizers.Enqueue(() => Marshal.FreeHGlobal(ptr));
            return ptr;
        }
    }
}
