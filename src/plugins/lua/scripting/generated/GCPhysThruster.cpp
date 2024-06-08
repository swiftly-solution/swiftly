#include "../../../core/scripting/generated/classes/GCPhysThruster.h"
#include "../core.h"

void SetupLuaClassGCPhysThruster(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysThruster>("CPhysThruster")
        .addProperty("LocalOrigin", &GCPhysThruster::GetLocalOrigin, &GCPhysThruster::SetLocalOrigin)
        .endClass();
}