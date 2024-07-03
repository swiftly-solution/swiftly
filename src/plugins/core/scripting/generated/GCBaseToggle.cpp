#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseToggle::GCBaseToggle(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseToggle::GCBaseToggle(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCBaseToggle::GetToggle_state() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseToggle", "m_toggle_state");
}
void GCBaseToggle::SetToggle_state(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_toggle_state", false, value);
}
float GCBaseToggle::GetMoveDistance() const {
    return GetSchemaValue<float>(m_ptr, "CBaseToggle", "m_flMoveDistance");
}
void GCBaseToggle::SetMoveDistance(float value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_flMoveDistance", false, value);
}
float GCBaseToggle::GetWait() const {
    return GetSchemaValue<float>(m_ptr, "CBaseToggle", "m_flWait");
}
void GCBaseToggle::SetWait(float value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_flWait", false, value);
}
float GCBaseToggle::GetLip() const {
    return GetSchemaValue<float>(m_ptr, "CBaseToggle", "m_flLip");
}
void GCBaseToggle::SetLip(float value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_flLip", false, value);
}
bool GCBaseToggle::GetAlwaysFireBlockedOutputs() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseToggle", "m_bAlwaysFireBlockedOutputs");
}
void GCBaseToggle::SetAlwaysFireBlockedOutputs(bool value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_bAlwaysFireBlockedOutputs", false, value);
}
Vector GCBaseToggle::GetPosition1() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseToggle", "m_vecPosition1");
}
void GCBaseToggle::SetPosition1(Vector value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_vecPosition1", false, value);
}
Vector GCBaseToggle::GetPosition2() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseToggle", "m_vecPosition2");
}
void GCBaseToggle::SetPosition2(Vector value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_vecPosition2", false, value);
}
QAngle GCBaseToggle::GetMoveAng() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBaseToggle", "m_vecMoveAng");
}
void GCBaseToggle::SetMoveAng(QAngle value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_vecMoveAng", false, value);
}
QAngle GCBaseToggle::GetAngle1() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBaseToggle", "m_vecAngle1");
}
void GCBaseToggle::SetAngle1(QAngle value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_vecAngle1", false, value);
}
QAngle GCBaseToggle::GetAngle2() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBaseToggle", "m_vecAngle2");
}
void GCBaseToggle::SetAngle2(QAngle value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_vecAngle2", false, value);
}
float GCBaseToggle::GetHeight() const {
    return GetSchemaValue<float>(m_ptr, "CBaseToggle", "m_flHeight");
}
void GCBaseToggle::SetHeight(float value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_flHeight", false, value);
}
GCBaseEntity GCBaseToggle::GetActivator() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseToggle", "m_hActivator"));
    return value;
}
void GCBaseToggle::SetActivator(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n");
}
Vector GCBaseToggle::GetFinalDest() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseToggle", "m_vecFinalDest");
}
void GCBaseToggle::SetFinalDest(Vector value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_vecFinalDest", false, value);
}
QAngle GCBaseToggle::GetFinalAngle() const {
    return GetSchemaValue<QAngle>(m_ptr, "CBaseToggle", "m_vecFinalAngle");
}
void GCBaseToggle::SetFinalAngle(QAngle value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_vecFinalAngle", false, value);
}
int32_t GCBaseToggle::GetMovementType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseToggle", "m_movementType");
}
void GCBaseToggle::SetMovementType(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_movementType", false, value);
}
std::string GCBaseToggle::GetMaster() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBaseToggle", "m_sMaster").String();
}
void GCBaseToggle::SetMaster(std::string value) {
    SetSchemaValue(m_ptr, "CBaseToggle", "m_sMaster", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCBaseToggle::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseToggle::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCBaseToggle::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCBaseToggle::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseToggle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseToggle>("CBaseToggle")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Toggle_state", &GCBaseToggle::GetToggle_state, &GCBaseToggle::SetToggle_state)
        .addProperty("MoveDistance", &GCBaseToggle::GetMoveDistance, &GCBaseToggle::SetMoveDistance)
        .addProperty("Wait", &GCBaseToggle::GetWait, &GCBaseToggle::SetWait)
        .addProperty("Lip", &GCBaseToggle::GetLip, &GCBaseToggle::SetLip)
        .addProperty("AlwaysFireBlockedOutputs", &GCBaseToggle::GetAlwaysFireBlockedOutputs, &GCBaseToggle::SetAlwaysFireBlockedOutputs)
        .addProperty("Position1", &GCBaseToggle::GetPosition1, &GCBaseToggle::SetPosition1)
        .addProperty("Position2", &GCBaseToggle::GetPosition2, &GCBaseToggle::SetPosition2)
        .addProperty("MoveAng", &GCBaseToggle::GetMoveAng, &GCBaseToggle::SetMoveAng)
        .addProperty("Angle1", &GCBaseToggle::GetAngle1, &GCBaseToggle::SetAngle1)
        .addProperty("Angle2", &GCBaseToggle::GetAngle2, &GCBaseToggle::SetAngle2)
        .addProperty("Height", &GCBaseToggle::GetHeight, &GCBaseToggle::SetHeight)
        .addProperty("Activator", &GCBaseToggle::GetActivator, &GCBaseToggle::SetActivator)
        .addProperty("FinalDest", &GCBaseToggle::GetFinalDest, &GCBaseToggle::SetFinalDest)
        .addProperty("FinalAngle", &GCBaseToggle::GetFinalAngle, &GCBaseToggle::SetFinalAngle)
        .addProperty("MovementType", &GCBaseToggle::GetMovementType, &GCBaseToggle::SetMovementType)
        .addProperty("Master", &GCBaseToggle::GetMaster, &GCBaseToggle::SetMaster)
        .addProperty("Parent", &GCBaseToggle::GetParent, &GCBaseToggle::SetParent)
        .addFunction("ToPtr", &GCBaseToggle::ToPtr)
        .addFunction("IsValid", &GCBaseToggle::IsValid)
        .endClass();
}