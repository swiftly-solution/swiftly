using SwiftlyS2.API.SDK.CS2;
using SwiftlyS2.Internal_API;
using static SwiftlyS2.API.Scripting.UserMessages;
using static SwiftlyS2.API.SDK.CS2.Classes;

namespace SwiftlyS2.API.Scripting
{
    public class Generic
    {
        private static int _timerID = 50;
        private static List<int> _validTimerIds = [];

        public static void ReplyToCommand(int playerid, string prefix, string text)
        {
            if(playerid == -1)
            {
                Console.WriteLine(text);
            }
            else
            {
                Player? player = GetPlayer(playerid);
                if (player == null) return;
                if (player.IsFakeClient()) return;

                player.SendMsg(MessageType.Chat, $"{prefix} {text}");
            }
        }
        public static CEntityInstance CreateEntityByName(string class_name)
        {
            return Internal_API.Invoker.CallNative<CEntityInstance>("_G", "CreateEntityByName", Internal_API.CallKind.Function, class_name);
        }
        public static CEntityInstance[] FindEntitiesByClassname(string class_name)
        {
            return Internal_API.Invoker.CallNative<CEntityInstance[]>("_G", "FindEntitiesByClassname", Internal_API.CallKind.Function, class_name);
        }
        public static string CreateTextTable(string[][] data)
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
        public static void NextTick(Action callback)
        {
            SetTimeout(1, callback);
        }
        public static void SetTimeout(uint delay, Action callback)
        {
            var callbackUUID = Guid.NewGuid().ToString();

            FunctionCallers.AddFunctionCaller(Plugin.PluginContext, callbackUUID, (CallContext ctx) =>
            {
                callback();
                FunctionCallers.RemoveFunctionCaller(Plugin.PluginContext, callbackUUID);
            });

            Invoker.CallNative("_G", "AddTimeout", CallKind.Function, delay, callbackUUID);
        }
        public static TimerHandle SetTimer(uint delay, Action callback)
        {
            var currentTimerID = _timerID++;

            TimerHandle handle = new()
            {
                TimerID = currentTimerID
            };

            _validTimerIds.Add(currentTimerID);

            Action timeoutFunction = () => { };

            timeoutFunction = () =>
            {
                if (_validTimerIds.Contains(currentTimerID))
                {
                    callback();

                    if (_validTimerIds.Contains(currentTimerID))
                    {
                        SetTimeout(delay, timeoutFunction);
                    }
                }
            };

            SetTimeout(delay, timeoutFunction);

            return handle;
        }
        public static void StopTimer(TimerHandle timerid)
        {
            _validTimerIds.Remove(timerid.TimerID);
        }

        public static string FetchTranslation(string key, int? playerid)
        {
            return Internal_API.Invoker.CallNative<string>("_G", "FetchTranslation", CallKind.Function, key, playerid ?? -1) ?? "";
        }
        public static string FetchTranslation(string key)
        {
            return Internal_API.Invoker.CallNative<string>("_G", "FetchTranslation", CallKind.Function, key, -1) ?? "";
        }
        public static string ComputePrettyTime(ulong seconds)
        {
            if (seconds == 0) return FetchTranslation("core.forever");
            else if (seconds < 60) return FetchTranslation("core.seconds").Replace("{TIME}", seconds.ToString());
            else if (seconds < 3600) return FetchTranslation("core.minutes").Replace("{TIME}", MathF.Floor(seconds / 60).ToString());
            else if (seconds < 86400) return FetchTranslation("core.hours").Replace("{TIME}", MathF.Floor(seconds / 3600).ToString());
            else return FetchTranslation("core.days").Replace("{TIME}", MathF.Floor(seconds / 86400).ToString());
        }
        public static CCSGameRules GetCCSGameRules()
        {
            return Internal_API.Invoker.CallNative<CCSGameRules>("_G", "GetCCSGameRules", Internal_API.CallKind.Function);
        }
        public static Dictionary<string, string>[] GetPluginsList()
        {
            return Internal_API.Invoker.CallNative<Dictionary<string, string>[]>("_G", "GetPluginsList", Internal_API.CallKind.Function);
        }
        public static ulong RegisterCallstack(string plugin_name, string text)
        {
            return Internal_API.Invoker.CallNative<ulong>("_G", "RegisterCallstack", Internal_API.CallKind.Function, plugin_name, text);
        }
        public static void UnregisterCallstack(string plugin_name, ulong id)
        {
            Internal_API.Invoker.CallNative("_G", "UnregisterCallstack", Internal_API.CallKind.Function, plugin_name, id);
        }
        public static UserMessage GetUserMessage(UserMessage uuid)
        {
            return uuid;
        }
        public static bool IsValidItem(string name)
        {
            if (GetGameName() == "cs2")
            {
                return Utils.CS2.ItemsList.Contains(name);
            }
            else return false;
        }
        public static bool IsValidWeapon(string name)
        {
            if (GetGameName() == "cs2")
            {
                return Utils.CS2.WeaponsList.Contains(name);
            }
            else return false;
        }
        public static void StateUpdate(ClassData entity, string classname, string field)
        {
            Internal_API.Invoker.CallNative("_G", "StateUpdate", Internal_API.CallKind.Function, entity, classname, field);
        }
        public static string uuid()
        {
            return Guid.NewGuid().ToString();
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
            List<Player> matchedPlayers = [];

            for(int i = 0; i < 64; i++)
            {
                Player? player = GetPlayer(i);
                if (player == null) continue;

                if (player.IsFakeClient() && !matchbots) continue;

                if(target == "@all")
                {
                    matchedPlayers.Add(player);
                    continue;
                }

                if(target.StartsWith("#"))
                {
                    int pid = Int32.Parse(target.Replace("#", ""));
                    if(pid == i)
                    {
                        matchedPlayers.Add(player);
                        continue;
                    }
                }

                if(Utils.CS2.teamSelector.ContainsKey(target))
                {
                    CBaseEntity ent = player.CBaseEntity();
                    if(ent != null)
                    {
                        if(ent.IsValid())
                        {
                            if((Team)ent.TeamNum == Utils.CS2.teamSelector[target])
                            {
                                matchedPlayers.Add(player);
                                continue;
                            }
                        }
                    }
                }

                if (Utils.CS2.lifeStateSelector.ContainsKey(target))
                {
                    CBaseEntity ent = player.CBaseEntity();
                    if (ent != null)
                    {
                        if (ent.IsValid())
                        {
                            if ((LifeState_t)ent.LifeState == Utils.CS2.lifeStateSelector[target])
                            {
                                matchedPlayers.Add(player);
                                continue;
                            }
                        }
                    }
                }

                if(player.GetSteamID().ToString() == target || player.GetSteamID2() == target)
                {
                    matchedPlayers.Add(player);
                    continue;
                }

                CBasePlayerController controller = player.CBasePlayerController();
                if (controller != null)
                {
                    if (controller.IsValid())
                    {
                        if (controller.PlayerName.Contains(target))
                        {
                            matchedPlayers.Add(player);
                            continue;
                        }
                    }
                }

                var res = Events.TriggerEvent("FindPlayerByTarget", i, target);
                var eventData = res.Item2;
                if(eventData != null)
                {
                    if(eventData.GetReturn<bool>() == true)
                    {
                        matchedPlayers.Add(player);
                        continue;
                    }
                }
            }
            return matchedPlayers.ToArray();
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