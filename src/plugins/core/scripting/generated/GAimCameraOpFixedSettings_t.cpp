#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAimCameraOpFixedSettings_t::GAimCameraOpFixedSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAimCameraOpFixedSettings_t::GAimCameraOpFixedSettings_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GAimCameraOpFixedSettings_t::GetChainIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nChainIndex");
}
void GAimCameraOpFixedSettings_t::SetChainIndex(int32_t value) {
    SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nChainIndex", true, value);
}
int32_t GAimCameraOpFixedSettings_t::GetCameraJointIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nCameraJointIndex");
}
void GAimCameraOpFixedSettings_t::SetCameraJointIndex(int32_t value) {
    SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nCameraJointIndex", true, value);
}
int32_t GAimCameraOpFixedSettings_t::GetPelvisJointIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nPelvisJointIndex");
}
void GAimCameraOpFixedSettings_t::SetPelvisJointIndex(int32_t value) {
    SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nPelvisJointIndex", true, value);
}
int32_t GAimCameraOpFixedSettings_t::GetClavicleLeftJointIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nClavicleLeftJointIndex");
}
void GAimCameraOpFixedSettings_t::SetClavicleLeftJointIndex(int32_t value) {
    SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nClavicleLeftJointIndex", true, value);
}
int32_t GAimCameraOpFixedSettings_t::GetClavicleRightJointIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nClavicleRightJointIndex");
}
void GAimCameraOpFixedSettings_t::SetClavicleRightJointIndex(int32_t value) {
    SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nClavicleRightJointIndex", true, value);
}
int32_t GAimCameraOpFixedSettings_t::GetDepenetrationJointIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "AimCameraOpFixedSettings_t", "m_nDepenetrationJointIndex");
}
void GAimCameraOpFixedSettings_t::SetDepenetrationJointIndex(int32_t value) {
    SetSchemaValue(m_ptr, "AimCameraOpFixedSettings_t", "m_nDepenetrationJointIndex", true, value);
}
std::vector<int32> GAimCameraOpFixedSettings_t::GetPropJoints() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "AimCameraOpFixedSettings_t", "m_propJoints"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAimCameraOpFixedSettings_t::SetPropJoints(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "AimCameraOpFixedSettings_t", "m_propJoints", true, value);
}
std::string GAimCameraOpFixedSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAimCameraOpFixedSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAimCameraOpFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAimCameraOpFixedSettings_t>("AimCameraOpFixedSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ChainIndex", &GAimCameraOpFixedSettings_t::GetChainIndex, &GAimCameraOpFixedSettings_t::SetChainIndex)
        .addProperty("CameraJointIndex", &GAimCameraOpFixedSettings_t::GetCameraJointIndex, &GAimCameraOpFixedSettings_t::SetCameraJointIndex)
        .addProperty("PelvisJointIndex", &GAimCameraOpFixedSettings_t::GetPelvisJointIndex, &GAimCameraOpFixedSettings_t::SetPelvisJointIndex)
        .addProperty("ClavicleLeftJointIndex", &GAimCameraOpFixedSettings_t::GetClavicleLeftJointIndex, &GAimCameraOpFixedSettings_t::SetClavicleLeftJointIndex)
        .addProperty("ClavicleRightJointIndex", &GAimCameraOpFixedSettings_t::GetClavicleRightJointIndex, &GAimCameraOpFixedSettings_t::SetClavicleRightJointIndex)
        .addProperty("DepenetrationJointIndex", &GAimCameraOpFixedSettings_t::GetDepenetrationJointIndex, &GAimCameraOpFixedSettings_t::SetDepenetrationJointIndex)
        .addProperty("PropJoints", &GAimCameraOpFixedSettings_t::GetPropJoints, &GAimCameraOpFixedSettings_t::SetPropJoints)
        .addFunction("ToPtr", &GAimCameraOpFixedSettings_t::ToPtr)
        .addFunction("IsValid", &GAimCameraOpFixedSettings_t::IsValid)
        .endClass();
}