#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

int StringToInt(const char *str)
{
    int retval;
    try
    {
        retval = std::stoi(str);
    }
    catch (std::invalid_argument &ex)
    {
        retval = -1;
    }
    catch (std::out_of_range &exr)
    {
        retval = -1;
    }
    return retval;
}

void SetupLuaEnvironment(luacpp::LuaState *state, Plugin *plugin)
{
    luacpp::LuaTable playerTable = (state->Get("players").GetType() == LUA_TNIL ? state->CreateTable("players") : state->GetTable("players"));

    state->CreateFunction([](const char *plugin_name) -> int
                          { return scripting_GetPluginState(plugin_name); },
                          "GetPluginState");

    state->CreateFunction([plugin]() -> const char *
                          { return plugin->GetName().c_str(); },
                          "PluginName");
    state->CreateFunction([playerTable, state](int playerID) -> luacpp::LuaObject
                          {
        if(playerTable.Get(playerID).GetType() == LUA_TNIL) return state->CreateNil();
        else return playerTable.Get(playerID); },
                          "GetPlayer");
    state->CreateFunction([playerTable, state](const char *content, bool matchbots) -> int
                          {
        if(content == nullptr) return -1;
        int slot = StringToInt(content + 1);
        if(slot != -1) return slot;

        std::string match = str_tolower(content);
        for (int i = 0; i < g_playerManager->GetPlayerCap(); i++)
        {
            Player *player = g_playerManager->GetPlayer(i);
            if (player == nullptr)
                continue;
            if (!matchbots && player->IsFakeClient())
                continue;

            if (std::to_string(player->GetSteamID()) == match || std::string(str_tolower(player->GetName())).find(match) != std::string::npos)
                return i;
        }

        return -1; },
                          "GetPlayerId");
    state->CreateFunction([playerTable]() -> luacpp::LuaTable
                          { return playerTable; },
                          "GetPlayers");

    SetupLuaCommands(state, plugin);
    SetupLuaConfiguration(state, plugin);
    SetupLuaConvars(state, plugin);
    SetupLuaDatabase(state, plugin);
    SetupLuaEntities(state, plugin);
    SetupLuaExports(state, plugin);
    SetupLuaFiles(state, plugin);
    SetupLuaGameEvents(state, plugin);
    SetupLuaHTTP(state, plugin);
    SetupLuaLogger(state, plugin);
    SetupLuaMenus(state, plugin);
    SetupLuaPlayer(state, plugin);
    SetupLuaPlayerManager(state, plugin);
    SetupLuaPrecacher(state, plugin);
    SetupLuaServer(state, plugin);
    SetupLuaTimers(state, plugin);
    SetupLuaTranslation(state, plugin);
    SetupLuaTypes(state, plugin);
    SetupLuaUtils(state, plugin);
}