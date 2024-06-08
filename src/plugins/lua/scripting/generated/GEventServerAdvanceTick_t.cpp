#include "../../../core/scripting/generated/classes/GEventServerAdvanceTick_t.h"
#include "../core.h"

void SetupLuaClassGEventServerAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerAdvanceTick_t>("EventServerAdvanceTick_t")

        .endClass();
}