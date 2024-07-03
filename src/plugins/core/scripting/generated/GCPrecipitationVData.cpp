#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPrecipitationVData::GCPrecipitationVData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPrecipitationVData::GCPrecipitationVData(void *ptr) {
    m_ptr = ptr;
}
float GCPrecipitationVData::GetInnerDistance() const {
    return GetSchemaValue<float>(m_ptr, "CPrecipitationVData", "m_flInnerDistance");
}
void GCPrecipitationVData::SetInnerDistance(float value) {
    SetSchemaValue(m_ptr, "CPrecipitationVData", "m_flInnerDistance", false, value);
}
uint64_t GCPrecipitationVData::GetAttachType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPrecipitationVData", "m_nAttachType");
}
void GCPrecipitationVData::SetAttachType(uint64_t value) {
    SetSchemaValue(m_ptr, "CPrecipitationVData", "m_nAttachType", false, value);
}
bool GCPrecipitationVData::GetBatchSameVolumeType() const {
    return GetSchemaValue<bool>(m_ptr, "CPrecipitationVData", "m_bBatchSameVolumeType");
}
void GCPrecipitationVData::SetBatchSameVolumeType(bool value) {
    SetSchemaValue(m_ptr, "CPrecipitationVData", "m_bBatchSameVolumeType", false, value);
}
int32_t GCPrecipitationVData::GetRTEnvCP() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPrecipitationVData", "m_nRTEnvCP");
}
void GCPrecipitationVData::SetRTEnvCP(int32_t value) {
    SetSchemaValue(m_ptr, "CPrecipitationVData", "m_nRTEnvCP", false, value);
}
int32_t GCPrecipitationVData::GetRTEnvCPComponent() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPrecipitationVData", "m_nRTEnvCPComponent");
}
void GCPrecipitationVData::SetRTEnvCPComponent(int32_t value) {
    SetSchemaValue(m_ptr, "CPrecipitationVData", "m_nRTEnvCPComponent", false, value);
}
std::string GCPrecipitationVData::GetModifier() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CPrecipitationVData", "m_szModifier").Get();
}
void GCPrecipitationVData::SetModifier(std::string value) {
    SetSchemaValue(m_ptr, "CPrecipitationVData", "m_szModifier", false, CUtlString(value.c_str()));
}
std::string GCPrecipitationVData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPrecipitationVData::IsValid() {
    return (m_ptr != nullptr);
}
GCEntitySubclassVDataBase GCPrecipitationVData::GetParent() const {
    GCEntitySubclassVDataBase value(m_ptr);
    return value;
}
void GCPrecipitationVData::SetParent(GCEntitySubclassVDataBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPrecipitationVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPrecipitationVData>("CPrecipitationVData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InnerDistance", &GCPrecipitationVData::GetInnerDistance, &GCPrecipitationVData::SetInnerDistance)
        .addProperty("AttachType", &GCPrecipitationVData::GetAttachType, &GCPrecipitationVData::SetAttachType)
        .addProperty("BatchSameVolumeType", &GCPrecipitationVData::GetBatchSameVolumeType, &GCPrecipitationVData::SetBatchSameVolumeType)
        .addProperty("RTEnvCP", &GCPrecipitationVData::GetRTEnvCP, &GCPrecipitationVData::SetRTEnvCP)
        .addProperty("RTEnvCPComponent", &GCPrecipitationVData::GetRTEnvCPComponent, &GCPrecipitationVData::SetRTEnvCPComponent)
        .addProperty("Modifier", &GCPrecipitationVData::GetModifier, &GCPrecipitationVData::SetModifier)
        .addProperty("Parent", &GCPrecipitationVData::GetParent, &GCPrecipitationVData::SetParent)
        .addFunction("ToPtr", &GCPrecipitationVData::ToPtr)
        .addFunction("IsValid", &GCPrecipitationVData::IsValid)
        .endClass();
}