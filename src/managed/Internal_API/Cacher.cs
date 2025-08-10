using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq.Expressions;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using SwiftlyS2.API;

namespace SwiftlyS2.Internal_API
{
    public unsafe class Cacher
    {
        static readonly Dictionary<Type, int> _sizeCache = new Dictionary<Type, int>
        {
            { typeof(IntPtr), sizeof(IntPtr) },
            { typeof(bool), sizeof(bool) },
            { typeof(byte), sizeof(byte) },
            { typeof(sbyte), sizeof(sbyte) },
            { typeof(char), sizeof(char) },
            { typeof(short), sizeof(short) },
            { typeof(ushort), sizeof(ushort) },
            { typeof(int), sizeof(int) },
            { typeof(uint), sizeof(uint) },
            { typeof(long), sizeof(long) },
            { typeof(ulong), sizeof(ulong) },
            { typeof(float), sizeof(float) },
            { typeof(double), sizeof(double) },
            { typeof(string), sizeof(IntPtr) },
            { typeof(Array), sizeof(IntPtr) },
            { typeof(IDictionary), sizeof(IntPtr) },
            { typeof(Action), sizeof(IntPtr) },
            { typeof(ClassData), sizeof(IntPtr) },
        };

        static readonly Type[] _cacheWarmupTypes = [
            typeof(IntPtr),
            typeof(bool),
            typeof(byte),
            typeof(sbyte),
            typeof(char),
            typeof(short),
            typeof(ushort),
            typeof(int),
            typeof(uint),
            typeof(long),
            typeof(ulong),
            typeof(float),
            typeof(double),
            typeof(string),
            typeof(ClassData),
        ];

        static readonly Dictionary<Type, bool> _isPointerCache = [];
        static readonly Dictionary<string, IntPtr> _stringCacher = [];

        static readonly ConcurrentDictionary<Type, Func<int, Array>> _arrayCtorCache = new();
        static readonly ConcurrentDictionary<(Type, Type), Func<object>> _dictCtorCache = new();

        static readonly Dictionary<string, object> _cacher = [];

        public static int GetTypeSize(Type t)
        {
            if (_sizeCache.ContainsKey(t)) return _sizeCache[t];

            int size = Marshal.SizeOf(t);
            _sizeCache[t] = size;
            return size;
        }

        public static int GetTypeSize(ref Type t)
        {
            if (_sizeCache.ContainsKey(t)) return _sizeCache[t];

            int size = Marshal.SizeOf(t);
            _sizeCache[t] = size;
            return size;
        }

        public static int GetTypeSize<T>()
        {
            return Unsafe.SizeOf<T>();
        }

        public static bool ConsiderTypeAPointer(ref Type t)
        {
            if(_isPointerCache.TryGetValue(t, out bool value)) return value;

            value = (t == typeof(ClassData) || typeof(ClassData).IsAssignableFrom(t) || t == typeof(IntPtr) || t == typeof(string) || t.IsArray || typeof(IDictionary).IsAssignableFrom(t));
            _isPointerCache[t] = value;
            return value;
        }

        public static int GetTypeID(ref Type t)
        {
            if (t.IsArray) return CallContext.typesMap[typeof(Array)];
            else if (typeof(IDictionary).IsAssignableFrom(t)) return CallContext.typesMap[typeof(IDictionary)];
            else if (t == typeof(ClassData) || typeof(ClassData).IsAssignableFrom(t)) return CallContext.typesMap[typeof(ClassData)];
            else return CallContext.typesMap[t];
        }
        public static int GetTypeID(Type t)
        {
            int id = 0;

            if (t.IsArray) CallContext.typesMap.TryGetValue(typeof(Array), out id);
            else if (typeof(IDictionary).IsAssignableFrom(t)) CallContext.typesMap.TryGetValue(typeof(IDictionary), out id);
            else if (t == typeof(ClassData) || typeof(ClassData).IsAssignableFrom(t)) CallContext.typesMap.TryGetValue(typeof(ClassData), out id);
            else CallContext.typesMap.TryGetValue(t, out id);

            return id;
        }

