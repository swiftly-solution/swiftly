#include "../../../core/scripting/generated/classes/GEventClientAdvanceTick_t.h"
#include "../core.h"

void SetupLuaClassGEventClientAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientAdvanceTick_t>("EventClientAdvanceTick_t")

        .endClass();
}