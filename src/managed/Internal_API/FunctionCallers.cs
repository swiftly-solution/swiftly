using SwiftlyS2.API;

namespace SwiftlyS2.Internal_API
{
    class FunctionCallers
    {
        private static Dictionary<IntPtr, Dictionary<string, Action<CallContext>>> functionCallers = [];

        public static void AddFunctionCaller(IntPtr ctx, string function, Action<CallContext> caller)
        {
            if (!functionCallers.ContainsKey(ctx)) functionCallers.Add(ctx, []);
            functionCallers[ctx].Add(function, caller);
        }

        public static Action<CallContext> GetActionCaller(IntPtr ctx, string function)
        {
            return functionCallers[ctx][function];
        }

        public static void RemoveFunctionCaller(IntPtr ctx, string function)
        {
            if (!functionCallers.ContainsKey(ctx)) return;
            if (!functionCallers[ctx].ContainsKey(function)) return;

            functionCallers[ctx].Remove(function);
        }
    }
}
