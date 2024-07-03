#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBtActionCombatPositioning::GCBtActionCombatPositioning(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBtActionCombatPositioning::GCBtActionCombatPositioning(void *ptr) {
    m_ptr = ptr;
}
std::string GCBtActionCombatPositioning::GetSensorInputKey() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBtActionCombatPositioning", "m_szSensorInputKey").Get();
}
void GCBtActionCombatPositioning::SetSensorInputKey(std::string value) {
    SetSchemaValue(m_ptr, "CBtActionCombatPositioning", "m_szSensorInputKey", false, CUtlString(value.c_str()));
}
std::string GCBtActionCombatPositioning::GetIsAttackingKey() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBtActionCombatPositioning", "m_szIsAttackingKey").Get();
}
void GCBtActionCombatPositioning::SetIsAttackingKey(std::string value) {
    SetSchemaValue(m_ptr, "CBtActionCombatPositioning", "m_szIsAttackingKey", false, CUtlString(value.c_str()));
}
GCountdownTimer GCBtActionCombatPositioning::GetActionTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CBtActionCombatPositioning", "m_ActionTimer"));
    return value;
}
void GCBtActionCombatPositioning::SetActionTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CBtActionCombatPositioning", "m_ActionTimer", false, value);
}
bool GCBtActionCombatPositioning::GetCrouching() const {
    return GetSchemaValue<bool>(m_ptr, "CBtActionCombatPositioning", "m_bCrouching");
}
void GCBtActionCombatPositioning::SetCrouching(bool value) {
    SetSchemaValue(m_ptr, "CBtActionCombatPositioning", "m_bCrouching", false, value);
}
std::string GCBtActionCombatPositioning::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBtActionCombatPositioning::IsValid() {
    return (m_ptr != nullptr);
}
GCBtNode GCBtActionCombatPositioning::GetParent() const {
    GCBtNode value(m_ptr);
    return value;
}
void GCBtActionCombatPositioning::SetParent(GCBtNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBtActionCombatPositioning(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtActionCombatPositioning>("CBtActionCombatPositioning")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SensorInputKey", &GCBtActionCombatPositioning::GetSensorInputKey, &GCBtActionCombatPositioning::SetSensorInputKey)
        .addProperty("IsAttackingKey", &GCBtActionCombatPositioning::GetIsAttackingKey, &GCBtActionCombatPositioning::SetIsAttackingKey)
        .addProperty("ActionTimer", &GCBtActionCombatPositioning::GetActionTimer, &GCBtActionCombatPositioning::SetActionTimer)
        .addProperty("Crouching", &GCBtActionCombatPositioning::GetCrouching, &GCBtActionCombatPositioning::SetCrouching)
        .addProperty("Parent", &GCBtActionCombatPositioning::GetParent, &GCBtActionCombatPositioning::SetParent)
        .addFunction("ToPtr", &GCBtActionCombatPositioning::ToPtr)
        .addFunction("IsValid", &GCBtActionCombatPositioning::IsValid)
        .endClass();
}