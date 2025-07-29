using SwiftlyS2.Internal_API;
using static SwiftlyS2.API.Scripting.UserMessages;

namespace SwiftlyS2.API.Scripting
{
    public class Generic
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Generic", "Generic", CallKind.ClassFunction);
        }
        public static void ReplyToCommand(int playerid, string prefix, string text)
        {
            Internal_API.Invoker.CallNative("_G", "ReplyToCommand", Internal_API.CallKind.Function, playerid, prefix, text);
        }
        public static HookHandle AddHookEntityOutput(string class_name, string output)
        {
            return Internal_API.Invoker.CallNative<HookHandle>("_G", "AddHookEntityOutput", Internal_API.CallKind.Function, class_name, output);
        }
        public static CEntityInstance CreateEntityByName(string class_name)
        {
            return Internal_API.Invoker.CallNative<CEntityInstance>("_G", "CreateEntityByName", Internal_API.CallKind.Function, class_name);
        }
        public static CEntityInstance[] FindEntitiesByClassname(string class_name)
        {
            return Internal_API.Invoker.CallNative<CEntityInstance[]>("_G", "FindEntitiesByClassname", Internal_API.CallKind.Function, class_name);
        }
        public static EventHandler AddEventHandler(string event_name, Func<Event,object, EventResult?> callback)
        {
            return Internal_API.Invoker.CallNative<EventHandler>("_G", "AddEventHandler", Internal_API.CallKind.Function, event_name, callback);
        }
        public static void RemoveEventHandler(EventHandler handler)
        {
            Internal_API.Invoker.CallNative("_G", "RemoveEventHandler", Internal_API.CallKind.Function, handler);
        }
        public static (EventResult, Event) TriggerEvent(string event_name, params object[] args)
        {
            return Internal_API.Invoker.CallNative<(EventResult, Event)>("_G", "TriggerEvent", Internal_API.CallKind.Function, event_name, (object)args);
        }
        public static string CreateTextTable(string[] data)
        {
            return Internal_API.Invoker.CallNative<string>("_G", "CreateTextTable", Internal_API.CallKind.Function, (object)data);
        }
        public static string GetCurrentPluginName()
        {
            return Internal_API.Invoker.CallNative<string>("_G", "GetCurrentPluginName", Internal_API.CallKind.Function);
        }
        public static string GetGameName()
        {
            return Internal_API.Invoker.CallNative<string>("_G", "GetGameName", Internal_API.CallKind.Function);
        }
        public static string GetPluginPath(string plugin_name)
        {
            return Internal_API.Invoker.CallNative<string>("_G", "GetPluginPath", Internal_API.CallKind.Function, plugin_name);
        }
        public static PluginState_t GetPluginState(string plugin_name)
        {
            return Internal_API.Invoker.CallNative<PluginState_t>("_G", "GetPluginState", Internal_API.CallKind.Function, plugin_name);
        }
        public static HookHandle AddHook(Memory memory, string args_list, string return_type)
        {
            return Internal_API.Invoker.CallNative<HookHandle>("_G", "AddHook", Internal_API.CallKind.Function, memory, args_list, return_type);
        }
        public static EventHandler AddPostHookListener(HookHandle hook_handle, Func<Event, EventResult?> callback)
        {
            return Internal_API.Invoker.CallNative<EventHandler>("_G", "AddPostHookListener", Internal_API.CallKind.Function, hook_handle, callback);
        }
        public static EventHandler AddPreHookListener(HookHandle hook_handle, Func<Event, EventResult?> callback)
        {
            return Internal_API.Invoker.CallNative<EventHandler>("_G", "AddPreHookListener", Internal_API.CallKind.Function, hook_handle, callback);
        }
        public static HookHandle AddHook(string library, string vtable_name, string offset, string args_list, string return_type)
        {
            return Internal_API.Invoker.CallNative<HookHandle>("_G", "AddHook", Internal_API.CallKind.Function, library, vtable_name, offset, args_list, return_type);
        }
        public static object CallHook(HookHandle hook_handle, params object[] args)
        {
            return Internal_API.Invoker.CallNative<object>("_G", "CallHook", Internal_API.CallKind.Function, hook_handle, (object)args);
        }
        public static void NextTick(Action callback)
        {
            Internal_API.Invoker.CallNative("_G", "NextTick", Internal_API.CallKind.Function, callback);
        }
        public static void SetTimeout(long delay, Action callback)
        {
            Internal_API.Invoker.CallNative("_G", "SetTimeout", Internal_API.CallKind.Function, delay, callback);
        }
        public static TimerHandle SetTimer(long delay, Action callback)
        {
            return Internal_API.Invoker.CallNative<TimerHandle>("_G", "SetTimer", Internal_API.CallKind.Function, delay, callback) ?? new();
        }
        public static void StopTimer(TimerHandle timerid)
        {
            Internal_API.Invoker.CallNative("_G", "StopTimer", Internal_API.CallKind.Function, timerid);
        }
        public static string FetchTranslation(string key, int? playerid)
        {
            return Internal_API.Invoker.CallNative<string>("_G", "FetchTranslation", Internal_API.CallKind.Function, key, playerid) ?? "";
        }
        public static string ComputePrettyTime(ulong seconds)
        {
            return Internal_API.Invoker.CallNative<string>("_G", "ComputePrettyTime", Internal_API.CallKind.Function, seconds);
        }
        public static CCSGameRules GetCCSGameRules()
        {
            return Internal_API.Invoker.CallNative<CCSGameRules>("_G", "GetCCSGameRules", Internal_API.CallKind.Function);
        }
        public static Dictionary<string, string>[] GetPluginsList()
        {
            return Internal_API.Invoker.CallNative<Dictionary<string, string>[]>("_G", "GetPluginsList", Internal_API.CallKind.Function);
        }
        public static UserMessage GetUserMessage(UserMessage uuid)
        {
            return Internal_API.Invoker.CallNative<UserMessage>("_G", "GetUserMessage", Internal_API.CallKind.Function, uuid) ?? new("");
        }
        public static bool IsValidItem(string name)
        {
            return Internal_API.Invoker.CallNative<bool>("_G", "IsValidItem", Internal_API.CallKind.Function, name);
        }
        public static bool IsValidWeapon(string name)
        {
            return Internal_API.Invoker.CallNative<bool>("_G", "IsValidWeapon", Internal_API.CallKind.Function, name);
        }
        public static void StateUpdate(SDKClass entity, string classname, string field)
        {
            Internal_API.Invoker.CallNative("_G", "StateUpdate", Internal_API.CallKind.Function, entity, classname, field);
        }
        public static string uuid()
        {
            return Internal_API.Invoker.CallNative<string>("_G", "uuid", Internal_API.CallKind.Function) ?? "";
        }
        public static string GetOS()
        {
            return Internal_API.Invoker.CallNative<string>("_G", "GetOS", Internal_API.CallKind.Function) ?? "";
        }
        public static bool IsLinux()
        {
            return Internal_API.Invoker.CallNative<bool>("_G", "IsLinux", Internal_API.CallKind.Function);
        }
        public static bool IsWindows()
        {
            return Internal_API.Invoker.CallNative<bool>("_G", "IsWindows", Internal_API.CallKind.Function);
        }
        public static Player[] FindPlayersByTarget(string target, bool matchbots)
        {
            return Internal_API.Invoker.CallNative<Player[]>("_G", "FindPlayersByTarget", Internal_API.CallKind.Function, target, matchbots);
        }
        public static Player? GetPlayer(int playerid)
        {
            return Internal_API.Invoker.CallNative<Player?>("_G", "GetPlayer", Internal_API.CallKind.Function, playerid);
        }
        public static ulong GetTime()
        {
            return Internal_API.Invoker.CallNative<ulong>("_G", "GetTime", Internal_API.CallKind.Function);
        }
    }
}