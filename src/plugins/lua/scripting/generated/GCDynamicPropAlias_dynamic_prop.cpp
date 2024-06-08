#include "../../../core/scripting/generated/classes/GCDynamicPropAlias_dynamic_prop.h"
#include "../core.h"

void SetupLuaClassGCDynamicPropAlias_dynamic_prop(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDynamicPropAlias_dynamic_prop>("CDynamicPropAlias_dynamic_prop")

        .endClass();
}