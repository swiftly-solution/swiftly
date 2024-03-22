#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

#include <rapidjson/document.h>

class LuaPlayerClass
{
public:
    int playerSlot;
    bool fakeClient;

    LuaPlayerClass(int m_playerSlot, bool m_fakeClient) : playerSlot(m_playerSlot), fakeClient(m_fakeClient) {}
};

class LuaPlayerArgsClass
{
public:
    int playerSlot;

    LuaPlayerArgsClass(int m_playerSlot) : playerSlot(m_playerSlot) {}
};

class LuaPlayerTwoArgsClass
{
public:
    int playerSlot;
    uint32 slot;

    LuaPlayerTwoArgsClass(int m_playerSlot, uint32 m_slot) : playerSlot(m_playerSlot), slot(m_slot) {}
};

void SetupLuaPlayer(luacpp::LuaState *state, Plugin *plugin)
{
    auto playerClass = state->CreateClass<LuaPlayerClass>("Player").DefConstructor<int, bool>();

    auto healthClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto armorClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto clantagClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto teamClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto varsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto statsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto moneyClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto coordsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto velocityClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto weaponsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto gravityClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto speedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto eyeangleClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto fovClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto weaponClass = state->CreateClass<LuaPlayerTwoArgsClass>().DefConstructor<int, uint32>();
    auto autokickdisabledClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto availableentitysteadystateClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto predictClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto tickbaseClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lerptimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastrealcommandnumberexecutedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastplayertalktimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastlatecommandexecutedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastentitysteadystateClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lagcompensationClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto islowviolenceClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto ishltvClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hasanysteadystateentsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto gamepausedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();

    playerClass.DefMember("GetSteamID", [](LuaPlayerClass *base) -> uint64_t
                          { return scripting_Player_GetSteamID(base->playerSlot); })
        .DefMember("GetSteamID2", [](LuaPlayerClass *base) -> const char *
                   { return scripting_Player_GetSteamID2(base->playerSlot); })
        .DefMember("GetName", [](LuaPlayerClass *base) -> const char *
                   { return scripting_Player_GetName(base->playerSlot); })
        .DefMember("SetName", [](LuaPlayerClass *base, const char *name) -> void
                   { scripting_Player_SetName(base->playerSlot, name); })
        .DefMember("GetHealth", [](LuaPlayerClass *base) -> int
                   { return scripting_Player_GetHealth(base->playerSlot); })
        .DefMember("GetIPAddress", [](LuaPlayerClass *base) -> const char *
                   { return scripting_Player_GetIPAddress(base->playerSlot); })
        .DefMember("IsFirstSpawn", [](LuaPlayerClass *base) -> bool
                   { return scripting_Player_IsFirstSpawn(base->playerSlot); })
        .DefMember("ShowMenu", [](LuaPlayerClass *base, const char *menuid) -> void
                   { scripting_Player_ShowMenu(base->playerSlot, menuid); })
        .DefMember("GetChatTag", [](LuaPlayerClass *base) -> const char *
                   { return scripting_Player_GetChatTag(base->playerSlot); })
        .DefMember("SetChatTag", [](LuaPlayerClass *base, const char *tag) -> void
                   { scripting_Player_SetChatTag(base->playerSlot, tag); })
        .DefMember("SetCompetitiveRanking", [](LuaPlayerClass *base, int ranking) -> void
                   { scripting_Player_SetCompetitiveRanking(base->playerSlot, ranking); })
        .DefMember("SetCompetitiveRankType", [](LuaPlayerClass *base, int type) -> void
                   { scripting_Player_SetCompetitiveRankType(base->playerSlot, type); })
        .DefMember("SetChatTagColor", [](LuaPlayerClass *base, const char *color) -> void
                   { scripting_Player_SetChatTagColor(base->playerSlot, color); })
        .DefMember("SetNameColor", [](LuaPlayerClass *base, const char *color) -> void
                   { scripting_Player_SetNameColor(base->playerSlot, color); })
        .DefMember("SetChatColor", [](LuaPlayerClass *base, const char *color) -> void
                   { scripting_Player_SetChatColor(base->playerSlot, color); })
        .DefMember("HideMenu", [](LuaPlayerClass *base) -> void
                   { scripting_Player_HideMenu(base->playerSlot); })
        .DefMember("GetConnectedTime", [](LuaPlayerClass *base) -> uint32_t
                   { return scripting_Player_GetConnectedTime(base->playerSlot); })
        .DefMember("SendMsg", [](LuaPlayerClass *base, int dest, const char *message) -> void
                   { return scripting_Player_SendMessage(base->playerSlot, dest, message); })
        .DefMember("SetGloves", [](LuaPlayerClass *base, uint16_t defindex, int paintkit, int seed, float wear) -> void
                   { scripting_Player_SetGloves(base->playerSlot, defindex, paintkit, seed, wear); })
        .DefMember("GetConvarValue", [](LuaPlayerClass *base, const char *name) -> const char *
                   { return scripting_Player_GetConvar(base->playerSlot, name); })
        .DefMember("SetConvar", [](LuaPlayerClass *base, const char *name, const char *value) -> void
                   { scripting_Player_SetConvar(base->playerSlot, name, value); })
        .DefMember("SetFlashDuration", [](LuaPlayerClass *base, float duration) -> void
                   { scripting_Player_SetFlashDuration(base->playerSlot, duration); })
        .DefMember("IsAuthenticated", [](LuaPlayerClass *base) -> bool
                   { return scripting_Player_IsAuthenticated(base->playerSlot); })
        .DefMember("Kill", [](LuaPlayerClass *base) -> void
                   { scripting_Player_Kill(base->playerSlot); })
        .DefMember("Drop", [](LuaPlayerClass *base, int reason) -> void
                   { scripting_Player_Drop(base->playerSlot, reason); })
        .DefMember("IsFakeClient", [](LuaPlayerClass *base) -> bool
                   { return base->fakeClient; })
        .DefMember("GetLatency", [](LuaPlayerClass *base) -> int
                   { return scripting_Player_GetLatency(base->playerSlot); })
        .DefMember("GetSlot", [](LuaPlayerClass *base) -> int
                   { return base->playerSlot; })
        .DefMember("ExecuteCommand", [](LuaPlayerClass *base, const char *command) -> void
                   { scripting_Player_ExecuteCommand(base->playerSlot, command); })
        .DefMember("SetModel", [](LuaPlayerClass *base, const char *model) -> void
                   { scripting_Player_SetModel(base->playerSlot, model); })
        .DefMember("SetMusicKit", [](LuaPlayerClass *base, int musickit) -> void
                   { scripting_Player_SetMusicKit(base->playerSlot, musickit); })
        .DefMember("Respawn", [](LuaPlayerClass *base) -> void
                   { scripting_Player_Respawn(base->playerSlot); })
        .DefMember("SetHealthShotBoostEffectExpirationTime", [](LuaPlayerClass *base, float expireTime) -> void
                   { scripting_Player_SetHealthShotBoostEffectExpirationTime(base->playerSlot, expireTime); })
        .DefMember("health", [healthClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return healthClass.CreateInstance(base->playerSlot); })
        .DefMember("armor", [armorClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return armorClass.CreateInstance(base->playerSlot); })
        .DefMember("clantag", [clantagClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return clantagClass.CreateInstance(base->playerSlot); })
        .DefMember("team", [teamClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return teamClass.CreateInstance(base->playerSlot); })
        .DefMember("vars", [varsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return varsClass.CreateInstance(base->playerSlot); })
        .DefMember("stats", [statsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return statsClass.CreateInstance(base->playerSlot); })
        .DefMember("money", [moneyClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return moneyClass.CreateInstance(base->playerSlot); })
        .DefMember("coords", [coordsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return coordsClass.CreateInstance(base->playerSlot); })
        .DefMember("velocity", [velocityClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return velocityClass.CreateInstance(base->playerSlot); })
        .DefMember("weapons", [weaponsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return weaponsClass.CreateInstance(base->playerSlot); })
        .DefMember("gravity", [gravityClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return gravityClass.CreateInstance(base->playerSlot); })
        .DefMember("speed", [speedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return speedClass.CreateInstance(base->playerSlot); })
        .DefMember("eyeangle", [eyeangleClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return eyeangleClass.CreateInstance(base->playerSlot); })
        .DefMember("autokickdisabled", [autokickdisabledClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return autokickdisabledClass.CreateInstance(base->playerSlot); })
        .DefMember("availableentitysteadystate", [availableentitysteadystateClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return availableentitysteadystateClass.CreateInstance(base->playerSlot); })
        .DefMember("predict", [predictClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return predictClass.CreateInstance(base->playerSlot); })
        .DefMember("gamepaused", [gamepausedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return gamepausedClass.CreateInstance(base->playerSlot); })
        .DefMember("tickbase", [tickbaseClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return tickbaseClass.CreateInstance(base->playerSlot); })
        .DefMember("hasanysteadystateents", [hasanysteadystateentsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hasanysteadystateentsClass.CreateInstance(base->playerSlot); })
        .DefMember("ishltv", [ishltvClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return ishltvClass.CreateInstance(base->playerSlot); })
        .DefMember("islowviolence", [islowviolenceClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return islowviolenceClass.CreateInstance(base->playerSlot); })
        .DefMember("lagcompensation", [lagcompensationClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lagcompensationClass.CreateInstance(base->playerSlot); })
        .DefMember("lastentitysteadystate", [lastentitysteadystateClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastentitysteadystateClass.CreateInstance(base->playerSlot); })
        .DefMember("lastlatecommandexecuted", [lastlatecommandexecutedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastlatecommandexecutedClass.CreateInstance(base->playerSlot); })
        .DefMember("lastplayertalktime", [lastplayertalktimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastplayertalktimeClass.CreateInstance(base->playerSlot); })
        .DefMember("lastrealcommandnumberexecuted", [lastrealcommandnumberexecutedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastrealcommandnumberexecutedClass.CreateInstance(base->playerSlot); })
        .DefMember("lerptime", [lerptimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lerptimeClass.CreateInstance(base->playerSlot); })
        .DefMember("fov", [fovClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return fovClass.CreateInstance(base->playerSlot); });

    gamepausedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                              { return scripting_Player_GetGamePaused(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetGamePaused(base->playerSlot, val); });

    lastplayertalktimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                      { return scripting_Player_GetLastPlayerTalkTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastPlayerTalkTime(base->playerSlot, val); });

    lerptimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                            { return scripting_Player_GetLerpTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLerpTime(base->playerSlot, val); });

    lastrealcommandnumberexecutedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                                 { return scripting_Player_GetLastRealCommandNumberExecuted(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetLastRealCommandNumberExecuted(base->playerSlot, val); });

    ishltvClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                          { return scripting_Player_GetIsHLTV(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetIsHLTV(base->playerSlot, val); });

    lastlatecommandexecutedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                           { return scripting_Player_GetLastLateCommandExecuted(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetLastLateCommandExecuted(base->playerSlot, val); });

    lastentitysteadystateClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                         { return scripting_Player_GetLastEntitySteadyState(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastEntitySteadyState(base->playerSlot, val); });

    lagcompensationClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                   { return scripting_Player_GetLagCompensation(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetLagCompensation(base->playerSlot, val); })

            islowviolenceClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                         { return scripting_Player_GetIsLowViolence(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetIsLowViolence(base->playerSlot, val); });

    hasanysteadystateentsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                         { return scripting_Player_GetHasAnySteadyStateEnts(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHasAnySteadyStateEnts(base->playerSlot, val); });

    healthClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int
                          { return scripting_Player_GetHealth(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int health) -> void
                   { scripting_Player_SetHealth(base->playerSlot, health); })
        .DefMember("Take", [](LuaPlayerArgsClass *base, int health) -> void
                   { scripting_Player_TakeHealth(base->playerSlot, health); })
        .DefMember("GetMax", [](LuaPlayerArgsClass *base) -> int
                   { return scripting_Player_GetMaxHealth(base->playerSlot); })
        .DefMember("SetMax", [](LuaPlayerArgsClass *base, int health) -> void
                   { scripting_Player_SetMaxHealth(base->playerSlot, health); });

    gravityClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                           { return scripting_Player_GetGravity(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float gravity) -> void
                   { scripting_Player_SetGravity(base->playerSlot, gravity); });

    speedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                         { return scripting_Player_GetSpeed(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float speed) -> void
                   { scripting_Player_SetSpeed(base->playerSlot, speed); });

    armorClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int
                         { return scripting_Player_GetArmor(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int armor) -> void
                   { scripting_Player_SetArmor(base->playerSlot, armor); })
        .DefMember("Take", [](LuaPlayerArgsClass *base, int armor) -> void
                   { scripting_Player_TakeArmor(base->playerSlot, armor); });

    clantagClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> const char *
                           { return scripting_Player_GetClanTag(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, const char *tag) -> void
                   { scripting_Player_SetClanTag(base->playerSlot, tag); });

    teamClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint8
                        { return scripting_Player_GetTeam(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int team) -> void
                   { scripting_Player_SetTeam(base->playerSlot, team); });

    varsClass.DefMember("Get", [state](LuaPlayerArgsClass *base, const char *key) -> luacpp::LuaObject
                        {
                            rapidjson::Document doc;
                            doc.Parse(scripting_Player_GetVar(base->playerSlot, key));
                            if(doc.HasParseError()) return state->CreateNil();

                            if(doc["value"].IsString()) return state->CreateString(doc["value"].GetString());
                            else if(doc["value"].IsInt()) return state->CreateInteger(doc["value"].GetInt());
                            else if(doc["value"].IsInt64()) return state->CreateInteger(doc["value"].GetInt64());
                            else if(doc["value"].IsUint()) return state->CreateInteger(doc["value"].GetUint());
                            else if(doc["value"].IsUint64()) return state->CreateInteger(doc["value"].GetUint64());
                            else if(doc["value"].IsBool()) return state->CreateInteger(doc["value"].GetBool());
                            else if(doc["value"].IsFloat()) return state->CreateNumber(doc["value"].GetFloat());
                            else if(doc["value"].IsDouble()) return state->CreateNumber(doc["value"].IsDouble());
                            else return state->CreateNil(); })
        .DefMember("Set", [plugin](LuaPlayerArgsClass *base, const char *key, luacpp::LuaObject value) -> void
                   {
                        if(value.GetType() == LUA_TBOOLEAN) scripting_Player_SetVar(base->playerSlot, key, 7, value.ToBool());
                        else if(value.GetType() == LUA_TSTRING) scripting_Player_SetVar(base->playerSlot, key, 1, value.ToString());
                        else if(value.GetType() == LUA_TNUMBER) {
                            lua_rawgeti(plugin->GetLuaRawState(), LUA_REGISTRYINDEX, value.GetRefIndex());
                            if(lua_isinteger(plugin->GetLuaRawState(), -1) == 1) scripting_Player_SetVar(base->playerSlot, key, 8, value.ToInteger());
                            else {
                                double val = value.ToNumber();
                                scripting_Player_SetVar(base->playerSlot, key, 4, val);
                            }
                            lua_pop(plugin->GetLuaRawState(), 1);
                        } });

    statsClass.DefMember("Get", [](LuaPlayerArgsClass *base, int stat) -> int
                         { return scripting_Player_FetchMatchStat(base->playerSlot, (PlayerStat)stat); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int stat, int value) -> void
                   { scripting_Player_SetMatchStat(base->playerSlot, (PlayerStat)stat, value); });

    autokickdisabledClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                    { return scripting_Player_GetAutoKickDisabled(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetAutoKickDisabled(base->playerSlot, val); });

    availableentitysteadystateClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                              { return scripting_Player_GetAvailableEntitySteadyState(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetAvailableEntitySteadyState(base->playerSlot, val); });

    moneyClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int
                         { return scripting_Player_GetMoney(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int money) -> void
                   { scripting_Player_SetMoney(base->playerSlot, money); })
        .DefMember("Take", [](LuaPlayerArgsClass *base, int money) -> void
                   { scripting_Player_TakeMoney(base->playerSlot, money); });

    predictClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                           { return scripting_Player_GetPredict(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetPredict(base->playerSlot, val); });

    tickbaseClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                            { return scripting_Player_GetTickBase(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetTickBase(base->playerSlot, val); });

    coordsClass.DefMember("Get", [state](LuaPlayerArgsClass *base) -> luacpp::LuaObject
                          {
                            rapidjson::Document doc;
                            doc.Parse(scripting_Player_GetCoords(base->playerSlot));
                            if(doc.HasParseError()) return state->CreateNil();
                            if(!doc["value"].IsObject()) return state->CreateNil();

                            float x = doc["value"]["x"].GetFloat();
                            float y = doc["value"]["y"].GetFloat();
                            float z = doc["value"]["z"].GetFloat();

                            LuaFuncWrapper wrapper(state->Get("vector3"));
                            wrapper.PrepForExec();
                            luacpp::PushValues(wrapper.GetML(), x, y, z);
                            return wrapper.ExecuteWithReturnRaw("vector3", 3); })
        .DefMember("Set", [state](LuaPlayerArgsClass *base, luacpp::LuaObject coordsObj) -> void
                   {
                        if(coordsObj.GetType() != LUA_TTABLE) {
                            PRINT("Runtime", "Coords field needs to be a vector3.\n");
                            return;
                        }

                        luacpp::LuaTable coords = luacpp::LuaTable(coordsObj);

                        if(coords.Get("x").GetType() == LUA_TNIL || coords.Get("y").GetType() == LUA_TNIL || coords.Get("z").GetType() == LUA_TNIL) {
                            PRINT("Runtime", "Coords field needs to be a vector3.\n");
                            return;
                        }

                        scripting_Player_SetCoords(base->playerSlot, (float)coords.GetNumber("x"), (float)coords.GetNumber("y"), (float)coords.GetNumber("z")); });

    velocityClass.DefMember("Get", [state](LuaPlayerArgsClass *base) -> luacpp::LuaObject
                            {
                            rapidjson::Document doc;
                            doc.Parse(scripting_Player_GetVelocity(base->playerSlot));
                            if(doc.HasParseError()) return state->CreateNil();
                            if(!doc["value"].IsObject()) return state->CreateNil();

                            float x = doc["value"]["x"].GetFloat();
                            float y = doc["value"]["y"].GetFloat();
                            float z = doc["value"]["z"].GetFloat();

                            LuaFuncWrapper wrapper(state->Get("vector3"));
                            wrapper.PrepForExec();
                            luacpp::PushValues(wrapper.GetML(), x, y, z);
                            return wrapper.ExecuteWithReturnRaw("vector3", 3); })
        .DefMember("Set", [state](LuaPlayerArgsClass *base, luacpp::LuaObject coordsObj) -> void
                   {
                        if(coordsObj.GetType() != LUA_TTABLE) {
                            PRINT("Runtime", "Coords field needs to be a vector3.\n");
                            return;
                        }

                        luacpp::LuaTable coords = luacpp::LuaTable(coordsObj);

                        if(coords.Get("x").GetType() == LUA_TNIL || coords.Get("y").GetType() == LUA_TNIL || coords.Get("z").GetType() == LUA_TNIL) {
                            PRINT("Runtime", "Coords field needs to be a vector3.\n");
                            return;
                        }

                        scripting_Player_SetVelocity(base->playerSlot, (float)coords.GetNumber("x"),(float)coords.GetNumber("y"), (float)coords.GetNumber("z")); });

    weaponsClass.DefMember("DropWeapons", [](LuaPlayerArgsClass *base) -> void
                           { scripting_Player_Weapons_Drop(base->playerSlot); })
        .DefMember("RemoveWeapons", [](LuaPlayerArgsClass *base) -> void
                   { scripting_Player_Weapons_Remove(base->playerSlot); })
        .DefMember("GiveWeapons", [](LuaPlayerArgsClass *base, const char *name) -> void
                   { scripting_Player_Weapons_Give(base->playerSlot, name); })
        .DefMember("SetActiveWeapon", [](LuaPlayerArgsClass *base, uint32 slot) -> void
                   { scripting_Player_Weapons_SetActiveWeapon(base->playerSlot, slot); })
        .DefMember("GetWeaponFromSlot", [weaponClass](LuaPlayerArgsClass *base, uint32 slot) -> luacpp::LuaObject
                   { return weaponClass.CreateInstance(base->playerSlot, scripting_Player_Weapons_GetWeaponID(base->playerSlot, slot)); })
        .DefMember("GetWeapon", [weaponClass](LuaPlayerArgsClass *base, uint32 weaponID) -> luacpp::LuaObject
                   { return weaponClass.CreateInstance(base->playerSlot, weaponID); });

    weaponClass.DefMember("Remove", [](LuaPlayerTwoArgsClass *base) -> void
                          { scripting_Player_Weapon_Remove(base->playerSlot, base->slot); })
        .DefMember("Drop", [](LuaPlayerTwoArgsClass *base) -> void
                   { scripting_Player_Weapon_Drop(base->playerSlot, base->slot); })
        .DefMember("SetStatTrack", [](LuaPlayerTwoArgsClass *base, bool stattrack) -> void
                   { scripting_Player_Weapon_SetStatTrack(base->playerSlot, base->slot, stattrack); })
        .DefMember("SetWear", [](LuaPlayerTwoArgsClass *base, float wear) -> void
                   { scripting_Player_Weapon_SetWear(base->playerSlot, base->slot, wear); })
        .DefMember("SetPaintKit", [](LuaPlayerTwoArgsClass *base, int paintkit) -> void
                   { scripting_Player_Weapon_SetPaintKit(base->playerSlot, base->slot, paintkit); })
        .DefMember("SetSeed", [](LuaPlayerTwoArgsClass *base, int seed) -> void
                   { scripting_Player_Weapon_SetSeed(base->playerSlot, base->slot, seed); })
        .DefMember("GetStatTrack", [](LuaPlayerTwoArgsClass *base) -> bool
                   { return scripting_Player_Weapon_GetStatTrack(base->playerSlot, base->slot); })
        .DefMember("GetWear", [](LuaPlayerTwoArgsClass *base) -> float
                   { return scripting_Player_Weapon_GetWear(base->playerSlot, base->slot); })
        .DefMember("GetPaintKit", [](LuaPlayerTwoArgsClass *base) -> int
                   { return scripting_Player_Weapon_GetPaintKit(base->playerSlot, base->slot); })
        .DefMember("GetSeed", [](LuaPlayerTwoArgsClass *base) -> int
                   { return scripting_Player_Weapon_GetSeed(base->playerSlot, base->slot); })
        .DefMember("GetType", [](LuaPlayerTwoArgsClass *base) -> uint32
                   { return scripting_Player_Weapon_GetType(base->playerSlot, base->slot); })
        .DefMember("GetName", [](LuaPlayerTwoArgsClass *base) -> const char *
                   { return scripting_Player_Weapon_GetName(base->playerSlot, base->slot); })
        .DefMember("Exists", [](LuaPlayerTwoArgsClass *base) -> bool
                   { return scripting_Player_Weapon_Exists(base->playerSlot, base->slot); })
        .DefMember("SetDefaultChangeSkinAttributes", [](LuaPlayerTwoArgsClass *base) -> void
                   { scripting_Player_Weapon_SetDefaultChangeSkinAttributes(base->playerSlot, base->slot); })
        .DefMember("GetID", [](LuaPlayerTwoArgsClass *base) -> uint32
                   { return base->slot; })
        .DefMember("SetNametag", [](LuaPlayerTwoArgsClass *base, const char *text) -> void
                   { scripting_Player_Weapon_SetNametag(base->playerSlot, base->slot, text); })
        .DefMember("GetSilencerType", [](LuaPlayerTwoArgsClass *base) -> uint32_t
                   { return scripting_Player_Weapon_GetSilencerType(base->playerSlot, base->slot); })
        .DefMember("SetClipAmmo", [](LuaPlayerTwoArgsClass *base, int ammo) -> void
                   { scripting_Player_Weapon_SetClipAmmo(base->playerSlot, base->slot, ammo); })
        .DefMember("SetClip2Ammo", [](LuaPlayerTwoArgsClass *base, int ammo) -> void
                   { scripting_Player_Weapon_SetClip2Ammo(base->playerSlot, base->slot, ammo); })
        .DefMember("SetReserveAmmo", [](LuaPlayerTwoArgsClass *base, int ammo) -> void
                   { scripting_Player_Weapon_SetReserveAmmo(base->playerSlot, base->slot, ammo); })
        .DefMember("GetNextPrimaryAttackTick", [](LuaPlayerTwoArgsClass *base) -> int32_t
                   { return scripting_Player_Weapon_GetNextPrimaryAttackTick(base->playerSlot, base->slot); })
        .DefMember("SetNextPrimaryAttackTick", [](LuaPlayerTwoArgsClass *base, int32_t tick) -> void
                   { scripting_Player_Weapon_SetNextPrimaryAttackTick(base->playerSlot, base->slot, tick); })
        .DefMember("GetNextSecondaryAttackTick", [](LuaPlayerTwoArgsClass *base) -> int32_t
                   { return scripting_Player_Weapon_GetNextSecondaryAttackTick(base->playerSlot, base->slot); })
        .DefMember("SetNextSecondaryAttackTick", [](LuaPlayerTwoArgsClass *base, int32_t tick) -> void
                   { scripting_Player_Weapon_SetNextSecondaryAttackTick(base->playerSlot, base->slot, tick); })
        .DefMember("GetNextPrimaryAttackTickRatio", [](LuaPlayerTwoArgsClass *base) -> float
                   { return scripting_Player_Weapon_GetNextPrimaryAttackTickRatio(base->playerSlot, base->slot); })
        .DefMember("SetNextPrimaryAttackTickRatio", [](LuaPlayerTwoArgsClass *base, float ratio) -> void
                   { scripting_Player_Weapon_SetNextPrimaryAttackTickRatio(base->playerSlot, base->slot, ratio); })
        .DefMember("GetNextSecondaryAttackTickRatio", [](LuaPlayerTwoArgsClass *base) -> float
                   { return scripting_Player_Weapon_GetNextSecondaryAttackTickRatio(base->playerSlot, base->slot); })
        .DefMember("SetNextSecondaryAttackTickRatio", [](LuaPlayerTwoArgsClass *base, float ratio) -> void
                   { scripting_Player_Weapon_SetNextSecondaryAttackTickRatio(base->playerSlot, base->slot, ratio); });

    eyeangleClass.DefMember("Get", [state](LuaPlayerArgsClass *base) -> luacpp::LuaObject
                            {
                            QAngle angle = scripting_Player_GetEyeAnglesRaw(base->playerSlot);

                            float x = angle.x;
                            float y = angle.y;
                            float z = angle.z;

                            LuaFuncWrapper wrapper(state->Get("vector3"));
                            wrapper.PrepForExec();
                            luacpp::PushValues(wrapper.GetML(), x, y, z);
                            return wrapper.ExecuteWithReturnRaw("vector3", 3); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, luacpp::LuaObject coordsObj) -> void
                   {
                                if (coordsObj.GetType() != LUA_TTABLE) {
                                    PRINT("Runtime", "Coords field needs to be a vector3.\n");
                                    return;
                                }

                                luacpp::LuaTable coords = luacpp::LuaTable(coordsObj);

                                if (coords.Get("x").GetType() == LUA_TNIL || coords.Get("y").GetType() == LUA_TNIL || coords.Get("z").GetType() == LUA_TNIL) {
                                    PRINT("Runtime", "Coords field needs to be a vector3.\n");
                                    return;
                                }

                                scripting_Player_SetEyeAngles(base->playerSlot, (float)coords.GetNumber("x"), (float)coords.GetNumber("y"), (float)coords.GetNumber("z")); });

    fovClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                       { return scripting_Player_GetDesiredFOV(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t fov)
                   { scripting_Player_SetDesiredFOV(base->playerSlot, fov); });
}