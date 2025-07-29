using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Menus
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Menus", "Menus", CallKind.ClassFunction);
        }
        public static void Register(string id, string title, string color, string[] options, string? kind)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Menus", "Register", Internal_API.CallKind.ClassFunction, _ctx, id, title, color, (object)options, kind);
        }
        public static void RegisterTemporary(string id, string title, string color, string[] options, string? kind)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Menus", "RegisterTemporary", Internal_API.CallKind.ClassFunction, _ctx, id, title, color, (object)options, kind);
        }
        public static void UnregisterMenu(string id)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Menus", "UnregisterMenu", Internal_API.CallKind.ClassFunction, _ctx, id);
        }
    }
}