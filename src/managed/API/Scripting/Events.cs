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

        public class Event : ClassData
        {
            public Event(string event_name) : base(Internal_API.Invoker.CallNative<IntPtr>("Event", "Event", CallKind.ClassFunction, event_name))
            {
            }
            public string GetInvokingPlugin()
            {
                return Internal_API.Invoker.CallNative<string>("Event", "GetInvokingPlugin", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
            }
            public bool IsGameEvent()
            {
                return Internal_API.Invoker.CallNative<bool>("Event", "IsGameEvent", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public bool IsHook()
            {
                return Internal_API.Invoker.CallNative<bool>("Event", "IsHook", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void SetBool(string key, bool value)
            {
                Internal_API.Invoker.CallNative("Event", "SetBool", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetInt(string key, int value)
            {
                Internal_API.Invoker.CallNative("Event", "SetInt", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetUint64(string key, ulong value)
            {
                Internal_API.Invoker.CallNative("Event", "SetUint64", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetFloat(string key, float value)
            {
                Internal_API.Invoker.CallNative("Event", "SetFloat", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public void SetString(string key, string value)
            {
                Internal_API.Invoker.CallNative("Event", "SetString", Internal_API.CallKind.ClassFunction, m_classData, key, value);
            }
            public bool GetBool(string key)
            {
                return Internal_API.Invoker.CallNative<bool>("Event", "GetBool", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public int GetInt(string key)
            {
                return Internal_API.Invoker.CallNative<int>("Event", "GetInt", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public ulong GetUint64(string key)
            {
                return Internal_API.Invoker.CallNative<ulong>("Event", "GetUint64", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public float GetFloat(string key)
            {
                return Internal_API.Invoker.CallNative<float>("Event", "GetFloat", Internal_API.CallKind.ClassFunction, m_classData, key);
            }
            public string GetString(string key)
            {
                return Internal_API.Invoker.CallNative<string>("Event", "GetString", Internal_API.CallKind.ClassFunction, m_classData, key) ?? "";
            }
            public object GetReturn()
            {
                return Internal_API.Invoker.CallNative<object>("Event", "GetReturn", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void SetReturn(object value)
            {
                Internal_API.Invoker.CallNative("Event", "SetReturn", Internal_API.CallKind.ClassFunction, m_classData, value);
            }
            public void FireEvent(bool dont_broadcast)
            {
                Internal_API.Invoker.CallNative("Event", "FireEvent", Internal_API.CallKind.ClassFunction, m_classData, dont_broadcast);
            }
            public void FireEventToClient(int playerid)
            {
                Internal_API.Invoker.CallNative("Event", "FireEventToClient", Internal_API.CallKind.ClassFunction, m_classData, playerid);
            }
            public void SetHookBoolean(uint index, bool value)
            {
                Internal_API.Invoker.CallNative("Event", "SetHookBoolean", Internal_API.CallKind.ClassFunction, m_classData, index, value);
            }
            public void SetHookInt(uint index, int value)
            {
                Internal_API.Invoker.CallNative("Event", "SetHookInt", Internal_API.CallKind.ClassFunction, m_classData, index, value);
            }
            public void SetHookUInt(uint index, uint value)
            {
                Internal_API.Invoker.CallNative("Event", "SetHookUInt", Internal_API.CallKind.ClassFunction, m_classData, index, value);
            }
            public void SetHookUInt64(uint index, ulong value)
            {
                Internal_API.Invoker.CallNative("Event", "SetHookUInt64", Internal_API.CallKind.ClassFunction, m_classData, index, value);
            }
            public void SetHookInt64(uint index, long value)
            {
                Internal_API.Invoker.CallNative("Event", "SetHookInt64", Internal_API.CallKind.ClassFunction, m_classData, index, value);
            }
            public void SetHookFloat(uint index, float value)
            {
                Internal_API.Invoker.CallNative("Event", "SetHookFloat", Internal_API.CallKind.ClassFunction, m_classData, index, value);
            }
            public void SetHookDouble(uint index, double value)
            {
                Internal_API.Invoker.CallNative("Event", "SetHookDouble", Internal_API.CallKind.ClassFunction, m_classData, index, value);
            }
            public void SetHookString(uint index, string value)
            {
                Internal_API.Invoker.CallNative("Event", "SetHookString", Internal_API.CallKind.ClassFunction, m_classData, index, value);
            }
            public void SetHookPointer(uint index, Memory value)
            {
                Internal_API.Invoker.CallNative("Event", "SetHookPointer", Internal_API.CallKind.ClassFunction, m_classData, index, value);
            }
            public bool GetHookBoolean(uint index)
            {
                return Internal_API.Invoker.CallNative<bool>("Event", "GetHookBoolean", Internal_API.CallKind.ClassFunction, m_classData, index);
            }
            public int GetHookInt(uint index)
            {
                return Internal_API.Invoker.CallNative<int>("Event", "GetHookInt", Internal_API.CallKind.ClassFunction, m_classData, index);
            }
            public uint GetHookUInt(uint index)
            {
                return Internal_API.Invoker.CallNative<uint>("Event", "GetHookUInt", Internal_API.CallKind.ClassFunction, m_classData, index);
            }
            public long GetHookInt64(uint index)
            {
                return Internal_API.Invoker.CallNative<long>("Event", "GetHookInt64", Internal_API.CallKind.ClassFunction, m_classData, index);
            }
            public ulong GetHookUInt64(uint index)
            {
                return Internal_API.Invoker.CallNative<ulong>("Event", "GetHookUInt64", Internal_API.CallKind.ClassFunction, m_classData, index);
            }
            public float GetHookFloat(uint index)
            {
                return Internal_API.Invoker.CallNative<float>("Event", "GetHookFloat", Internal_API.CallKind.ClassFunction, m_classData, index);
            }
            public double GetHookDouble(uint index)
            {
                return Internal_API.Invoker.CallNative<double>("Event", "GetHookDouble", Internal_API.CallKind.ClassFunction, m_classData, index);
            }
            public string GetHookString(uint index)
            {
                return Internal_API.Invoker.CallNative<string>("Event", "GetHookString", Internal_API.CallKind.ClassFunction, m_classData, index) ?? "";
            }
            public Memory GetHookPointer(uint index)
            {
                return Internal_API.Invoker.CallNative<Memory>("Event", "GetHookPointer", Internal_API.CallKind.ClassFunction, m_classData, index) ?? new();
            }
            public object GetHookReturn()
            {
                return Internal_API.Invoker.CallNative<object>("Event", "GetHookReturn", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void SetHookReturn(object value)
            {
                Internal_API.Invoker.CallNative("Event", "SetHookReturn", Internal_API.CallKind.ClassFunction, m_classData, value);
            }
            public bool GetNoBroadcast()
            {
                return Internal_API.Invoker.CallNative<bool>("Event", "GetNoBroadcast", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void SetNoBroadcast(bool value)
            {
                Internal_API.Invoker.CallNative("Event", "SetNoBroadcast", Internal_API.CallKind.ClassFunction, m_classData, value);
            }
        }
    }
}
