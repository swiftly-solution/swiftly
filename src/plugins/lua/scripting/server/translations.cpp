#include "../core.h"

LoadLuaScriptingComponent(
    translation,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .addFunction("FetchTranslation", +[](std::string key, lua_State *L) -> std::string
            {
                int playerid = -1;
                int argsCount = lua_gettop(L);
                if (argsCount > 1) {
                    if (lua_isnumber(L, 2)) {
                        playerid = static_cast<int>(lua_tointeger(L, 2));
                    }
                }

                return scripting_FetchTranslation(FetchPluginByState(L), key, playerid);
            });
    }
)