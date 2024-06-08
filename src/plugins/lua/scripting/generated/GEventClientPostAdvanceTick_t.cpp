#include "../../../core/scripting/generated/classes/GEventClientPostAdvanceTick_t.h"
#include "../core.h"

void SetupLuaClassGEventClientPostAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPostAdvanceTick_t>("EventClientPostAdvanceTick_t")

        .endClass();
}