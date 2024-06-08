#include "../../../core/scripting/generated/classes/GCDynamicPropAlias_cable_dynamic.h"
#include "../core.h"

void SetupLuaClassGCDynamicPropAlias_cable_dynamic(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDynamicPropAlias_cable_dynamic>("CDynamicPropAlias_cable_dynamic")

        .endClass();
}