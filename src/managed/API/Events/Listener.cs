using SwiftlyS2.API.Scripting;
using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Events
{
    static class Listener
    {
        private static EventResult CallEventHandlers(List<Scripting.EventHandler> events, object[] args)
        {
            for (int i = 0; i < events.Count; i++)
            {
                Scripting.EventHandler eventInfo = events[i];
                object returnValue = eventInfo.Callback.DynamicInvoke(args) ?? EventResult.Continue;
                if (!returnValue.GetType().IsEnum) returnValue = EventResult.Continue;

                if ((EventResult)returnValue != EventResult.Continue) return (EventResult)returnValue;
            }

            return EventResult.Continue;
        }

        public static void StartListening()
        {
            FunctionCallers.AddFunctionCaller("AddGlobalEvents", (ctx) =>
            {
                IntPtr eventObject = ctx.GetArgument<IntPtr>(0);
                string eventName = ctx.GetArgument<string>(1); 

                List<Scripting.EventHandler> callbacks = Scripting.Events.GetEventCallbacks(eventName);
                if (callbacks.Count == 0)
                {
                    ctx.SetReturn(EventResult.Continue);
                    return;
                }

                ctx.SetReturn(CallEventHandlers(callbacks, []));
            });
        }
    }
}
