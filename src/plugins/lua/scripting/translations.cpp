#include "core.h"

void SetupLuaTranslations(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .addFunction("FetchTranslation", +[](std::string key, lua_State *L) -> std::string
                     { return scripting_FetchTranslation(FetchPlugin(L), key); });
}