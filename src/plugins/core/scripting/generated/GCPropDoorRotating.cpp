#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPropDoorRotating::GCPropDoorRotating(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPropDoorRotating::GCPropDoorRotating(void *ptr) {
    m_ptr = ptr;
}
Vector GCPropDoorRotating::GetAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CPropDoorRotating", "m_vecAxis");
}
void GCPropDoorRotating::SetAxis(Vector value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_vecAxis", false, value);
}
float GCPropDoorRotating::GetDistance() const {
    return GetSchemaValue<float>(m_ptr, "CPropDoorRotating", "m_flDistance");
}
void GCPropDoorRotating::SetDistance(float value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_flDistance", false, value);
}
uint64_t GCPropDoorRotating::GetSpawnPosition() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPropDoorRotating", "m_eSpawnPosition");
}
void GCPropDoorRotating::SetSpawnPosition(uint64_t value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_eSpawnPosition", false, value);
}
uint64_t GCPropDoorRotating::GetOpenDirection() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPropDoorRotating", "m_eOpenDirection");
}
void GCPropDoorRotating::SetOpenDirection(uint64_t value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_eOpenDirection", false, value);
}
uint64_t GCPropDoorRotating::GetCurrentOpenDirection() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPropDoorRotating", "m_eCurrentOpenDirection");
}
void GCPropDoorRotating::SetCurrentOpenDirection(uint64_t value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_eCurrentOpenDirection", false, value);
}
float GCPropDoorRotating::GetAjarAngle() const {
    return GetSchemaValue<float>(m_ptr, "CPropDoorRotating", "m_flAjarAngle");
}
void GCPropDoorRotating::SetAjarAngle(float value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_flAjarAngle", false, value);
}
QAngle GCPropDoorRotating::GetRotationAjarDeprecated() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPropDoorRotating", "m_angRotationAjarDeprecated");
}
void GCPropDoorRotating::SetRotationAjarDeprecated(QAngle value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_angRotationAjarDeprecated", false, value);
}
QAngle GCPropDoorRotating::GetRotationClosed() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPropDoorRotating", "m_angRotationClosed");
}
void GCPropDoorRotating::SetRotationClosed(QAngle value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_angRotationClosed", false, value);
}
QAngle GCPropDoorRotating::GetRotationOpenForward() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPropDoorRotating", "m_angRotationOpenForward");
}
void GCPropDoorRotating::SetRotationOpenForward(QAngle value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_angRotationOpenForward", false, value);
}
QAngle GCPropDoorRotating::GetRotationOpenBack() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPropDoorRotating", "m_angRotationOpenBack");
}
void GCPropDoorRotating::SetRotationOpenBack(QAngle value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_angRotationOpenBack", false, value);
}
QAngle GCPropDoorRotating::GetGoal() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPropDoorRotating", "m_angGoal");
}
void GCPropDoorRotating::SetGoal(QAngle value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_angGoal", false, value);
}
Vector GCPropDoorRotating::GetForwardBoundsMin() const {
    return GetSchemaValue<Vector>(m_ptr, "CPropDoorRotating", "m_vecForwardBoundsMin");
}
void GCPropDoorRotating::SetForwardBoundsMin(Vector value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_vecForwardBoundsMin", false, value);
}
Vector GCPropDoorRotating::GetForwardBoundsMax() const {
    return GetSchemaValue<Vector>(m_ptr, "CPropDoorRotating", "m_vecForwardBoundsMax");
}
void GCPropDoorRotating::SetForwardBoundsMax(Vector value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_vecForwardBoundsMax", false, value);
}
Vector GCPropDoorRotating::GetBackBoundsMin() const {
    return GetSchemaValue<Vector>(m_ptr, "CPropDoorRotating", "m_vecBackBoundsMin");
}
void GCPropDoorRotating::SetBackBoundsMin(Vector value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_vecBackBoundsMin", false, value);
}
Vector GCPropDoorRotating::GetBackBoundsMax() const {
    return GetSchemaValue<Vector>(m_ptr, "CPropDoorRotating", "m_vecBackBoundsMax");
}
void GCPropDoorRotating::SetBackBoundsMax(Vector value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_vecBackBoundsMax", false, value);
}
bool GCPropDoorRotating::GetAjarDoorShouldntAlwaysOpen() const {
    return GetSchemaValue<bool>(m_ptr, "CPropDoorRotating", "m_bAjarDoorShouldntAlwaysOpen");
}
void GCPropDoorRotating::SetAjarDoorShouldntAlwaysOpen(bool value) {
    SetSchemaValue(m_ptr, "CPropDoorRotating", "m_bAjarDoorShouldntAlwaysOpen", false, value);
}
GCEntityBlocker GCPropDoorRotating::GetEntityBlocker() const {
    GCEntityBlocker value(*GetSchemaValuePtr<void*>(m_ptr, "CPropDoorRotating", "m_hEntityBlocker"));
    return value;
}
void GCPropDoorRotating::SetEntityBlocker(GCEntityBlocker* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'EntityBlocker' is not possible.\n");
}
std::string GCPropDoorRotating::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPropDoorRotating::IsValid() {
    return (m_ptr != nullptr);
}
GCBasePropDoor GCPropDoorRotating::GetParent() const {
    GCBasePropDoor value(m_ptr);
    return value;
}
void GCPropDoorRotating::SetParent(GCBasePropDoor value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPropDoorRotating(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPropDoorRotating>("CPropDoorRotating")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Axis", &GCPropDoorRotating::GetAxis, &GCPropDoorRotating::SetAxis)
        .addProperty("Distance", &GCPropDoorRotating::GetDistance, &GCPropDoorRotating::SetDistance)
        .addProperty("SpawnPosition", &GCPropDoorRotating::GetSpawnPosition, &GCPropDoorRotating::SetSpawnPosition)
        .addProperty("OpenDirection", &GCPropDoorRotating::GetOpenDirection, &GCPropDoorRotating::SetOpenDirection)
        .addProperty("CurrentOpenDirection", &GCPropDoorRotating::GetCurrentOpenDirection, &GCPropDoorRotating::SetCurrentOpenDirection)
        .addProperty("AjarAngle", &GCPropDoorRotating::GetAjarAngle, &GCPropDoorRotating::SetAjarAngle)
        .addProperty("RotationAjarDeprecated", &GCPropDoorRotating::GetRotationAjarDeprecated, &GCPropDoorRotating::SetRotationAjarDeprecated)
        .addProperty("RotationClosed", &GCPropDoorRotating::GetRotationClosed, &GCPropDoorRotating::SetRotationClosed)
        .addProperty("RotationOpenForward", &GCPropDoorRotating::GetRotationOpenForward, &GCPropDoorRotating::SetRotationOpenForward)
        .addProperty("RotationOpenBack", &GCPropDoorRotating::GetRotationOpenBack, &GCPropDoorRotating::SetRotationOpenBack)
        .addProperty("Goal", &GCPropDoorRotating::GetGoal, &GCPropDoorRotating::SetGoal)
        .addProperty("ForwardBoundsMin", &GCPropDoorRotating::GetForwardBoundsMin, &GCPropDoorRotating::SetForwardBoundsMin)
        .addProperty("ForwardBoundsMax", &GCPropDoorRotating::GetForwardBoundsMax, &GCPropDoorRotating::SetForwardBoundsMax)
        .addProperty("BackBoundsMin", &GCPropDoorRotating::GetBackBoundsMin, &GCPropDoorRotating::SetBackBoundsMin)
        .addProperty("BackBoundsMax", &GCPropDoorRotating::GetBackBoundsMax, &GCPropDoorRotating::SetBackBoundsMax)
        .addProperty("AjarDoorShouldntAlwaysOpen", &GCPropDoorRotating::GetAjarDoorShouldntAlwaysOpen, &GCPropDoorRotating::SetAjarDoorShouldntAlwaysOpen)
        .addProperty("EntityBlocker", &GCPropDoorRotating::GetEntityBlocker, &GCPropDoorRotating::SetEntityBlocker)
        .addProperty("Parent", &GCPropDoorRotating::GetParent, &GCPropDoorRotating::SetParent)
        .addFunction("ToPtr", &GCPropDoorRotating::ToPtr)
        .addFunction("IsValid", &GCPropDoorRotating::IsValid)
        .endClass();
}