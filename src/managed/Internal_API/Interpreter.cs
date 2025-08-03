using System.Collections;
using SwiftlyS2.API;

namespace SwiftlyS2.Internal_API
{
    public class Interpreter
    {
        private static readonly Dictionary<int, Type> revTypesMap = new Dictionary<int, Type>
        {
            { 1, typeof(IntPtr) },
            { 2, typeof(bool) },
            { 3, typeof(byte) },
            { 4, typeof(sbyte) },
            { 5, typeof(char) },
            { 6, typeof(short) },
            { 7, typeof(ushort) },
            { 8, typeof(int) },
            { 9, typeof(uint) },
            { 10, typeof(long) },
            { 11, typeof(ulong) },
            { 12, typeof(float) },
            { 13, typeof(double) },
            { 14, typeof(string) },
            { 15, typeof(Array) },
            { 16, typeof(IDictionary) },
            { 17, typeof(Action) },
            { 18, typeof(ClassData) },
        };

        public static unsafe string? TryInterpretUnknownPtr(IntPtr ptr, int type)
        {
            if (ptr == IntPtr.Zero)
                return null;

            if (type == 15) return "Array";
            else if (type == 16) return "Dictionary";
            else if (type == 17) return "Function";

            Type t = revTypesMap[type];
            byte* p = (byte*)ptr;
            return CallContext.ReadValue(ref t, ref p).ToString();
        }

    }
}
