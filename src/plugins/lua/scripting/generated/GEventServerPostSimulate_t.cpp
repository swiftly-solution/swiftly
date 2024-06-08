#include "../../../core/scripting/generated/classes/GEventServerPostSimulate_t.h"
#include "../core.h"

void SetupLuaClassGEventServerPostSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerPostSimulate_t>("EventServerPostSimulate_t")

        .endClass();
}