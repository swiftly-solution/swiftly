#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundOpvarSetEntity::GCSoundOpvarSetEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundOpvarSetEntity::GCSoundOpvarSetEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCSoundOpvarSetEntity::GetStackName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetEntity", "m_iszStackName").String();
}
void GCSoundOpvarSetEntity::SetStackName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_iszStackName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSoundOpvarSetEntity::GetOperatorName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetEntity", "m_iszOperatorName").String();
}
void GCSoundOpvarSetEntity::SetOperatorName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_iszOperatorName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSoundOpvarSetEntity::GetOpvarName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetEntity", "m_iszOpvarName").String();
}
void GCSoundOpvarSetEntity::SetOpvarName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_iszOpvarName", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCSoundOpvarSetEntity::GetOpvarType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetEntity", "m_nOpvarType");
}
void GCSoundOpvarSetEntity::SetOpvarType(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_nOpvarType", false, value);
}
int32_t GCSoundOpvarSetEntity::GetOpvarIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetEntity", "m_nOpvarIndex");
}
void GCSoundOpvarSetEntity::SetOpvarIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_nOpvarIndex", false, value);
}
float GCSoundOpvarSetEntity::GetOpvarValue() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetEntity", "m_flOpvarValue");
}
void GCSoundOpvarSetEntity::SetOpvarValue(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_flOpvarValue", false, value);
}
std::string GCSoundOpvarSetEntity::GetOpvarValueString() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetEntity", "m_OpvarValueString").String();
}
void GCSoundOpvarSetEntity::SetOpvarValueString(std::string value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_OpvarValueString", false, CUtlSymbolLarge(value.c_str()));
}
bool GCSoundOpvarSetEntity::GetSetOnSpawn() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundOpvarSetEntity", "m_bSetOnSpawn");
}
void GCSoundOpvarSetEntity::SetSetOnSpawn(bool value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_bSetOnSpawn", false, value);
}
std::string GCSoundOpvarSetEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundOpvarSetEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCSoundOpvarSetEntity::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCSoundOpvarSetEntity::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundOpvarSetEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetEntity>("CSoundOpvarSetEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StackName", &GCSoundOpvarSetEntity::GetStackName, &GCSoundOpvarSetEntity::SetStackName)
        .addProperty("OperatorName", &GCSoundOpvarSetEntity::GetOperatorName, &GCSoundOpvarSetEntity::SetOperatorName)
        .addProperty("OpvarName", &GCSoundOpvarSetEntity::GetOpvarName, &GCSoundOpvarSetEntity::SetOpvarName)
        .addProperty("OpvarType", &GCSoundOpvarSetEntity::GetOpvarType, &GCSoundOpvarSetEntity::SetOpvarType)
        .addProperty("OpvarIndex", &GCSoundOpvarSetEntity::GetOpvarIndex, &GCSoundOpvarSetEntity::SetOpvarIndex)
        .addProperty("OpvarValue", &GCSoundOpvarSetEntity::GetOpvarValue, &GCSoundOpvarSetEntity::SetOpvarValue)
        .addProperty("OpvarValueString", &GCSoundOpvarSetEntity::GetOpvarValueString, &GCSoundOpvarSetEntity::SetOpvarValueString)
        .addProperty("SetOnSpawn", &GCSoundOpvarSetEntity::GetSetOnSpawn, &GCSoundOpvarSetEntity::SetSetOnSpawn)
        .addProperty("Parent", &GCSoundOpvarSetEntity::GetParent, &GCSoundOpvarSetEntity::SetParent)
        .addFunction("ToPtr", &GCSoundOpvarSetEntity::ToPtr)
        .addFunction("IsValid", &GCSoundOpvarSetEntity::IsValid)
        .endClass();
}