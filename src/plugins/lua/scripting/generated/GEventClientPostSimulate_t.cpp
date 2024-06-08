#include "../../../core/scripting/generated/classes/GEventClientPostSimulate_t.h"
#include "../core.h"

void SetupLuaClassGEventClientPostSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPostSimulate_t>("EventClientPostSimulate_t")

        .endClass();
}