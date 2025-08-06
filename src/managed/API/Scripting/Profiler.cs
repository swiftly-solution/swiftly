using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Profiler
    {
        private static IntPtr _ctx = IntPtr.Zero;

        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Profiler", "Profiler", CallKind.ClassFunction);
        }
        public static void Start(string name)
        {
            InitializeContext();
            Invoker.CallNative("Profiler", "Start", CallKind.CoreClassFunction, _ctx, name);
        }
        public static void Stop(string name)
        {
            InitializeContext();
            Invoker.CallNative("Profiler", "Stop", CallKind.CoreClassFunction, _ctx, name);
        }
    }
}
