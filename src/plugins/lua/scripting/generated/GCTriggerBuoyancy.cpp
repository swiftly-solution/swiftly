#include "../../../core/scripting/generated/classes/GCTriggerBuoyancy.h"
#include "../core.h"

void SetupLuaClassGCTriggerBuoyancy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerBuoyancy>("CTriggerBuoyancy")
        .addProperty("BuoyancyHelper", &GCTriggerBuoyancy::GetBuoyancyHelper, &GCTriggerBuoyancy::SetBuoyancyHelper)
        .addProperty("FluidDensity", &GCTriggerBuoyancy::GetFluidDensity, &GCTriggerBuoyancy::SetFluidDensity)
        .endClass();
}