namespace SwiftlyS2.Internal_API
{
    public class Interpreter
    {
        public static unsafe string? TryInterpretUnknownPtr(IntPtr ptr, int type)
        {
            if (ptr == IntPtr.Zero)
                return null;

            if (type == 15) return "Array";
            else if (type == 16) return "Dictionary";
            else if (type == 17) return "Function";

            foreach (var entry in CallContext.typesMap)
            {
                if (entry.Value == type)
                {
                    return CallContext.ReadValue(entry.Key, (byte*)ptr).ToString();
                }
            }

            return null;
        }

    }
}
