#include "../../../core/scripting/generated/classes/GCBaseFlexAlias_funCBaseFlex.h"
#include "../core.h"

void SetupLuaClassGCBaseFlexAlias_funCBaseFlex(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseFlexAlias_funCBaseFlex>("CBaseFlexAlias_funCBaseFlex")

        .endClass();
}