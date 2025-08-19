using System.Text.Json;
using SwiftlyS2.API;
using SwiftlyS2.API.Scripting;

namespace SwiftlyS2.Internal_API
{
    static class EventsListener
    {
        private static unsafe EventResult CallEventHandlers(ref List<API.Scripting.EventHandler> events, API.Scripting.Events.Event ev, ref nint[] args)
        {
            for (int i = 0; i < events.Count; i++)
            {
                API.Scripting.EventHandler eventInfo = events[i];

                var functionParams = eventInfo.Parameters;

                object returnValue;
                if (functionParams.Length == 0)
                {
                    returnValue = eventInfo.Callback(eventInfo.TargetInstance, []) ?? EventResult.Continue;
                }
                else
                {
                    List<object> a = [ev];
                    for (int j = 0; j < args.Length; j++)
                    {
                        if (functionParams.Length == j + 1) break;
                        Type t = functionParams[j + 1].ParameterType;
                        byte* arg = (byte*)args[j];
                        byte* marg = (byte*)&arg;
                        a.Add(CallContext.ReadValue(ref t, ref marg));
                    }
                    returnValue = eventInfo.Callback(eventInfo.TargetInstance, a.ToArray()) ?? EventResult.Continue;
                }

                if (!returnValue.GetType().IsEnum) returnValue = EventResult.Continue;

                if ((EventResult)returnValue != EventResult.Continue) return (EventResult)returnValue;
            }

            return EventResult.Continue;
        }

        private static EventResult CallEventHandlersJSON(ref List<API.Scripting.EventHandler> events, API.Scripting.Events.Event ev, ref object[] args)
        {
            for (int i = 0; i < events.Count; i++)
            {
                API.Scripting.EventHandler eventInfo = events[i];

                var functionParams = eventInfo.Parameters;
                List<object> a = [ev];
                a.AddRange(args.Take(functionParams.Length));

                object returnValue = eventInfo.Callback(eventInfo.TargetInstance, a.ToArray()) ?? EventResult.Continue;
                if (!returnValue.GetType().IsEnum) returnValue = EventResult.Continue;

                if ((EventResult)returnValue != EventResult.Continue) return (EventResult)returnValue;
            }

            return EventResult.Continue;
        }

        public static unsafe void StartListening()
        {
            FunctionCallers.AddFunctionCaller(Plugin.PluginContext, "AddGlobalEvents", (ctx) =>
            {
                nint eventObject = ctx.GetArgument<nint>(0);
                string eventName = ctx.GetArgument<string>(1);
                nint[] arguments = ctx.GetArgument<nint[]>(2);

                List<API.Scripting.EventHandler> callbacks = API.Scripting.Events.GetEventCallbacks(eventName);
                if (callbacks.Count == 0)
                {
                    ctx.SetReturn(EventResult.Continue);
                    return;
                }

                ctx.SetReturn(CallEventHandlers(ref callbacks, new API.Scripting.Events.Event(eventObject), ref arguments));
            });

            FunctionCallers.AddFunctionCaller(Plugin.PluginContext, "AddGlobalEventsJSON", (ctx) =>
            {
                nint eventObject = ctx.GetArgument<nint>(0);
                string eventName = ctx.GetArgument<string>(1);
                string arguments = ctx.GetArgument<string>(2);
                object[] parsedArgs = JsonSerializer.Deserialize<object[]>(arguments) ?? [];

                List<API.Scripting.EventHandler> callbacks = API.Scripting.Events.GetEventCallbacks(eventName);
                if (callbacks.Count == 0)
                {
                    ctx.SetReturn(EventResult.Continue);
                    return;
                }

                ctx.SetReturn(CallEventHandlersJSON(ref callbacks, new API.Scripting.Events.Event(eventObject), ref parsedArgs));
            });

            Invoker.CallNative("_G", "AddGlobalEvents", CallKind.Function, "AddGlobalEvents");
            Invoker.CallNative("_G", "AddGlobalEventsJSON", CallKind.Function, "AddGlobalEventsJSON");
        }
    }
}
