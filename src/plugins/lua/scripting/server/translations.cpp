#include "../core.h"

LoadLuaScriptingComponent(
    translation,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .addFunction("FetchTranslation", +[](lua_State *L) -> std::string
            {
                auto key = luabridge::LuaRef::fromStack(L, 1).cast<std::string>();
                int playerid = -1;
                auto pidRef = luabridge::LuaRef::fromStack(L, 2);
                if(pidRef.isNumber())
                    playerid = pidRef.cast<int>();

                return scripting_FetchTranslation(key, playerid);
            });
    }
)