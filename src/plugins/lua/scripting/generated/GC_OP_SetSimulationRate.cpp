#include "../../../core/scripting/generated/classes/GC_OP_SetSimulationRate.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetSimulationRate(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetSimulationRate>("C_OP_SetSimulationRate")
        .addProperty("SimulationScale", &GC_OP_SetSimulationRate::GetSimulationScale, &GC_OP_SetSimulationRate::SetSimulationScale)
        .endClass();
}