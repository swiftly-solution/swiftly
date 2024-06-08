#include "../../../core/scripting/generated/classes/GEventClientSimulate_t.h"
#include "../core.h"

void SetupLuaClassGEventClientSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientSimulate_t>("EventClientSimulate_t")

        .endClass();
}