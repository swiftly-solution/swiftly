#include "../../../core/scripting/generated/classes/GCLightDirectionalEntity.h"
#include "../core.h"

void SetupLuaClassGCLightDirectionalEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightDirectionalEntity>("CLightDirectionalEntity")

        .endClass();
}