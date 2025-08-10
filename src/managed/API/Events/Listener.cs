using System.Text.Json;
using SwiftlyS2.API.Scripting;
using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Events
{
    static class Listener
    {
        private static unsafe EventResult CallEventHandlers(ref List<Scripting.EventHandler> events, Scripting.Events.Event ev, ref IntPtr[] args)
        {
            for (int i = 0; i < events.Count; i++)
            {
                Scripting.EventHandler eventInfo = events[i];

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
                        if(Cacher.ConsiderTypeAPointer(ref t))
                        {
                            byte* marg = (byte*)&arg;
                            a.Add(Internal_API.CallContext.ReadValue(ref t, ref marg));
                        }
                        else
                        {
                            a.Add(Internal_API.CallContext.ReadValue(ref t, ref arg));
                        }
                    }
                    returnValue = eventInfo.Callback(eventInfo.TargetInstance, a.ToArray()) ?? EventResult.Continue;
                }

                if (!returnValue.GetType().IsEnum) returnValue = EventResult.Continue;

                if ((EventResult)returnValue != EventResult.Continue) return (EventResult)returnValue;
            }

            return EventResult.Continue;
        }

        private static EventResult CallEventHandlersJSON(ref List<Scripting.EventHandler> events, Scripting.Events.Event ev, ref object[] args)
        {
            for (int i = 0; i < events.Count; i++)
            {
                Scripting.EventHandler eventInfo = events[i];

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
                IntPtr eventObject = ctx.GetArgument<IntPtr>(0);
                string eventName = ctx.GetArgument<string>(1);
                IntPtr[] arguments = ctx.GetArgument<IntPtr[]>(2);

                List<Scripting.EventHandler> callbacks = Scripting.Events.GetEventCallbacks(eventName);
                if (callbacks.Count == 0)
                {
                    ctx.SetReturn(EventResult.Continue);
                    return;
                }

                ctx.SetReturn(CallEventHandlers(ref callbacks, new Scripting.Events.Event(eventObject), ref arguments));
            });

            FunctionCallers.AddFunctionCaller(Plugin.PluginContext, "AddGlobalEventsJSON", (ctx) =>
            {
                IntPtr eventObject = ctx.GetArgument<IntPtr>(0);
                string eventName = ctx.GetArgument<string>(1);
                string arguments = ctx.GetArgument<string>(2);
                object[] parsedArgs = JsonSerializer.Deserialize<object[]>(arguments) ?? [];

                List<Scripting.EventHandler> callbacks = Scripting.Events.GetEventCallbacks(eventName);
                if (callbacks.Count == 0)
                {
                    ctx.SetReturn(EventResult.Continue);
                    return;
                }

                ctx.SetReturn(CallEventHandlersJSON(ref callbacks, new Scripting.Events.Event(eventObject), ref parsedArgs));
            });

            Invoker.CallNative("_G", "AddGlobalEvents", CallKind.Function, "AddGlobalEvents");
            Invoker.CallNative("_G", "AddGlobalEventsJSON", CallKind.Function, "AddGlobalEventsJSON");
        }
    }
}
