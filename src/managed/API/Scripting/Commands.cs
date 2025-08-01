using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class Commands
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Commands", "Commands", CallKind.ClassFunction);
        }
        public static string[] GetAllCommands()
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<string[]>("Commands", "GetAllCommands", Internal_API.CallKind.CoreClassFunction, _ctx) ?? [];
        }
        public static string[] GetCommands()
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<string[]>("Commands", "GetCommands", Internal_API.CallKind.CoreClassFunction, _ctx) ?? [];
        }
        public static void Register(string command_name, Action<int,string[],int,bool,string> callback)
        {
            InitializeContext();

            string id = Guid.NewGuid().ToString();

            FunctionCallers.AddFunctionCaller(Plugin.PluginContext, id, (CallContext ctx) =>
            {
                int playerid = ctx.GetArgument<int>(0);
                string[] args = ctx.GetArgument<string[]>(1);
                int argsCount = ctx.GetArgument<int>(2);
                bool silent = ctx.GetArgument<bool>(3);
                string prefix = ctx.GetArgument<string>(4);

                callback(playerid, args, argsCount, silent, prefix);
            });

            Internal_API.Invoker.CallNative("Commands", "Register", Internal_API.CallKind.CoreClassFunction, _ctx, command_name, id);
        }
        public static void RegisterAlias(string command_name, string alias)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Commands", "RegisterAlias", Internal_API.CallKind.CoreClassFunction, _ctx, command_name, alias);
        }
        public static void RegisterRawAlias(string command_name, string alias)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Commands", "RegisterRawAlias", Internal_API.CallKind.CoreClassFunction, _ctx, command_name, alias);
        }
        public static void Unregister(string command_name)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Commands", "Unregister", Internal_API.CallKind.CoreClassFunction, _ctx, command_name);
        }
        public static void UnregisterAlias(string alias)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("Commands", "UnregisterAlias", Internal_API.CallKind.CoreClassFunction, _ctx, alias);
        }
    }
}