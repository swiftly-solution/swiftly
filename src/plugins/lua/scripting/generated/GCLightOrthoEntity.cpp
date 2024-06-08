#include "../../../core/scripting/generated/classes/GCLightOrthoEntity.h"
#include "../core.h"

void SetupLuaClassGCLightOrthoEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightOrthoEntity>("CLightOrthoEntity")

        .endClass();
}