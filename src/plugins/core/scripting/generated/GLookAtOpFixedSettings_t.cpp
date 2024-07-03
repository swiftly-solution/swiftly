#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GLookAtOpFixedSettings_t::GLookAtOpFixedSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GLookAtOpFixedSettings_t::GLookAtOpFixedSettings_t(void *ptr) {
    m_ptr = ptr;
}
GCAnimAttachment GLookAtOpFixedSettings_t::GetAttachment() const {
    GCAnimAttachment value(GetSchemaPtr(m_ptr, "LookAtOpFixedSettings_t", "m_attachment"));
    return value;
}
void GLookAtOpFixedSettings_t::SetAttachment(GCAnimAttachment value) {
    SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_attachment", true, value);
}
GCAnimInputDamping GLookAtOpFixedSettings_t::GetDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "LookAtOpFixedSettings_t", "m_damping"));
    return value;
}
void GLookAtOpFixedSettings_t::SetDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_damping", true, value);
}
std::vector<GLookAtBone_t> GLookAtOpFixedSettings_t::GetBones() const {
    CUtlVector<GLookAtBone_t>* vec = GetSchemaValue<CUtlVector<GLookAtBone_t>*>(m_ptr, "LookAtOpFixedSettings_t", "m_bones"); std::vector<GLookAtBone_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GLookAtOpFixedSettings_t::SetBones(std::vector<GLookAtBone_t> value) {
    SetSchemaValueCUtlVector<GLookAtBone_t>(m_ptr, "LookAtOpFixedSettings_t", "m_bones", true, value);
}
float GLookAtOpFixedSettings_t::GetYawLimit() const {
    return GetSchemaValue<float>(m_ptr, "LookAtOpFixedSettings_t", "m_flYawLimit");
}
void GLookAtOpFixedSettings_t::SetYawLimit(float value) {
    SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_flYawLimit", true, value);
}
float GLookAtOpFixedSettings_t::GetPitchLimit() const {
    return GetSchemaValue<float>(m_ptr, "LookAtOpFixedSettings_t", "m_flPitchLimit");
}
void GLookAtOpFixedSettings_t::SetPitchLimit(float value) {
    SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_flPitchLimit", true, value);
}
float GLookAtOpFixedSettings_t::GetHysteresisInnerAngle() const {
    return GetSchemaValue<float>(m_ptr, "LookAtOpFixedSettings_t", "m_flHysteresisInnerAngle");
}
void GLookAtOpFixedSettings_t::SetHysteresisInnerAngle(float value) {
    SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_flHysteresisInnerAngle", true, value);
}
float GLookAtOpFixedSettings_t::GetHysteresisOuterAngle() const {
    return GetSchemaValue<float>(m_ptr, "LookAtOpFixedSettings_t", "m_flHysteresisOuterAngle");
}
void GLookAtOpFixedSettings_t::SetHysteresisOuterAngle(float value) {
    SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_flHysteresisOuterAngle", true, value);
}
bool GLookAtOpFixedSettings_t::GetRotateYawForward() const {
    return GetSchemaValue<bool>(m_ptr, "LookAtOpFixedSettings_t", "m_bRotateYawForward");
}
void GLookAtOpFixedSettings_t::SetRotateYawForward(bool value) {
    SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_bRotateYawForward", true, value);
}
bool GLookAtOpFixedSettings_t::GetMaintainUpDirection() const {
    return GetSchemaValue<bool>(m_ptr, "LookAtOpFixedSettings_t", "m_bMaintainUpDirection");
}
void GLookAtOpFixedSettings_t::SetMaintainUpDirection(bool value) {
    SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_bMaintainUpDirection", true, value);
}
bool GLookAtOpFixedSettings_t::GetTargetIsPosition() const {
    return GetSchemaValue<bool>(m_ptr, "LookAtOpFixedSettings_t", "m_bTargetIsPosition");
}
void GLookAtOpFixedSettings_t::SetTargetIsPosition(bool value) {
    SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_bTargetIsPosition", true, value);
}
bool GLookAtOpFixedSettings_t::GetUseHysteresis() const {
    return GetSchemaValue<bool>(m_ptr, "LookAtOpFixedSettings_t", "m_bUseHysteresis");
}
void GLookAtOpFixedSettings_t::SetUseHysteresis(bool value) {
    SetSchemaValue(m_ptr, "LookAtOpFixedSettings_t", "m_bUseHysteresis", true, value);
}
std::string GLookAtOpFixedSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GLookAtOpFixedSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassLookAtOpFixedSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GLookAtOpFixedSettings_t>("LookAtOpFixedSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Attachment", &GLookAtOpFixedSettings_t::GetAttachment, &GLookAtOpFixedSettings_t::SetAttachment)
        .addProperty("Damping", &GLookAtOpFixedSettings_t::GetDamping, &GLookAtOpFixedSettings_t::SetDamping)
        .addProperty("Bones", &GLookAtOpFixedSettings_t::GetBones, &GLookAtOpFixedSettings_t::SetBones)
        .addProperty("YawLimit", &GLookAtOpFixedSettings_t::GetYawLimit, &GLookAtOpFixedSettings_t::SetYawLimit)
        .addProperty("PitchLimit", &GLookAtOpFixedSettings_t::GetPitchLimit, &GLookAtOpFixedSettings_t::SetPitchLimit)
        .addProperty("HysteresisInnerAngle", &GLookAtOpFixedSettings_t::GetHysteresisInnerAngle, &GLookAtOpFixedSettings_t::SetHysteresisInnerAngle)
        .addProperty("HysteresisOuterAngle", &GLookAtOpFixedSettings_t::GetHysteresisOuterAngle, &GLookAtOpFixedSettings_t::SetHysteresisOuterAngle)
        .addProperty("RotateYawForward", &GLookAtOpFixedSettings_t::GetRotateYawForward, &GLookAtOpFixedSettings_t::SetRotateYawForward)
        .addProperty("MaintainUpDirection", &GLookAtOpFixedSettings_t::GetMaintainUpDirection, &GLookAtOpFixedSettings_t::SetMaintainUpDirection)
        .addProperty("TargetIsPosition", &GLookAtOpFixedSettings_t::GetTargetIsPosition, &GLookAtOpFixedSettings_t::SetTargetIsPosition)
        .addProperty("UseHysteresis", &GLookAtOpFixedSettings_t::GetUseHysteresis, &GLookAtOpFixedSettings_t::SetUseHysteresis)
        .addFunction("ToPtr", &GLookAtOpFixedSettings_t::ToPtr)
        .addFunction("IsValid", &GLookAtOpFixedSettings_t::IsValid)
        .endClass();
}