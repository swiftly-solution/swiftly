#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

extern std::map<std::string, std::map<std::string, std::vector<luacpp::LuaObject>>> lua_game_events;
std::map<std::string, std::map<std::string, std::vector<luacpp::LuaObject>>> lua_game_events;

class LuaGameEvents
{
public:
    LuaGameEvents() {}
};

void SetupLuaGameEvents(luacpp::LuaState *state, Plugin *plugin)
{
    auto eventsClass = state->CreateClass<LuaGameEvents>("Events").DefConstructor();

    eventsClass.DefMember("on", [plugin](LuaGameEvents *base, const char *eventName, const luacpp::LuaObject &function) -> void
                          {
                              if (function.GetType() != LUA_TFUNCTION)
                              {
                                  PRINTF("Runtime", "An error has occured while registering game event '%s'.\nError: No function was provided as a second argument.\n", eventName);
                                  return;
                              }

                              std::string eName = eventName;

                              if (lua_game_events.find(plugin->GetName()) == lua_game_events.end())
                                  lua_game_events.insert(std::make_pair(plugin->GetName(), std::map<std::string, std::vector<luacpp::LuaObject>>{}));

                              std::map<std::string, std::vector<luacpp::LuaObject>> events = lua_game_events.at(plugin->GetName());
                              if (events.find(eName) == events.end())
                                  events.insert(std::make_pair(eName, std::vector<luacpp::LuaObject>{}));

                              std::vector<luacpp::LuaObject> objs = events.at(eName);
                              
                              objs.push_back(function);

                              lua_game_events[plugin->GetName()][eName] = objs; });

    state->DoString("events = Events()");

    state->DoString("function Internal_RegisterPlayer(slot, fake) players[slot] = Player(slot, fake); end");
    state->DoString("function Internal_UnregisterPlayer(slot) players[slot] = nil; end");
    state->DoString("function Internal_OnProgramLoad(plugin_name, bin) if OnProgramLoad then OnProgramLoad(plugin_name, bin) end end");

    PRINT("Scripting - Lua", "Game Events loaded.\n");
}