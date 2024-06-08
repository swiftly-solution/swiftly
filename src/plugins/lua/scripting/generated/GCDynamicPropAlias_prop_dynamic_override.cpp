#include "../../../core/scripting/generated/classes/GCDynamicPropAlias_prop_dynamic_override.h"
#include "../core.h"

void SetupLuaClassGCDynamicPropAlias_prop_dynamic_override(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDynamicPropAlias_prop_dynamic_override>("CDynamicPropAlias_prop_dynamic_override")

        .endClass();
}