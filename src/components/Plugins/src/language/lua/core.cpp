#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

void SetupLuaEnvironment(Plugin *plugin)
{
    luacpp::LuaState *state = plugin->GetLuaState();
    luacpp::LuaTable playerTable = state->CreateTable("players");

    state->CreateFunction([plugin]() -> void
                          {
                                lua_State* st = plugin->GetLuaRawState();

                                int n = lua_gettop(st);

                                lua_getglobal(st, "tostring");

                                for(int i = 1; i <= n; i++) {
                                    lua_pushvalue(st, -1);
                                    lua_pushvalue(st,i);
                                    lua_call(st,1,1);

                                    size_t l = 0;
                                    const char* s = lua_tolstring(st, -1, &l);
                                    if(s == nullptr) {
                                        PRINTF("Runtime", "An error has occured while trying to call 'print'.\nError: 'tostring' must return a string to 'print'\n");
                                        break;
                                    }

                                    if(i > 1) scripting_Print("\t");
                                    scripting_Print(s);
                                    lua_pop(st,1);
                                } scripting_Print("\n"); },
                          "print");
    state->CreateFunction([plugin]() -> const char *
                          { return plugin->GetName().c_str(); },
                          "PluginName");
    state->CreateFunction([playerTable, state](int playerID) -> luacpp::LuaObject
                          {
        if(playerTable.Get(playerID).GetType() == LUA_TNIL) return state->CreateNil();
        else return playerTable.Get(playerID); },
                          "GetPlayer");
    state->CreateFunction([playerTable]() -> luacpp::LuaTable
                          { return playerTable; },
                          "GetPlayers");

    PRINT("Scripting - Lua", "Core loaded.\n");

    SetupLuaCommands(state, plugin);
    SetupLuaConfiguration(state, plugin);
    SetupLuaConvars(state, plugin);
    SetupLuaDatabase(state, plugin);
    SetupLuaEntities(state, plugin);
    SetupLuaGameEvents(state, plugin);
    SetupLuaHTTP(state, plugin);
    SetupLuaLogger(state, plugin);
    SetupLuaPlayer(state, plugin);
    SetupLuaPlayerManager(state, plugin);
    SetupLuaPrecacher(state, plugin);
    SetupLuaServer(state, plugin);
    SetupLuaTimers(state, plugin);
    SetupLuaTranslation(state, plugin);
    SetupLuaTypes(state, plugin);
    SetupLuaUtils(state, plugin);
}