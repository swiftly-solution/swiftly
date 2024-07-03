#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAimCameraUpdateNode::GCAimCameraUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAimCameraUpdateNode::GCAimCameraUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCAnimParamHandle GCAimCameraUpdateNode::GetParameterPosition() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CAimCameraUpdateNode", "m_hParameterPosition"));
    return value;
}
void GCAimCameraUpdateNode::SetParameterPosition(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterPosition", false, value);
}
GCAnimParamHandle GCAimCameraUpdateNode::GetParameterOrientation() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CAimCameraUpdateNode", "m_hParameterOrientation"));
    return value;
}
void GCAimCameraUpdateNode::SetParameterOrientation(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterOrientation", false, value);
}
GCAnimParamHandle GCAimCameraUpdateNode::GetParameterSpineRotationWeight() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CAimCameraUpdateNode", "m_hParameterSpineRotationWeight"));
    return value;
}
void GCAimCameraUpdateNode::SetParameterSpineRotationWeight(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterSpineRotationWeight", false, value);
}
GCAnimParamHandle GCAimCameraUpdateNode::GetParameterPelvisOffset() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CAimCameraUpdateNode", "m_hParameterPelvisOffset"));
    return value;
}
void GCAimCameraUpdateNode::SetParameterPelvisOffset(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterPelvisOffset", false, value);
}
GCAnimParamHandle GCAimCameraUpdateNode::GetParameterUseIK() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CAimCameraUpdateNode", "m_hParameterUseIK"));
    return value;
}
void GCAimCameraUpdateNode::SetParameterUseIK(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterUseIK", false, value);
}
GCAnimParamHandle GCAimCameraUpdateNode::GetParameterWeaponDepenetrationDistance() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CAimCameraUpdateNode", "m_hParameterWeaponDepenetrationDistance"));
    return value;
}
void GCAimCameraUpdateNode::SetParameterWeaponDepenetrationDistance(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterWeaponDepenetrationDistance", false, value);
}
GCAnimParamHandle GCAimCameraUpdateNode::GetParameterCameraClearanceDistance() const {
    GCAnimParamHandle value(GetSchemaPtr(m_ptr, "CAimCameraUpdateNode", "m_hParameterCameraClearanceDistance"));
    return value;
}
void GCAimCameraUpdateNode::SetParameterCameraClearanceDistance(GCAnimParamHandle value) {
    SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_hParameterCameraClearanceDistance", false, value);
}
GAimCameraOpFixedSettings_t GCAimCameraUpdateNode::GetOpFixedSettings() const {
    GAimCameraOpFixedSettings_t value(GetSchemaPtr(m_ptr, "CAimCameraUpdateNode", "m_opFixedSettings"));
    return value;
}
void GCAimCameraUpdateNode::SetOpFixedSettings(GAimCameraOpFixedSettings_t value) {
    SetSchemaValue(m_ptr, "CAimCameraUpdateNode", "m_opFixedSettings", false, value);
}
std::string GCAimCameraUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAimCameraUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCAimCameraUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCAimCameraUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAimCameraUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAimCameraUpdateNode>("CAimCameraUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParameterPosition", &GCAimCameraUpdateNode::GetParameterPosition, &GCAimCameraUpdateNode::SetParameterPosition)
        .addProperty("ParameterOrientation", &GCAimCameraUpdateNode::GetParameterOrientation, &GCAimCameraUpdateNode::SetParameterOrientation)
        .addProperty("ParameterSpineRotationWeight", &GCAimCameraUpdateNode::GetParameterSpineRotationWeight, &GCAimCameraUpdateNode::SetParameterSpineRotationWeight)
        .addProperty("ParameterPelvisOffset", &GCAimCameraUpdateNode::GetParameterPelvisOffset, &GCAimCameraUpdateNode::SetParameterPelvisOffset)
        .addProperty("ParameterUseIK", &GCAimCameraUpdateNode::GetParameterUseIK, &GCAimCameraUpdateNode::SetParameterUseIK)
        .addProperty("ParameterWeaponDepenetrationDistance", &GCAimCameraUpdateNode::GetParameterWeaponDepenetrationDistance, &GCAimCameraUpdateNode::SetParameterWeaponDepenetrationDistance)
        .addProperty("ParameterCameraClearanceDistance", &GCAimCameraUpdateNode::GetParameterCameraClearanceDistance, &GCAimCameraUpdateNode::SetParameterCameraClearanceDistance)
        .addProperty("OpFixedSettings", &GCAimCameraUpdateNode::GetOpFixedSettings, &GCAimCameraUpdateNode::SetOpFixedSettings)
        .addProperty("Parent", &GCAimCameraUpdateNode::GetParent, &GCAimCameraUpdateNode::SetParent)
        .addFunction("ToPtr", &GCAimCameraUpdateNode::ToPtr)
        .addFunction("IsValid", &GCAimCameraUpdateNode::IsValid)
        .endClass();
}