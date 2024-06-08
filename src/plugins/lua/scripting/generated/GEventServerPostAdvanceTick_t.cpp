#include "../../../core/scripting/generated/classes/GEventServerPostAdvanceTick_t.h"
#include "../core.h"

void SetupLuaClassGEventServerPostAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventServerPostAdvanceTick_t>("EventServerPostAdvanceTick_t")

        .endClass();
}