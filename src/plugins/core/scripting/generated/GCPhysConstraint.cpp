#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysConstraint::GCPhysConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysConstraint::GCPhysConstraint(void *ptr) {
    m_ptr = ptr;
}
std::string GCPhysConstraint::GetNameAttach1() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysConstraint", "m_nameAttach1").String();
}
void GCPhysConstraint::SetNameAttach1(std::string value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_nameAttach1", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPhysConstraint::GetNameAttach2() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysConstraint", "m_nameAttach2").String();
}
void GCPhysConstraint::SetNameAttach2(std::string value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_nameAttach2", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCPhysConstraint::GetAttach1() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPhysConstraint", "m_hAttach1"));
    return value;
}
void GCPhysConstraint::SetAttach1(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Attach1' is not possible.\n");
}
GCBaseEntity GCPhysConstraint::GetAttach2() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPhysConstraint", "m_hAttach2"));
    return value;
}
void GCPhysConstraint::SetAttach2(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Attach2' is not possible.\n");
}
std::string GCPhysConstraint::GetNameAttachment1() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysConstraint", "m_nameAttachment1").String();
}
void GCPhysConstraint::SetNameAttachment1(std::string value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_nameAttachment1", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPhysConstraint::GetNameAttachment2() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysConstraint", "m_nameAttachment2").String();
}
void GCPhysConstraint::SetNameAttachment2(std::string value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_nameAttachment2", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCPhysConstraint::GetBreakSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPhysConstraint", "m_breakSound").String();
}
void GCPhysConstraint::SetBreakSound(std::string value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_breakSound", false, CUtlSymbolLarge(value.c_str()));
}
float GCPhysConstraint::GetForceLimit() const {
    return GetSchemaValue<float>(m_ptr, "CPhysConstraint", "m_forceLimit");
}
void GCPhysConstraint::SetForceLimit(float value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_forceLimit", false, value);
}
float GCPhysConstraint::GetTorqueLimit() const {
    return GetSchemaValue<float>(m_ptr, "CPhysConstraint", "m_torqueLimit");
}
void GCPhysConstraint::SetTorqueLimit(float value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_torqueLimit", false, value);
}
uint32_t GCPhysConstraint::GetTeleportTick() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPhysConstraint", "m_teleportTick");
}
void GCPhysConstraint::SetTeleportTick(uint32_t value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_teleportTick", false, value);
}
float GCPhysConstraint::GetMinTeleportDistance() const {
    return GetSchemaValue<float>(m_ptr, "CPhysConstraint", "m_minTeleportDistance");
}
void GCPhysConstraint::SetMinTeleportDistance(float value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_minTeleportDistance", false, value);
}
bool GCPhysConstraint::GetSnapObjectPositions() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysConstraint", "m_bSnapObjectPositions");
}
void GCPhysConstraint::SetSnapObjectPositions(bool value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_bSnapObjectPositions", false, value);
}
GCEntityIOOutput GCPhysConstraint::GetOnBreak() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysConstraint", "m_OnBreak"));
    return value;
}
void GCPhysConstraint::SetOnBreak(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysConstraint", "m_OnBreak", false, value);
}
std::string GCPhysConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCPhysConstraint::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCPhysConstraint::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysConstraint>("CPhysConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NameAttach1", &GCPhysConstraint::GetNameAttach1, &GCPhysConstraint::SetNameAttach1)
        .addProperty("NameAttach2", &GCPhysConstraint::GetNameAttach2, &GCPhysConstraint::SetNameAttach2)
        .addProperty("Attach1", &GCPhysConstraint::GetAttach1, &GCPhysConstraint::SetAttach1)
        .addProperty("Attach2", &GCPhysConstraint::GetAttach2, &GCPhysConstraint::SetAttach2)
        .addProperty("NameAttachment1", &GCPhysConstraint::GetNameAttachment1, &GCPhysConstraint::SetNameAttachment1)
        .addProperty("NameAttachment2", &GCPhysConstraint::GetNameAttachment2, &GCPhysConstraint::SetNameAttachment2)
        .addProperty("BreakSound", &GCPhysConstraint::GetBreakSound, &GCPhysConstraint::SetBreakSound)
        .addProperty("ForceLimit", &GCPhysConstraint::GetForceLimit, &GCPhysConstraint::SetForceLimit)
        .addProperty("TorqueLimit", &GCPhysConstraint::GetTorqueLimit, &GCPhysConstraint::SetTorqueLimit)
        .addProperty("TeleportTick", &GCPhysConstraint::GetTeleportTick, &GCPhysConstraint::SetTeleportTick)
        .addProperty("MinTeleportDistance", &GCPhysConstraint::GetMinTeleportDistance, &GCPhysConstraint::SetMinTeleportDistance)
        .addProperty("SnapObjectPositions", &GCPhysConstraint::GetSnapObjectPositions, &GCPhysConstraint::SetSnapObjectPositions)
        .addProperty("OnBreak", &GCPhysConstraint::GetOnBreak, &GCPhysConstraint::SetOnBreak)
        .addProperty("Parent", &GCPhysConstraint::GetParent, &GCPhysConstraint::SetParent)
        .addFunction("ToPtr", &GCPhysConstraint::ToPtr)
        .addFunction("IsValid", &GCPhysConstraint::IsValid)
        .endClass();
}