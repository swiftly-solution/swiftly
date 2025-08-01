using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Precacher
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Precacher", "Precacher", CallKind.ClassFunction);
        }
        public static void PrecacheItem(string path)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Precacher", "PrecacheItem", Internal_API.CallKind.CoreClassFunction, _ctx, path);
        }
        public static void PrecacheModel(string path)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Precacher", "PrecacheModel", Internal_API.CallKind.CoreClassFunction, _ctx, path);
        }
        public static void PrecacheSound(string path)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Precacher", "PrecacheSound", Internal_API.CallKind.CoreClassFunction, _ctx, path);
        }
    }
}