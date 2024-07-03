#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicMeasureMovement::GCLogicMeasureMovement(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicMeasureMovement::GCLogicMeasureMovement(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicMeasureMovement::GetStrMeasureTarget() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicMeasureMovement", "m_strMeasureTarget").String();
}
void GCLogicMeasureMovement::SetStrMeasureTarget(std::string value) {
    SetSchemaValue(m_ptr, "CLogicMeasureMovement", "m_strMeasureTarget", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCLogicMeasureMovement::GetStrMeasureReference() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicMeasureMovement", "m_strMeasureReference").String();
}
void GCLogicMeasureMovement::SetStrMeasureReference(std::string value) {
    SetSchemaValue(m_ptr, "CLogicMeasureMovement", "m_strMeasureReference", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCLogicMeasureMovement::GetStrTargetReference() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicMeasureMovement", "m_strTargetReference").String();
}
void GCLogicMeasureMovement::SetStrTargetReference(std::string value) {
    SetSchemaValue(m_ptr, "CLogicMeasureMovement", "m_strTargetReference", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCLogicMeasureMovement::GetMeasureTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CLogicMeasureMovement", "m_hMeasureTarget"));
    return value;
}
void GCLogicMeasureMovement::SetMeasureTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'MeasureTarget' is not possible.\n");
}
GCBaseEntity GCLogicMeasureMovement::GetMeasureReference() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CLogicMeasureMovement", "m_hMeasureReference"));
    return value;
}
void GCLogicMeasureMovement::SetMeasureReference(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'MeasureReference' is not possible.\n");
}
GCBaseEntity GCLogicMeasureMovement::GetTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CLogicMeasureMovement", "m_hTarget"));
    return value;
}
void GCLogicMeasureMovement::SetTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target' is not possible.\n");
}
GCBaseEntity GCLogicMeasureMovement::GetTargetReference() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CLogicMeasureMovement", "m_hTargetReference"));
    return value;
}
void GCLogicMeasureMovement::SetTargetReference(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetReference' is not possible.\n");
}
float GCLogicMeasureMovement::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CLogicMeasureMovement", "m_flScale");
}
void GCLogicMeasureMovement::SetScale(float value) {
    SetSchemaValue(m_ptr, "CLogicMeasureMovement", "m_flScale", false, value);
}
int32_t GCLogicMeasureMovement::GetMeasureType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicMeasureMovement", "m_nMeasureType");
}
void GCLogicMeasureMovement::SetMeasureType(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicMeasureMovement", "m_nMeasureType", false, value);
}
std::string GCLogicMeasureMovement::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicMeasureMovement::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicMeasureMovement::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicMeasureMovement::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicMeasureMovement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicMeasureMovement>("CLogicMeasureMovement")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StrMeasureTarget", &GCLogicMeasureMovement::GetStrMeasureTarget, &GCLogicMeasureMovement::SetStrMeasureTarget)
        .addProperty("StrMeasureReference", &GCLogicMeasureMovement::GetStrMeasureReference, &GCLogicMeasureMovement::SetStrMeasureReference)
        .addProperty("StrTargetReference", &GCLogicMeasureMovement::GetStrTargetReference, &GCLogicMeasureMovement::SetStrTargetReference)
        .addProperty("MeasureTarget", &GCLogicMeasureMovement::GetMeasureTarget, &GCLogicMeasureMovement::SetMeasureTarget)
        .addProperty("MeasureReference", &GCLogicMeasureMovement::GetMeasureReference, &GCLogicMeasureMovement::SetMeasureReference)
        .addProperty("Target", &GCLogicMeasureMovement::GetTarget, &GCLogicMeasureMovement::SetTarget)
        .addProperty("TargetReference", &GCLogicMeasureMovement::GetTargetReference, &GCLogicMeasureMovement::SetTargetReference)
        .addProperty("Scale", &GCLogicMeasureMovement::GetScale, &GCLogicMeasureMovement::SetScale)
        .addProperty("MeasureType", &GCLogicMeasureMovement::GetMeasureType, &GCLogicMeasureMovement::SetMeasureType)
        .addProperty("Parent", &GCLogicMeasureMovement::GetParent, &GCLogicMeasureMovement::SetParent)
        .addFunction("ToPtr", &GCLogicMeasureMovement::ToPtr)
        .addFunction("IsValid", &GCLogicMeasureMovement::IsValid)
        .endClass();
}