using SwiftlyS2.API.Scripting;
using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Events
{
    static class Listener
    {
        private static unsafe EventResult CallEventHandlers(List<Scripting.EventHandler> events, Scripting.Events.Event ev, IntPtr[] args)
        {
            for (int i = 0; i < events.Count; i++)
            {
                Scripting.EventHandler eventInfo = events[i];

                var functionParams = eventInfo.Callback.Method.GetParameters();
                List<object> a = [ev];
                for(int j = 0; j < args.Length; j++)
                {
                    if (functionParams.Length == j + 1) break;
                    a.Add(Internal_API.CallContext.ReadValue(functionParams[j+1].ParameterType, (byte*)args[j]));
                } 

                object returnValue = eventInfo.Callback.DynamicInvoke(a.Take(functionParams.Length).ToArray()) ?? EventResult.Continue;
                if (!returnValue.GetType().IsEnum) returnValue = EventResult.Continue;

                if ((EventResult)returnValue != EventResult.Continue) return (EventResult)returnValue;
            }

            return EventResult.Continue;
        }

        public static unsafe void StartListening()
        {
            FunctionCallers.AddFunctionCaller("AddGlobalEvents", (ctx) =>
            {
                IntPtr eventObject = ctx.GetArgument<IntPtr>(0);
                string eventName = ctx.GetArgument<string>(1);
                IntPtr[] arguments = ctx.GetArgument<IntPtr[]>(2);

                List<Scripting.EventHandler> callbacks = Scripting.Events.GetEventCallbacks(eventName);
                if (callbacks.Count == 0)
                {
                    ctx.SetReturn(EventResult.Continue);
                    return;
                }

                ctx.SetReturn(CallEventHandlers(callbacks, new Scripting.Events.Event(eventObject), arguments));
            });
        }
    }
}
