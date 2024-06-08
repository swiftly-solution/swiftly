#include "../../../core/scripting/generated/classes/GChainToSolveData_t.h"
#include "../core.h"

void SetupLuaClassGChainToSolveData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GChainToSolveData_t>("ChainToSolveData_t")
        .addProperty("ChainIndex", &GChainToSolveData_t::GetChainIndex, &GChainToSolveData_t::SetChainIndex)
        .addProperty("SolverSettings", &GChainToSolveData_t::GetSolverSettings, &GChainToSolveData_t::SetSolverSettings)
        .addProperty("TargetSettings", &GChainToSolveData_t::GetTargetSettings, &GChainToSolveData_t::SetTargetSettings)
        .addProperty("DebugSetting", &GChainToSolveData_t::GetDebugSetting, &GChainToSolveData_t::SetDebugSetting)
        .addProperty("DebugNormalizedValue", &GChainToSolveData_t::GetDebugNormalizedValue, &GChainToSolveData_t::SetDebugNormalizedValue)
        .addProperty("DebugOffset", &GChainToSolveData_t::GetDebugOffset, &GChainToSolveData_t::SetDebugOffset)
        .endClass();
}