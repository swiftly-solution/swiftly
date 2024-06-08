#include "../../../core/scripting/generated/classes/GCFishPool.h"
#include "../core.h"

void SetupLuaClassGCFishPool(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFishPool>("CFishPool")
        .addProperty("FishCount", &GCFishPool::GetFishCount, &GCFishPool::SetFishCount)
        .addProperty("MaxRange", &GCFishPool::GetMaxRange, &GCFishPool::SetMaxRange)
        .addProperty("SwimDepth", &GCFishPool::GetSwimDepth, &GCFishPool::SetSwimDepth)
        .addProperty("WaterLevel", &GCFishPool::GetWaterLevel, &GCFishPool::SetWaterLevel)
        .addProperty("IsDormant", &GCFishPool::GetIsDormant, &GCFishPool::SetIsDormant)
        .addProperty("VisTimer", &GCFishPool::GetVisTimer, &GCFishPool::SetVisTimer)
        .endClass();
}