        public static unsafe IntPtr GenerateStringPointer(string str)
        {
            if(str == null) return IntPtr.Zero;
            if(_stringCacher.ContainsKey(str)) return _stringCacher[str];

            var b = Encoding.UTF8.GetBytes(str + "\0");
            void* ptr = NativeMemory.Alloc((nuint)b.Length);

            fixed (byte* src = b)
            {
                Buffer.MemoryCopy(src, ptr, b.Length, b.Length);
            }

            IntPtr p = (IntPtr)ptr;
            _stringCacher[str] = p;
            return p;
        }

        public static unsafe void ClearStringPointersCache(string str)
        {
            foreach(var v in _stringCacher)
            {
                NativeMemory.Free((void*)v.Value);
            }
            _stringCacher.Clear();
        }

        public static Func<object, object[], object> CreateInvoker(MethodInfo method)
        {
            if (method == null) throw new ArgumentNullException(nameof(method));

            var targetType = method.DeclaringType;

            var instanceParam = Expression.Parameter(typeof(object), "target");
            var argsParam = Expression.Parameter(typeof(object[]), "args");

            var methodParams = method.GetParameters();

            var arguments = new Expression[methodParams.Length];

            for (int i = 0; i < methodParams.Length; i++)
            {
                var indexExpr = Expression.Constant(i);
                var paramAccess = Expression.ArrayIndex(argsParam, indexExpr);
                var paramCast = Expression.Convert(paramAccess, methodParams[i].ParameterType);
                arguments[i] = paramCast;
            }

            Expression instanceCast = method.IsStatic
                ? null
                : Expression.Convert(instanceParam, targetType);

            Expression methodCall = Expression.Call(instanceCast, method, arguments);

            Expression body = method.ReturnType == typeof(void)
                ? Expression.Block(methodCall, Expression.Constant(null, typeof(object)))
                : Expression.Convert(methodCall, typeof(object));

            var lambda = Expression.Lambda<Func<object, object[], object>>(body, instanceParam, argsParam);
            return lambda.Compile();
        }

        public static Func<int, Array> BuildArrayCtor(Type t)
        {
            var param = Expression.Parameter(typeof(int), "length");
            var newarr = Expression.NewArrayBounds(t, param);
            var lambda = Expression.Lambda<Func<int, Array>>(newarr, param);
            return lambda.Compile();
        }

        public static Func<object> BuildDictCtor((Type, Type) t)
        {
            var dictType = typeof(Dictionary<,>).MakeGenericType(t.Item1, t.Item2);
            var newExpr = Expression.New(dictType);
            var lambda = Expression.Lambda<Func<object>>(Expression.Convert(newExpr, typeof(object)));
            return lambda.Compile();
        }

        public static Array CreateArray(Type element, int length)
        {
            return _arrayCtorCache.GetOrAdd(element, BuildArrayCtor)(length);
        }

        public static object CreateDict(Type key, Type value)
        {
            return _dictCtorCache.GetOrAdd((key, value), BuildDictCtor)();
        }

        public static void PrepareCache()
        {
            foreach(Type t in _cacheWarmupTypes)
            {
                // Load Array Ctor Cache
                _arrayCtorCache.TryAdd(t, BuildArrayCtor(t));

                // Load Dict Ctor Cache
                foreach(Type k in _cacheWarmupTypes)
                {
                    if (_dictCtorCache.ContainsKey((t, k))) continue;
                    _dictCtorCache.TryAdd((t, k), BuildDictCtor((t,k)));
                }

                // Load Pointer Cache
                Type tmp = t;
                ConsiderTypeAPointer(ref tmp);
            }

            GenerateStringPointer("_G");
        }

        public static object CacheValue(string key, Func<object> call)
        {
            if (_cacher.TryGetValue(key, out object? value)) return value;

            value = call();
            _cacher[key] = value;
            return value;
        }
    }
}
