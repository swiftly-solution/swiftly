#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundOpvarSetPointBase::GCSoundOpvarSetPointBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundOpvarSetPointBase::GCSoundOpvarSetPointBase(void *ptr) {
    m_ptr = ptr;
}
bool GCSoundOpvarSetPointBase::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundOpvarSetPointBase", "m_bDisabled");
}
void GCSoundOpvarSetPointBase::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_bDisabled", false, value);
}
GCEntityInstance GCSoundOpvarSetPointBase::GetSource() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CSoundOpvarSetPointBase", "m_hSource"));
    return value;
}
void GCSoundOpvarSetPointBase::SetSource(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Source' is not possible.\n");
}
std::string GCSoundOpvarSetPointBase::GetSourceEntityName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPointBase", "m_iszSourceEntityName").String();
}
void GCSoundOpvarSetPointBase::SetSourceEntityName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_iszSourceEntityName", false, CUtlSymbolLarge(value.c_str()));
}
Vector GCSoundOpvarSetPointBase::GetLastPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetPointBase", "m_vLastPosition");
}
void GCSoundOpvarSetPointBase::SetLastPosition(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_vLastPosition", false, value);
}
std::string GCSoundOpvarSetPointBase::GetStackName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPointBase", "m_iszStackName").String();
}
void GCSoundOpvarSetPointBase::SetStackName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_iszStackName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSoundOpvarSetPointBase::GetOperatorName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPointBase", "m_iszOperatorName").String();
}
void GCSoundOpvarSetPointBase::SetOperatorName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_iszOperatorName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSoundOpvarSetPointBase::GetOpvarName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPointBase", "m_iszOpvarName").String();
}
void GCSoundOpvarSetPointBase::SetOpvarName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_iszOpvarName", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCSoundOpvarSetPointBase::GetOpvarIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetPointBase", "m_iOpvarIndex");
}
void GCSoundOpvarSetPointBase::SetOpvarIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_iOpvarIndex", false, value);
}
bool GCSoundOpvarSetPointBase::GetUseAutoCompare() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundOpvarSetPointBase", "m_bUseAutoCompare");
}
void GCSoundOpvarSetPointBase::SetUseAutoCompare(bool value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_bUseAutoCompare", false, value);
}
std::string GCSoundOpvarSetPointBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundOpvarSetPointBase::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCSoundOpvarSetPointBase::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCSoundOpvarSetPointBase::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundOpvarSetPointBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetPointBase>("CSoundOpvarSetPointBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCSoundOpvarSetPointBase::GetDisabled, &GCSoundOpvarSetPointBase::SetDisabled)
        .addProperty("Source", &GCSoundOpvarSetPointBase::GetSource, &GCSoundOpvarSetPointBase::SetSource)
        .addProperty("SourceEntityName", &GCSoundOpvarSetPointBase::GetSourceEntityName, &GCSoundOpvarSetPointBase::SetSourceEntityName)
        .addProperty("LastPosition", &GCSoundOpvarSetPointBase::GetLastPosition, &GCSoundOpvarSetPointBase::SetLastPosition)
        .addProperty("StackName", &GCSoundOpvarSetPointBase::GetStackName, &GCSoundOpvarSetPointBase::SetStackName)
        .addProperty("OperatorName", &GCSoundOpvarSetPointBase::GetOperatorName, &GCSoundOpvarSetPointBase::SetOperatorName)
        .addProperty("OpvarName", &GCSoundOpvarSetPointBase::GetOpvarName, &GCSoundOpvarSetPointBase::SetOpvarName)
        .addProperty("OpvarIndex", &GCSoundOpvarSetPointBase::GetOpvarIndex, &GCSoundOpvarSetPointBase::SetOpvarIndex)
        .addProperty("UseAutoCompare", &GCSoundOpvarSetPointBase::GetUseAutoCompare, &GCSoundOpvarSetPointBase::SetUseAutoCompare)
        .addProperty("Parent", &GCSoundOpvarSetPointBase::GetParent, &GCSoundOpvarSetPointBase::SetParent)
        .addFunction("ToPtr", &GCSoundOpvarSetPointBase::ToPtr)
        .addFunction("IsValid", &GCSoundOpvarSetPointBase::IsValid)
        .endClass();
}