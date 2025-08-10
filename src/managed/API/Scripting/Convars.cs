using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Convars
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Convars", "Convars", CallKind.ClassFunction);
        }
        public static void AddFlags(string name, long flags)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Convars", "AddFlags", Internal_API.CallKind.CoreClassFunction, _ctx, name, flags);
        }
        public static void Create(string name, string description, EConVarType cvar_type, long flags, object? default_value, object? min_value, object? max_value)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Convars", "Create", Internal_API.CallKind.CoreClassFunction, _ctx, name, description, cvar_type, flags, default_value, min_value, max_value);
        }
        public static void CreateFake(string name, EConVarType cvar_type, object default_value, bool? prot)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Convars", "CreateFake", Internal_API.CallKind.CoreClassFunction, _ctx, name, cvar_type, default_value, prot);
        }
        public static void Delete(string name)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Convars", "Delete", Internal_API.CallKind.CoreClassFunction, _ctx, name);
        }
        public static void DeleteFake(string name)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Convars", "DeleteFake", Internal_API.CallKind.CoreClassFunction, _ctx, name);
        }
        public static bool Exists(string name)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<bool>("Convars", "Exists", Internal_API.CallKind.CoreClassFunction, _ctx, name);
        }
        public static bool ExistsFake(string name)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<bool>("Convars", "ExistsFake", Internal_API.CallKind.CoreClassFunction, _ctx, name);
        }
        public static T? Get<T>(string name)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<T>("Convars", "Get", Internal_API.CallKind.CoreClassFunction, _ctx, name);
        }
        public static long GetFlags(string name)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<long>("Convars", "GetFlags", Internal_API.CallKind.CoreClassFunction, _ctx, name);
        }
        public static EConVarType GetType(string name)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<EConVarType>("Convars", "GetType", Internal_API.CallKind.CoreClassFunction, _ctx, name);
        }
        public static bool HasFlags(string name, long flags)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<bool>("Convars", "HasFlags", Internal_API.CallKind.CoreClassFunction, _ctx, name, flags);
        }
        public static void RemoveFlags(string name, long flags)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Convars", "RemoveFlags", Internal_API.CallKind.CoreClassFunction, _ctx, name, flags);
        }
        public static void Set(string name, string value)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Convars", "Set", Internal_API.CallKind.CoreClassFunction, _ctx, name, value);
        }
    }
}