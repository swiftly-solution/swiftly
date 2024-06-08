#include "../../../core/scripting/generated/classes/GCLightSpotEntity.h"
#include "../core.h"

void SetupLuaClassGCLightSpotEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightSpotEntity>("CLightSpotEntity")

        .endClass();
}