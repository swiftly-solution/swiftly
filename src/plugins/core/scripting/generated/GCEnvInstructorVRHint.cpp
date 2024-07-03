#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvInstructorVRHint::GCEnvInstructorVRHint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvInstructorVRHint::GCEnvInstructorVRHint(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvInstructorVRHint::GetName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorVRHint", "m_iszName").String();
}
void GCEnvInstructorVRHint::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iszName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvInstructorVRHint::GetHintTargetEntity() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorVRHint", "m_iszHintTargetEntity").String();
}
void GCEnvInstructorVRHint::SetHintTargetEntity(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iszHintTargetEntity", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCEnvInstructorVRHint::GetTimeout() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorVRHint", "m_iTimeout");
}
void GCEnvInstructorVRHint::SetTimeout(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iTimeout", false, value);
}
std::string GCEnvInstructorVRHint::GetCaption() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorVRHint", "m_iszCaption").String();
}
void GCEnvInstructorVRHint::SetCaption(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iszCaption", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCEnvInstructorVRHint::GetStartSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorVRHint", "m_iszStartSound").String();
}
void GCEnvInstructorVRHint::SetStartSound(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iszStartSound", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCEnvInstructorVRHint::GetLayoutFileType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorVRHint", "m_iLayoutFileType");
}
void GCEnvInstructorVRHint::SetLayoutFileType(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iLayoutFileType", false, value);
}
std::string GCEnvInstructorVRHint::GetCustomLayoutFile() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CEnvInstructorVRHint", "m_iszCustomLayoutFile").String();
}
void GCEnvInstructorVRHint::SetCustomLayoutFile(std::string value) {
    SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iszCustomLayoutFile", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCEnvInstructorVRHint::GetAttachType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvInstructorVRHint", "m_iAttachType");
}
void GCEnvInstructorVRHint::SetAttachType(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_iAttachType", false, value);
}
float GCEnvInstructorVRHint::GetHeightOffset() const {
    return GetSchemaValue<float>(m_ptr, "CEnvInstructorVRHint", "m_flHeightOffset");
}
void GCEnvInstructorVRHint::SetHeightOffset(float value) {
    SetSchemaValue(m_ptr, "CEnvInstructorVRHint", "m_flHeightOffset", false, value);
}
std::string GCEnvInstructorVRHint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvInstructorVRHint::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCEnvInstructorVRHint::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCEnvInstructorVRHint::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvInstructorVRHint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvInstructorVRHint>("CEnvInstructorVRHint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCEnvInstructorVRHint::GetName, &GCEnvInstructorVRHint::SetName)
        .addProperty("HintTargetEntity", &GCEnvInstructorVRHint::GetHintTargetEntity, &GCEnvInstructorVRHint::SetHintTargetEntity)
        .addProperty("Timeout", &GCEnvInstructorVRHint::GetTimeout, &GCEnvInstructorVRHint::SetTimeout)
        .addProperty("Caption", &GCEnvInstructorVRHint::GetCaption, &GCEnvInstructorVRHint::SetCaption)
        .addProperty("StartSound", &GCEnvInstructorVRHint::GetStartSound, &GCEnvInstructorVRHint::SetStartSound)
        .addProperty("LayoutFileType", &GCEnvInstructorVRHint::GetLayoutFileType, &GCEnvInstructorVRHint::SetLayoutFileType)
        .addProperty("CustomLayoutFile", &GCEnvInstructorVRHint::GetCustomLayoutFile, &GCEnvInstructorVRHint::SetCustomLayoutFile)
        .addProperty("AttachType", &GCEnvInstructorVRHint::GetAttachType, &GCEnvInstructorVRHint::SetAttachType)
        .addProperty("HeightOffset", &GCEnvInstructorVRHint::GetHeightOffset, &GCEnvInstructorVRHint::SetHeightOffset)
        .addProperty("Parent", &GCEnvInstructorVRHint::GetParent, &GCEnvInstructorVRHint::SetParent)
        .addFunction("ToPtr", &GCEnvInstructorVRHint::ToPtr)
        .addFunction("IsValid", &GCEnvInstructorVRHint::IsValid)
        .endClass();
}