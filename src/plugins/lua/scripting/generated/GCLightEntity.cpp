#include "../../../core/scripting/generated/classes/GCLightEntity.h"
#include "../core.h"

void SetupLuaClassGCLightEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightEntity>("CLightEntity")
        .addProperty("CLightComponent", &GCLightEntity::GetCLightComponent, &GCLightEntity::SetCLightComponent)
        .endClass();
}