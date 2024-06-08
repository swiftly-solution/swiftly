#include "../../../core/scripting/generated/classes/GC_INIT_DistanceToNeighborCull.h"
#include "../core.h"

void SetupLuaClassGC_INIT_DistanceToNeighborCull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_DistanceToNeighborCull>("C_INIT_DistanceToNeighborCull")
        .addProperty("Distance", &GC_INIT_DistanceToNeighborCull::GetDistance, &GC_INIT_DistanceToNeighborCull::SetDistance)
        .endClass();
}