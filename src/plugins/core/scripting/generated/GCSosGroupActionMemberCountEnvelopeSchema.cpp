#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosGroupActionMemberCountEnvelopeSchema::GCSosGroupActionMemberCountEnvelopeSchema(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosGroupActionMemberCountEnvelopeSchema::GCSosGroupActionMemberCountEnvelopeSchema(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSosGroupActionMemberCountEnvelopeSchema::GetBaseCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_nBaseCount");
}
void GCSosGroupActionMemberCountEnvelopeSchema::SetBaseCount(int32_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_nBaseCount", false, value);
}
int32_t GCSosGroupActionMemberCountEnvelopeSchema::GetTargetCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_nTargetCount");
}
void GCSosGroupActionMemberCountEnvelopeSchema::SetTargetCount(int32_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_nTargetCount", false, value);
}
float GCSosGroupActionMemberCountEnvelopeSchema::GetBaseValue() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flBaseValue");
}
void GCSosGroupActionMemberCountEnvelopeSchema::SetBaseValue(float value) {
    SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flBaseValue", false, value);
}
float GCSosGroupActionMemberCountEnvelopeSchema::GetTargetValue() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flTargetValue");
}
void GCSosGroupActionMemberCountEnvelopeSchema::SetTargetValue(float value) {
    SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flTargetValue", false, value);
}
float GCSosGroupActionMemberCountEnvelopeSchema::GetAttack() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flAttack");
}
void GCSosGroupActionMemberCountEnvelopeSchema::SetAttack(float value) {
    SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flAttack", false, value);
}
float GCSosGroupActionMemberCountEnvelopeSchema::GetDecay() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flDecay");
}
void GCSosGroupActionMemberCountEnvelopeSchema::SetDecay(float value) {
    SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_flDecay", false, value);
}
std::string GCSosGroupActionMemberCountEnvelopeSchema::GetResultVarName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_resultVarName").Get();
}
void GCSosGroupActionMemberCountEnvelopeSchema::SetResultVarName(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_resultVarName", false, CUtlString(value.c_str()));
}
bool GCSosGroupActionMemberCountEnvelopeSchema::GetSaveToGroup() const {
    return GetSchemaValue<bool>(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_bSaveToGroup");
}
void GCSosGroupActionMemberCountEnvelopeSchema::SetSaveToGroup(bool value) {
    SetSchemaValue(m_ptr, "CSosGroupActionMemberCountEnvelopeSchema", "m_bSaveToGroup", false, value);
}
std::string GCSosGroupActionMemberCountEnvelopeSchema::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosGroupActionMemberCountEnvelopeSchema::IsValid() {
    return (m_ptr != nullptr);
}
GCSosGroupActionSchema GCSosGroupActionMemberCountEnvelopeSchema::GetParent() const {
    GCSosGroupActionSchema value(m_ptr);
    return value;
}
void GCSosGroupActionMemberCountEnvelopeSchema::SetParent(GCSosGroupActionSchema value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSosGroupActionMemberCountEnvelopeSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionMemberCountEnvelopeSchema>("CSosGroupActionMemberCountEnvelopeSchema")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BaseCount", &GCSosGroupActionMemberCountEnvelopeSchema::GetBaseCount, &GCSosGroupActionMemberCountEnvelopeSchema::SetBaseCount)
        .addProperty("TargetCount", &GCSosGroupActionMemberCountEnvelopeSchema::GetTargetCount, &GCSosGroupActionMemberCountEnvelopeSchema::SetTargetCount)
        .addProperty("BaseValue", &GCSosGroupActionMemberCountEnvelopeSchema::GetBaseValue, &GCSosGroupActionMemberCountEnvelopeSchema::SetBaseValue)
        .addProperty("TargetValue", &GCSosGroupActionMemberCountEnvelopeSchema::GetTargetValue, &GCSosGroupActionMemberCountEnvelopeSchema::SetTargetValue)
        .addProperty("Attack", &GCSosGroupActionMemberCountEnvelopeSchema::GetAttack, &GCSosGroupActionMemberCountEnvelopeSchema::SetAttack)
        .addProperty("Decay", &GCSosGroupActionMemberCountEnvelopeSchema::GetDecay, &GCSosGroupActionMemberCountEnvelopeSchema::SetDecay)
        .addProperty("ResultVarName", &GCSosGroupActionMemberCountEnvelopeSchema::GetResultVarName, &GCSosGroupActionMemberCountEnvelopeSchema::SetResultVarName)
        .addProperty("SaveToGroup", &GCSosGroupActionMemberCountEnvelopeSchema::GetSaveToGroup, &GCSosGroupActionMemberCountEnvelopeSchema::SetSaveToGroup)
        .addProperty("Parent", &GCSosGroupActionMemberCountEnvelopeSchema::GetParent, &GCSosGroupActionMemberCountEnvelopeSchema::SetParent)
        .addFunction("ToPtr", &GCSosGroupActionMemberCountEnvelopeSchema::ToPtr)
        .addFunction("IsValid", &GCSosGroupActionMemberCountEnvelopeSchema::IsValid)
        .endClass();
}