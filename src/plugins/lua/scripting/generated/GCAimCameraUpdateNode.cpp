#include "../../../core/scripting/generated/classes/GCAimCameraUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCAimCameraUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAimCameraUpdateNode>("CAimCameraUpdateNode")
        .addProperty("ParameterPosition", &GCAimCameraUpdateNode::GetParameterPosition, &GCAimCameraUpdateNode::SetParameterPosition)
        .addProperty("ParameterOrientation", &GCAimCameraUpdateNode::GetParameterOrientation, &GCAimCameraUpdateNode::SetParameterOrientation)
        .addProperty("ParameterSpineRotationWeight", &GCAimCameraUpdateNode::GetParameterSpineRotationWeight, &GCAimCameraUpdateNode::SetParameterSpineRotationWeight)
        .addProperty("ParameterPelvisOffset", &GCAimCameraUpdateNode::GetParameterPelvisOffset, &GCAimCameraUpdateNode::SetParameterPelvisOffset)
        .addProperty("ParameterUseIK", &GCAimCameraUpdateNode::GetParameterUseIK, &GCAimCameraUpdateNode::SetParameterUseIK)
        .addProperty("ParameterWeaponDepenetrationDistance", &GCAimCameraUpdateNode::GetParameterWeaponDepenetrationDistance, &GCAimCameraUpdateNode::SetParameterWeaponDepenetrationDistance)
        .addProperty("ParameterCameraClearanceDistance", &GCAimCameraUpdateNode::GetParameterCameraClearanceDistance, &GCAimCameraUpdateNode::SetParameterCameraClearanceDistance)
        .addProperty("OpFixedSettings", &GCAimCameraUpdateNode::GetOpFixedSettings, &GCAimCameraUpdateNode::SetOpFixedSettings)
        .endClass();
}