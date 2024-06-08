#include "../../../core/scripting/generated/classes/GWorld_t.h"
#include "../core.h"

void SetupLuaClassGWorld_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWorld_t>("World_t")
        .addProperty("BuilderParams", &GWorld_t::GetBuilderParams, &GWorld_t::SetBuilderParams)
        .addProperty("WorldNodes", &GWorld_t::GetWorldNodes, &GWorld_t::SetWorldNodes)
        .addProperty("WorldLightingInfo", &GWorld_t::GetWorldLightingInfo, &GWorld_t::SetWorldLightingInfo)
        .endClass();
}