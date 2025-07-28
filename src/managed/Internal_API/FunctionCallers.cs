using SwiftlyS2.API;

namespace SwiftlyS2.Internal_API
{
    class FunctionCallers
    {
        private static Dictionary<IntPtr, Dictionary<string, Action<CallContext>>> functionCallers = [];

        public static void AddFunctionCaller(string function, Action<CallContext> caller)
        {
            if (!functionCallers.ContainsKey(Plugin.PluginContext)) functionCallers.Add(Plugin.PluginContext, []);
            functionCallers[Plugin.PluginContext].Add(function, caller);

            Invoker.CallNative("_G", function, CallKind.Function, function);
        }

        public static Action<CallContext> GetActionCaller(IntPtr ctx, string function)
        {
            return functionCallers[ctx][function];
        }
    }
}
