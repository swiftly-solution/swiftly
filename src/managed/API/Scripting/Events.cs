using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public struct EventHandler
    {
        public int Key;
        public string EventName;
        public Delegate Callback;
    }

    public class Events
    {
        private static int eventRegistryIndex = 50;
        private static Dictionary<string, List<EventHandler>> eventCallbacks = [];
        
        public static EventHandler AddEventHandler(string event_name, Delegate callback)
        {
            EventHandler info = new()
            {
                EventName = event_name,
                Callback = callback,
                Key = eventRegistryIndex++
            };

            if (!eventCallbacks.ContainsKey(event_name))
            {
                eventCallbacks.Add(event_name, [info]);
            }
            else
            {
                eventCallbacks[event_name].Append(info);
            }
            Invoker.CallNative("_G", "RegisterEventHandlerPlugin", CallKind.Function, event_name);

            return info;
        }

        public static void RemoveEventHandler(EventHandler info)
        {
            if (!eventCallbacks.ContainsKey(info.EventName)) return;

            for (int i = 0; i < eventCallbacks[info.EventName].Count; i++)
            {
                if (eventCallbacks[info.EventName][i].Key == info.Key)
                {
                    eventCallbacks[info.EventName].RemoveAt(i);
                    break;
                }
            }

            if(eventCallbacks[info.EventName].Count == 0)
            {
                Invoker.CallNative("_G", "RemoveEventHandlerPlugin", CallKind.Function, info.EventName);
            }
        }

        public static List<EventHandler> GetEventCallbacks(string event_name)
        {
            if (!eventCallbacks.TryGetValue(event_name, out List<EventHandler>? value)) return [];
            else return value!;
        }
    }
}
