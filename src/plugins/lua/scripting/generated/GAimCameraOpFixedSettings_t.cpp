#include "../../../core/scripting/generated/classes/GAimCameraOpFixedSettings_t.h"
#include "../core.h"

void SetupLuaClassGAimCameraOpFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAimCameraOpFixedSettings_t>("AimCameraOpFixedSettings_t")
        .addProperty("ChainIndex", &GAimCameraOpFixedSettings_t::GetChainIndex, &GAimCameraOpFixedSettings_t::SetChainIndex)
        .addProperty("CameraJointIndex", &GAimCameraOpFixedSettings_t::GetCameraJointIndex, &GAimCameraOpFixedSettings_t::SetCameraJointIndex)
        .addProperty("PelvisJointIndex", &GAimCameraOpFixedSettings_t::GetPelvisJointIndex, &GAimCameraOpFixedSettings_t::SetPelvisJointIndex)
        .addProperty("ClavicleLeftJointIndex", &GAimCameraOpFixedSettings_t::GetClavicleLeftJointIndex, &GAimCameraOpFixedSettings_t::SetClavicleLeftJointIndex)
        .addProperty("ClavicleRightJointIndex", &GAimCameraOpFixedSettings_t::GetClavicleRightJointIndex, &GAimCameraOpFixedSettings_t::SetClavicleRightJointIndex)
        .addProperty("DepenetrationJointIndex", &GAimCameraOpFixedSettings_t::GetDepenetrationJointIndex, &GAimCameraOpFixedSettings_t::SetDepenetrationJointIndex)
        .addProperty("PropJoints", &GAimCameraOpFixedSettings_t::GetPropJoints, &GAimCameraOpFixedSettings_t::SetPropJoints)
        .endClass();
}