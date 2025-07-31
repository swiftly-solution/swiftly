using SwiftlyS2.Internal_API;
using static SwiftlyS2.API.SDK.CS2.Classes;

namespace SwiftlyS2.API.Scripting
{
    public class Player: ClassData
    {
        public CBaseEntity CBaseEntity()
        {
            
            return Internal_API.Invoker.CallNative<CBaseEntity>("Player", "CBaseEntity", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public CBasePlayerController CBasePlayerController()
        {
            
            return Internal_API.Invoker.CallNative<CBasePlayerController>("Player", "CBasePlayerController", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public CBasePlayerPawn CBasePlayerPawn()
        {
            
            return Internal_API.Invoker.CallNative<CBasePlayerPawn>("Player", "CBasePlayerPawn", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public CCSPlayerController CCSPlayerController()
        {
            
            return Internal_API.Invoker.CallNative<CCSPlayerController>("Player", "CCSPlayerController", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public CCSPlayerPawn CCSPlayerPawn()
        {
            
            return Internal_API.Invoker.CallNative<CCSPlayerPawn>("Player", "CCSPlayerPawn", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public CCSPlayerPawnBase CCSPlayerPawnBase()
        {
            
            return Internal_API.Invoker.CallNative<CCSPlayerPawnBase>("Player", "CCSPlayerPawnBase", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public void ChangeTeam(Team team)
        {
            
            Internal_API.Invoker.CallNative("Player", "ChangeTeam", Internal_API.CallKind.ClassFunction, m_classData, team);
        }
        public void Drop(DisconnectReason reason, string? msg)
        {
            
            Internal_API.Invoker.CallNative("Player", "Drop", Internal_API.CallKind.ClassFunction, m_classData, reason, msg);
        }
        public void ExecuteCommand(string command)
        {
            
            Internal_API.Invoker.CallNative("Player", "ExecuteCommand", Internal_API.CallKind.ClassFunction, m_classData, command);
        }
        public string GetChatColor()
        {
            
            return Internal_API.Invoker.CallNative<string>("Player", "GetChatColor", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
        }
        public string GetChatTag()
        {
            
            return Internal_API.Invoker.CallNative<string>("Player", "GetChatTag", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
        }
        public string GetChatTagColor()
        {
            
            return Internal_API.Invoker.CallNative<string>("Player", "GetChatTagColor", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
        }
        public ulong GetConnectedTime()
        {
            
            return Internal_API.Invoker.CallNative<ulong>("Player", "GetConnectedTime", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public string GetConvar(string convar)
        {
            
            return Internal_API.Invoker.CallNative<string>("Player", "GetConvar", Internal_API.CallKind.ClassFunction, m_classData, convar) ?? "";
        }
        public string GetIPAddress()
        {
            
            return Internal_API.Invoker.CallNative<string>("Player", "GetIPAddress", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
        }
        public ListenOverride GetListening(int id)
        {
            
            return Internal_API.Invoker.CallNative<ListenOverride>("Player", "GetListening", Internal_API.CallKind.ClassFunction, m_classData, id);
        }
        public string GetNameColor()
        {
            
            return Internal_API.Invoker.CallNative<string>("Player", "GetNameColor", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
        }
        public int GetSlot()
        {
            
            return Internal_API.Invoker.CallNative<int>("Player", "GetSlot", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public ulong GetSteamID()
        {
            
            return Internal_API.Invoker.CallNative<ulong>("Player", "GetSteamID", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public string GetSteamID2()
        {
            
            return Internal_API.Invoker.CallNative<string>("Player", "GetSteamID2", Internal_API.CallKind.ClassFunction, m_classData) ?? "";
        }
        public T? GetVar<T>(string key)
        {
            return Internal_API.Invoker.CallNative<T>("Player", "GetVar", Internal_API.CallKind.ClassFunction, m_classData, key);
        }
        public ulong GetVoiceFlags()
        {
            
            return Internal_API.Invoker.CallNative<ulong>("Player", "GetVoiceFlags", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public WeaponManager GetWeaponManager()
        {
            
            return Internal_API.Invoker.CallNative<WeaponManager>("Player", "GetWeaponManager", Internal_API.CallKind.ClassFunction, m_classData) ?? new();
        }
        public void HideMenu()
        {
            
            Internal_API.Invoker.CallNative("Player", "HideMenu", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public bool IsFakeClient()
        {
            
            return Internal_API.Invoker.CallNative<bool>("Player", "IsFakeClient", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public bool IsFirstSpawn()
        {
            
            return Internal_API.Invoker.CallNative<bool>("Player", "IsFirstSpawn", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public bool IsValid()
        {
            
            return Internal_API.Invoker.CallNative<bool>("Player", "IsValid", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public void Kill()
        {
            
            Internal_API.Invoker.CallNative("Player", "Kill", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public void PerformMenuAction(string action, int value)
        {
            
            Internal_API.Invoker.CallNative("Player", "PerformMenuAction", Internal_API.CallKind.ClassFunction, m_classData, action, value);
        }
        public void QueryConvar(string convar_name)
        {
            
            Internal_API.Invoker.CallNative("Player", "QueryConvar", Internal_API.CallKind.ClassFunction, m_classData, convar_name);
        }
        public void Respawn()
        {
            
            Internal_API.Invoker.CallNative("Player", "Respawn", Internal_API.CallKind.ClassFunction, m_classData);
        }
        public void SendMsg(MessageType msgType, string text)
        {
            
            Internal_API.Invoker.CallNative("Player", "SendMsg", Internal_API.CallKind.ClassFunction, m_classData, msgType, text);
        }
        public void SetChatColor(string color)
        {
            
            Internal_API.Invoker.CallNative("Player", "SetChatColor", Internal_API.CallKind.ClassFunction, m_classData, color);
        }
        public void SetChatTag(string tag)
        {
            
            Internal_API.Invoker.CallNative("Player", "SetChatTag", Internal_API.CallKind.ClassFunction, m_classData, tag);
        }
        public void SetChatTagColor(string color)
        {
            
            Internal_API.Invoker.CallNative("Player", "SetChatTagColor", Internal_API.CallKind.ClassFunction, m_classData, color);
        }
        public void SetConvar(string convar, string value)
        {
            
            Internal_API.Invoker.CallNative("Player", "SetConvar", Internal_API.CallKind.ClassFunction, m_classData, convar, value);
        }
        public void SetListening(int id, ListenOverride over)
        {
            
            Internal_API.Invoker.CallNative("Player", "SetListening", Internal_API.CallKind.ClassFunction, m_classData, id, over);
        }
        public void SetNameColor(string color)
        {
            
            Internal_API.Invoker.CallNative("Player", "SetNameColor", Internal_API.CallKind.ClassFunction, m_classData, color);
        }
        public void SetVar(string key, object value)
        {
            
            Internal_API.Invoker.CallNative("Player", "SetVar", Internal_API.CallKind.ClassFunction, m_classData, key, value);
        }
        public void SetVoiceFlags(ulong flags)
        {
            
            Internal_API.Invoker.CallNative("Player", "SetVoiceFlags", Internal_API.CallKind.ClassFunction, m_classData, flags);
        }
        public void ShowMenu(string menuid)
        {
            
            Internal_API.Invoker.CallNative("Player", "ShowMenu", Internal_API.CallKind.ClassFunction, m_classData, menuid);
        }
        public void SwitchTeam(Team team)
        {
            
            Internal_API.Invoker.CallNative("Player", "SwitchTeam", Internal_API.CallKind.ClassFunction, m_classData, team);
        }
    }
}