using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Logs
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Logs", "Logs", CallKind.ClassFunction);
        }
        public static void Write(LogType_t log_type, string text)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Logs", "Write", Internal_API.CallKind.CoreClassFunction, _ctx, log_type, text);
        }
    }
}