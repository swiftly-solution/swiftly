using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Configuration
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Configuration", "Configuration", CallKind.ClassFunction);
        }
        public static void Create(string configuration_key, Dictionary<string, object> value)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Configuration", "Create", Internal_API.CallKind.CoreClassFunction, _ctx, configuration_key, value);
        }
        public static bool Exists(string key)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<bool>("Configuration", "Exists", Internal_API.CallKind.CoreClassFunction, _ctx, key);
        }
        public static T? Fetch<T>(string key)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<T>("Configuration", "Fetch", Internal_API.CallKind.CoreClassFunction, _ctx, key);
        }
        public static int FetchArraySize(string key)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<int>("Configuration", "FetchArraySize", Internal_API.CallKind.CoreClassFunction, _ctx, key);
        }
        public static void Reload(string key)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Configuration", "Reload", Internal_API.CallKind.CoreClassFunction, _ctx, key);
        }
    }
}