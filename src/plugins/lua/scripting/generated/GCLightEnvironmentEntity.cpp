#include "../../../core/scripting/generated/classes/GCLightEnvironmentEntity.h"
#include "../core.h"

void SetupLuaClassGCLightEnvironmentEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightEnvironmentEntity>("CLightEnvironmentEntity")

        .endClass();
}