#include "../../../core/scripting/generated/classes/GSolveIKChainPoseOpFixedSettings_t.h"
#include "../core.h"

void SetupLuaClassGSolveIKChainPoseOpFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSolveIKChainPoseOpFixedSettings_t>("SolveIKChainPoseOpFixedSettings_t")
        .addProperty("ChainsToSolveData", &GSolveIKChainPoseOpFixedSettings_t::GetChainsToSolveData, &GSolveIKChainPoseOpFixedSettings_t::SetChainsToSolveData)
        .addProperty("MatchTargetOrientation", &GSolveIKChainPoseOpFixedSettings_t::GetMatchTargetOrientation, &GSolveIKChainPoseOpFixedSettings_t::SetMatchTargetOrientation)
        .endClass();
}