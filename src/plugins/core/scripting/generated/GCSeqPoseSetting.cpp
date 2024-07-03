#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqPoseSetting::GCSeqPoseSetting(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqPoseSetting::GCSeqPoseSetting(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCSeqPoseSetting::GetPoseParameter() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSeqPoseSetting", "m_sPoseParameter");
}
void GCSeqPoseSetting::SetPoseParameter(CBufferString value) {
    SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_sPoseParameter", false, value);
}
CBufferString GCSeqPoseSetting::GetAttachment() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSeqPoseSetting", "m_sAttachment");
}
void GCSeqPoseSetting::SetAttachment(CBufferString value) {
    SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_sAttachment", false, value);
}
CBufferString GCSeqPoseSetting::GetReferenceSequence() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSeqPoseSetting", "m_sReferenceSequence");
}
void GCSeqPoseSetting::SetReferenceSequence(CBufferString value) {
    SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_sReferenceSequence", false, value);
}
float GCSeqPoseSetting::GetValue() const {
    return GetSchemaValue<float>(m_ptr, "CSeqPoseSetting", "m_flValue");
}
void GCSeqPoseSetting::SetValue(float value) {
    SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_flValue", false, value);
}
bool GCSeqPoseSetting::GetX() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqPoseSetting", "m_bX");
}
void GCSeqPoseSetting::SetX(bool value) {
    SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_bX", false, value);
}
bool GCSeqPoseSetting::GetY() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqPoseSetting", "m_bY");
}
void GCSeqPoseSetting::SetY(bool value) {
    SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_bY", false, value);
}
bool GCSeqPoseSetting::GetZ() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqPoseSetting", "m_bZ");
}
void GCSeqPoseSetting::SetZ(bool value) {
    SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_bZ", false, value);
}
int32_t GCSeqPoseSetting::GetType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSeqPoseSetting", "m_eType");
}
void GCSeqPoseSetting::SetType(int32_t value) {
    SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_eType", false, value);
}
std::string GCSeqPoseSetting::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqPoseSetting::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqPoseSetting(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqPoseSetting>("CSeqPoseSetting")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PoseParameter", &GCSeqPoseSetting::GetPoseParameter, &GCSeqPoseSetting::SetPoseParameter)
        .addProperty("Attachment", &GCSeqPoseSetting::GetAttachment, &GCSeqPoseSetting::SetAttachment)
        .addProperty("ReferenceSequence", &GCSeqPoseSetting::GetReferenceSequence, &GCSeqPoseSetting::SetReferenceSequence)
        .addProperty("Value", &GCSeqPoseSetting::GetValue, &GCSeqPoseSetting::SetValue)
        .addProperty("X", &GCSeqPoseSetting::GetX, &GCSeqPoseSetting::SetX)
        .addProperty("Y", &GCSeqPoseSetting::GetY, &GCSeqPoseSetting::SetY)
        .addProperty("Z", &GCSeqPoseSetting::GetZ, &GCSeqPoseSetting::SetZ)
        .addProperty("Type", &GCSeqPoseSetting::GetType, &GCSeqPoseSetting::SetType)
        .addFunction("ToPtr", &GCSeqPoseSetting::ToPtr)
        .addFunction("IsValid", &GCSeqPoseSetting::IsValid)
        .endClass();
}