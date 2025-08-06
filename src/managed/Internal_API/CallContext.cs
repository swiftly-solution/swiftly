using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using SwiftlyS2.API;
using SwiftlyS2.API.Scripting;
using static SwiftlyS2.API.Scripting.Entities;

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

        public IntPtr dbginfo_ptr;
        public int dbginfo_length;

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
        private readonly object ms_lock = new();
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
                data->ns_ptr = Cacher.GenerateStringPointer(ns);
                data->ns_length = ns.Length;

                data->func_ptr = Cacher.GenerateStringPointer(func);
                data->func_length = func.Length;
            }
        }

        [SecurityCritical]
        public unsafe void SetDebugInfo(string info)
        {
            fixed (CallData* data = &m_cdata)
            {
                data->dbginfo_ptr = Cacher.GenerateStringPointer(info);
                data->dbginfo_length = info.Length;
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
                if (value == null) value = "";
                return PushString(value.ToString() ?? "");
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
                return (IntPtr)value;
            }
            else if (value is ClassData v)
            {
                return v.GetClassDataPtr();
            }

            return value;
        }

        internal static unsafe void WritePrimitiveToPointer(ref object value, ref void* dest)
        {
            switch(value)
            {
                case bool b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case char c:
                    Unsafe.WriteUnaligned(dest, c); break;
                case sbyte b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case byte b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case short b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case ushort b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case int b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case uint b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case long b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case ulong b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case float b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case double b:
                    Unsafe.WriteUnaligned(dest, b); break;
                case decimal b:
                    Unsafe.WriteUnaligned(dest, b); break;
            }
        }

        internal static unsafe object ReadPointerToPrimitive(ref byte* ptr, ref Type type)
        {
            ref byte start = ref ptr[0];

            if (type == typeof(bool)) return (Unsafe.ReadUnaligned<bool>(ref start));
            if (type == typeof(char)) return Unsafe.ReadUnaligned<char>(ref start);
            if (type == typeof(sbyte)) return Unsafe.ReadUnaligned<sbyte>(ref start);
            if (type == typeof(byte)) return Unsafe.ReadUnaligned<byte>(ref start);
            if (type == typeof(short)) return Unsafe.ReadUnaligned<short>(ref start);
            if (type == typeof(ushort)) return Unsafe.ReadUnaligned<ushort>(ref start);
            if (type == typeof(int)) return Unsafe.ReadUnaligned<int>(ref start);
            if (type == typeof(uint)) return Unsafe.ReadUnaligned<uint>(ref start);
            if (type == typeof(long)) return Unsafe.ReadUnaligned<long>(ref start);
            if (type == typeof(ulong)) return Unsafe.ReadUnaligned<ulong>(ref start);
            if (type == typeof(float)) return Unsafe.ReadUnaligned<float>(ref start);
            if (type == typeof(double)) return Unsafe.ReadUnaligned<double>(ref start);
            if (type == typeof(decimal)) return Unsafe.ReadUnaligned<decimal>(ref start);
            return IntPtr.Zero;
        }

        [SecurityCritical]
        internal unsafe void PushObject(object value, CallData* data)
        {
            if (value == null) value = 0;

            if (value.GetType().IsEnum)
            {
                value = Convert.ToInt64(value);
            }

            if (value is string)
            {
                var ptr = PushInternal(value);

                *(IntPtr*)(&data->args_data[data->args_count << 3]) = (IntPtr)ptr;

                data->args_type[data->args_count] = Cacher.GetTypeID(typeof(string));
                data->args_count++;
                return;
            }
            else if (value is Array)
            {
                var arr = PushInternal(value);

                unsafe
                {
                    *(IntPtr*)(&data->args_data[data->args_count << 3]) = (IntPtr)arr;
                }

                data->args_type[data->args_count] = Cacher.GetTypeID(typeof(Array));
                data->args_count++;
                return;
            }
            else if (value is IDictionary)
            {
                var arr = PushInternal(value);

                unsafe
                {
                    *(IntPtr*)(&data->args_data[data->args_count << 3]) = (IntPtr)arr;
                }

                data->args_type[data->args_count] = Cacher.GetTypeID(typeof(IDictionary));
                data->args_count++;
                return;
            }
            else if (value is IntPtr)
            {
                var ptr = (IntPtr)PushInternal(value);

                unsafe
                {
                    *(IntPtr*)(&data->args_data[data->args_count << 3]) = ptr;
                }

                data->args_type[data->args_count] = Cacher.GetTypeID(typeof(IntPtr));
                data->args_count++;
                return;
            }
            else if (value is EValue ea)
            {
                PushObject(ea.Value, data);
                return;
            }
            else if(value is ClassData)
            {
                var ptr = (IntPtr)PushInternal(value);

                unsafe
                {
                    *(IntPtr*)(&data->args_data[data->args_count << 3]) = ptr;
                }

                data->args_type[data->args_count] = Cacher.GetTypeID(typeof(ClassData));
                data->args_count++;
                return;
            }

            Type t = value.GetType();

            data->args_type[data->args_count] = Cacher.GetTypeID(ref t);
            if (data->args_type[data->args_count] == 0)
            {
                throw new Exception($"Invalid data type tried to be pushed: {t.FullName}");
            }

            *(long*)(&data->args_data[data->args_count << 3]) = 0;
            void* p = (void*)(new IntPtr(data->args_data + (data->args_count << 3)));
            WritePrimitiveToPointer(ref value, ref p);
            data->args_count++;
            return;
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

            bool isKeyPointer = Cacher.ConsiderTypeAPointer(ref dictTypes[0]);
            bool isValuePointer = Cacher.ConsiderTypeAPointer(ref dictTypes[1]);

            int keySize = isKeyPointer ? Cacher.GetTypeSize<IntPtr>() : Cacher.GetTypeSize(ref dictTypes[0]);
            int valueSize = isValuePointer ? Cacher.GetTypeSize<IntPtr>() : Cacher.GetTypeSize(ref dictTypes[1]);

            IntPtr keysArray = (nint)NativeMemory.Alloc((nuint)(keySize * count));
            IntPtr valuesArray = (nint)NativeMemory.Alloc((nuint)(valueSize * count));

            int valuesCounter = 0;

            int mapDataSize = Cacher.GetTypeSize<MapData>();
            IntPtr structPtr = (nint)NativeMemory.Alloc((nuint)mapDataSize);

            MapData* p = (MapData*)structPtr.ToPointer();
            
            p->Keys = (byte*)keysArray;
            p->Values = (byte*)valuesArray;
            p->Length = count;

            p->keyType = Cacher.GetTypeID(ref dictTypes[0]);
            p->valueType = Cacher.GetTypeID(ref dictTypes[1]);

            if(p->keyType == 0 || p->valueType == 0)
            {
                throw new Exception($"Invalid key or value type. (Key={dictTypes[0].FullName}, Value={dictTypes[1].FullName})");
            }

            foreach (DictionaryEntry entry in dict)
            {
                if (isKeyPointer)
                {
                    Unsafe.Write((void*)(keysArray + (valuesCounter * keySize)), (IntPtr)PushInternal(entry.Key));
                }
                else
                {
                    object v = PushInternal(entry.Key!);
                    void* pt = (void*)(keysArray + (valuesCounter * keySize));

                    WritePrimitiveToPointer(ref v, ref pt);
                }

                if (isValuePointer)
                {
                    Unsafe.Write((void*)(valuesArray + (valuesCounter * valueSize)), (entry.Value == null ? IntPtr.Zero : (IntPtr)PushInternal(entry.Value)));
                }
                else
                {
                    object v = entry.Value == null ? 0 : PushInternal(entry.Value);
                    void* pt = (void*)(valuesArray + (valuesCounter * valueSize));

                    WritePrimitiveToPointer(ref v, ref pt);
                }

                valuesCounter++;
            }

            finalizers.Enqueue(() => NativeMemory.Free((void*)keysArray));
            finalizers.Enqueue(() => NativeMemory.Free((void*)valuesArray));
            finalizers.Enqueue(() => NativeMemory.Free((void*)structPtr));

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


            IntPtr structPtr = (nint)NativeMemory.Alloc((nuint)Cacher.GetTypeSize<ArrayData>());

            ArrayData* p = (ArrayData*)structPtr.ToPointer();

            bool isPointer = Cacher.ConsiderTypeAPointer(ref t);
            int elementSize = isPointer ? Cacher.GetTypeSize<IntPtr>() : Cacher.GetTypeSize(ref t);
            IntPtr arrayPtr = (nint)NativeMemory.Alloc((nuint)(elementSize * array.Length));
            byte* arrAsBytes = (byte*)arrayPtr;

            p->Length = array.Length;
            p->Elements = (byte*)arrayPtr;
            p->type = Cacher.GetTypeID(ref t);

            var i = 0;
            IEnumerator enums = array.GetEnumerator();
            while(enums.MoveNext())
            {
                if (isPointer)
                {
                    Unsafe.Write((void*)(arrayPtr + (i * elementSize)), (IntPtr)PushInternal(enums.Current));
                }
                else
                {
                    object v = PushInternal(enums.Current);
                    void* pt = (void*)(arrayPtr + (i * elementSize));

                    WritePrimitiveToPointer(ref v, ref pt);
                }
                i++;
            }

            finalizers.Enqueue(() => NativeMemory.Free((void*)arrayPtr));
            finalizers.Enqueue(() => NativeMemory.Free((void*)structPtr));
            return structPtr;
        }

        [SecurityCritical]
        internal unsafe IntPtr PushString(string str)
        {
            if(str == null) return IntPtr.Zero;

            var b = Encoding.UTF8.GetBytes(str + "\0");
            void* ptr = NativeMemory.Alloc((nuint)b.Length);

            fixed(byte* src = b)
            {
                Buffer.MemoryCopy(src, ptr, b.Length, b.Length);
            }

            finalizers.Enqueue(() => NativeMemory.Free(ptr));
            return (nint)ptr;
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
                value = Convert.ToInt64(value);
            }

            Type t = value.GetType();

            if (value is string)
            {
                if (value == null) value = "";
                var str = value.ToString() ?? "";
                var ptr = PushString(str);

                *(IntPtr*)(data->return_value) = ptr;

                data->return_type = Cacher.GetTypeID(typeof(string));
                return;
            }
            else if (value is Array)
            {
                *(IntPtr*)(data->return_value) = (nint)PushInternal(value);

                data->return_type = Cacher.GetTypeID(typeof(Array));
                return;
            }
            else if (value is IDictionary)
            {
                *(IntPtr*)(data->return_value) = (nint)PushInternal(value);

                data->return_type = Cacher.GetTypeID(typeof(IDictionary));
                return;
            }
            else if (value is IntPtr)
            {
                var ptr = (IntPtr)value;

                *(IntPtr*)(data->return_value) = ptr;
                
                data->return_type = Cacher.GetTypeID(typeof(IntPtr));
                return;
            }
            else if (value is EValue ea)
            {
                SetReturnObject(ea.Value, data);
                return;
            }
            else if(value is ClassData)
            {
                *(IntPtr*)(data->return_value) = (nint)PushInternal(value);

                data->return_type = Cacher.GetTypeID(typeof(IntPtr));
                return;
            }

            data->return_type = Cacher.GetTypeID(ref t);
            if (data->return_type == 0)
            {
                throw new Exception($"Invalid data type tried to be set as return: {t.FullName}");
            }
            
            void* ret = data->return_value;
            *(long*)(ret) = 0;
            WritePrimitiveToPointer(ref value, ref ret);
            return;
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
                byte* p = &data->args_data[index<<3];
                return ReadValue(ref type, ref p);
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
                if (data->has_return == 0) return null;
                byte* p = data->return_value;
                return ReadValue(ref type, ref p);
            }
        }

        [SecurityCritical]
        public static unsafe object ReadValue(ref Type type, ref byte* ptr)
        {
            if (ptr == null) return null;
            if (type == typeof(string))
            {
                var natUTF8 = *(IntPtr*)&ptr[0];

                if (natUTF8 == IntPtr.Zero) return null;
                byte* str = (byte*)natUTF8;

                var len = 0;
                while (str[len++] != 0) { }

                return Encoding.UTF8.GetString(new ReadOnlySpan<byte>((void*)natUTF8, len));
            }
            else if(type == typeof(ClassData) || typeof(ClassData).IsAssignableFrom(type))
            {
                IntPtr p = *(IntPtr*)ptr;
                if (p == IntPtr.Zero) return null; 
                
                if(type == typeof(Memory) || type == typeof(CEntityKeyValues))
                {
                    ClassData? data = Activator.CreateInstance(type) as ClassData;
                    if (data == null) return null;

                    Invoker.FinalizeClassdata(data.GetClassDataPtr());
                    data.SetClassDataPtr(p);
                    return data;
                }
                else
                {
                    ClassData? data = Activator.CreateInstance(type) as ClassData;
                    if (data == null) return null;

                    data.SetClassDataPtr(p);
                    return data;
                }
            }
            else if (type.IsEnum)
            {
                Type t = typeof(int);
                return Enum.ToObject(type, (int)ReadValue(ref t, ref ptr));
            }
            else if(type.IsArray)
            {
                IntPtr p = *(IntPtr*)ptr;
                ArrayData *data = (ArrayData*)p;

                Type t = type.GetElementType()!;
                Array? arr = Cacher.CreateArray(t, data->Length);
                if (arr == null) return null;

                bool isPointer = Cacher.ConsiderTypeAPointer(ref t);
                int elemSize = isPointer ? Cacher.GetTypeSize<IntPtr>() : Cacher.GetTypeSize(ref t);

                for (int i = 0; i < data->Length; i++)
                {
                    byte* element = &data->Elements[elemSize * i];
                    arr.SetValue(ReadValue(ref t, ref element), i);
                }
                return arr;
            }
            else if (typeof(IDictionary).IsAssignableFrom(type))
            {
                Type keyType = type.GetGenericArguments()[0];
                Type valueType = type.GetGenericArguments()[1];

                IDictionary? dict = Cacher.CreateDict(keyType, valueType) as IDictionary;
                if (dict == null) return null;

                IntPtr p = *(IntPtr*)ptr;
                MapData* data = (MapData*)p;

                IntPtr* keys = (IntPtr*)data->Keys;
                IntPtr* values = (IntPtr*)data->Values;

                bool isKeyPointer = Cacher.ConsiderTypeAPointer(ref keyType);
                int keySize = isKeyPointer ? Cacher.GetTypeSize<IntPtr>() : Cacher.GetTypeSize(ref keyType);

                bool isValuePointer = Cacher.ConsiderTypeAPointer(ref valueType);
                int valueSize = isValuePointer ? Cacher.GetTypeSize<IntPtr>() : Cacher.GetTypeSize(ref valueType);

                for (int i = 0; i < data->Length; i++)
                {
                    byte* key = &data->Keys[keySize * i];
                    byte* value = &data->Values[valueSize * i];

                    dict.Add(
                        ReadValue(ref keyType, ref key), 
                        ReadValue(ref valueType, ref value)
                    );
                }

                return dict;
            }
            else if(type == typeof(IntPtr))
            {
                ref byte start = ref ptr[0];
                return Unsafe.ReadUnaligned<IntPtr>(ref start);
            }

            return ReadPointerToPrimitive(ref ptr, ref type);
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
        public unsafe IntPtr AllocatePointer(int elementSize, int count)
        {
            IntPtr ptr = (nint)NativeMemory.Alloc((nuint)(elementSize * count));
            finalizers.Enqueue(() => NativeMemory.Free((void*)ptr));
            return ptr;
        }
    }
}
