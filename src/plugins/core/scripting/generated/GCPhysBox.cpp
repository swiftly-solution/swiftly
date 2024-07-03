#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysBox::GCPhysBox(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysBox::GCPhysBox(void *ptr) {
    m_ptr = ptr;
}
int32_t GCPhysBox::GetDamageType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysBox", "m_damageType");
}
void GCPhysBox::SetDamageType(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_damageType", false, value);
}
float GCPhysBox::GetMassScale() const {
    return GetSchemaValue<float>(m_ptr, "CPhysBox", "m_massScale");
}
void GCPhysBox::SetMassScale(float value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_massScale", false, value);
}
int32_t GCPhysBox::GetDamageToEnableMotion() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysBox", "m_damageToEnableMotion");
}
void GCPhysBox::SetDamageToEnableMotion(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_damageToEnableMotion", false, value);
}
float GCPhysBox::GetForceToEnableMotion() const {
    return GetSchemaValue<float>(m_ptr, "CPhysBox", "m_flForceToEnableMotion");
}
void GCPhysBox::SetForceToEnableMotion(float value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_flForceToEnableMotion", false, value);
}
QAngle GCPhysBox::GetPreferredCarryAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPhysBox", "m_angPreferredCarryAngles");
}
void GCPhysBox::SetPreferredCarryAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_angPreferredCarryAngles", false, value);
}
bool GCPhysBox::GetNotSolidToWorld() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysBox", "m_bNotSolidToWorld");
}
void GCPhysBox::SetNotSolidToWorld(bool value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_bNotSolidToWorld", false, value);
}
bool GCPhysBox::GetEnableUseOutput() const {
    return GetSchemaValue<bool>(m_ptr, "CPhysBox", "m_bEnableUseOutput");
}
void GCPhysBox::SetEnableUseOutput(bool value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_bEnableUseOutput", false, value);
}
int32_t GCPhysBox::GetExploitableByPlayer() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysBox", "m_iExploitableByPlayer");
}
void GCPhysBox::SetExploitableByPlayer(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_iExploitableByPlayer", false, value);
}
float GCPhysBox::GetTouchOutputPerEntityDelay() const {
    return GetSchemaValue<float>(m_ptr, "CPhysBox", "m_flTouchOutputPerEntityDelay");
}
void GCPhysBox::SetTouchOutputPerEntityDelay(float value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_flTouchOutputPerEntityDelay", false, value);
}
GCEntityIOOutput GCPhysBox::GetOnDamaged() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysBox", "m_OnDamaged"));
    return value;
}
void GCPhysBox::SetOnDamaged(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_OnDamaged", false, value);
}
GCEntityIOOutput GCPhysBox::GetOnAwakened() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysBox", "m_OnAwakened"));
    return value;
}
void GCPhysBox::SetOnAwakened(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_OnAwakened", false, value);
}
GCEntityIOOutput GCPhysBox::GetOnMotionEnabled() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysBox", "m_OnMotionEnabled"));
    return value;
}
void GCPhysBox::SetOnMotionEnabled(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_OnMotionEnabled", false, value);
}
GCEntityIOOutput GCPhysBox::GetOnPlayerUse() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysBox", "m_OnPlayerUse"));
    return value;
}
void GCPhysBox::SetOnPlayerUse(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_OnPlayerUse", false, value);
}
GCEntityIOOutput GCPhysBox::GetOnStartTouch() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CPhysBox", "m_OnStartTouch"));
    return value;
}
void GCPhysBox::SetOnStartTouch(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CPhysBox", "m_OnStartTouch", false, value);
}
GCBasePlayerPawn GCPhysBox::GetCarryingPlayer() const {
    GCBasePlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CPhysBox", "m_hCarryingPlayer"));
    return value;
}
void GCPhysBox::SetCarryingPlayer(GCBasePlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CarryingPlayer' is not possible.\n");
}
std::string GCPhysBox::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysBox::IsValid() {
    return (m_ptr != nullptr);
}
GCBreakable GCPhysBox::GetParent() const {
    GCBreakable value(m_ptr);
    return value;
}
void GCPhysBox::SetParent(GCBreakable value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysBox>("CPhysBox")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DamageType", &GCPhysBox::GetDamageType, &GCPhysBox::SetDamageType)
        .addProperty("MassScale", &GCPhysBox::GetMassScale, &GCPhysBox::SetMassScale)
        .addProperty("DamageToEnableMotion", &GCPhysBox::GetDamageToEnableMotion, &GCPhysBox::SetDamageToEnableMotion)
        .addProperty("ForceToEnableMotion", &GCPhysBox::GetForceToEnableMotion, &GCPhysBox::SetForceToEnableMotion)
        .addProperty("PreferredCarryAngles", &GCPhysBox::GetPreferredCarryAngles, &GCPhysBox::SetPreferredCarryAngles)
        .addProperty("NotSolidToWorld", &GCPhysBox::GetNotSolidToWorld, &GCPhysBox::SetNotSolidToWorld)
        .addProperty("EnableUseOutput", &GCPhysBox::GetEnableUseOutput, &GCPhysBox::SetEnableUseOutput)
        .addProperty("ExploitableByPlayer", &GCPhysBox::GetExploitableByPlayer, &GCPhysBox::SetExploitableByPlayer)
        .addProperty("TouchOutputPerEntityDelay", &GCPhysBox::GetTouchOutputPerEntityDelay, &GCPhysBox::SetTouchOutputPerEntityDelay)
        .addProperty("OnDamaged", &GCPhysBox::GetOnDamaged, &GCPhysBox::SetOnDamaged)
        .addProperty("OnAwakened", &GCPhysBox::GetOnAwakened, &GCPhysBox::SetOnAwakened)
        .addProperty("OnMotionEnabled", &GCPhysBox::GetOnMotionEnabled, &GCPhysBox::SetOnMotionEnabled)
        .addProperty("OnPlayerUse", &GCPhysBox::GetOnPlayerUse, &GCPhysBox::SetOnPlayerUse)
        .addProperty("OnStartTouch", &GCPhysBox::GetOnStartTouch, &GCPhysBox::SetOnStartTouch)
        .addProperty("CarryingPlayer", &GCPhysBox::GetCarryingPlayer, &GCPhysBox::SetCarryingPlayer)
        .addProperty("Parent", &GCPhysBox::GetParent, &GCPhysBox::SetParent)
        .addFunction("ToPtr", &GCPhysBox::ToPtr)
        .addFunction("IsValid", &GCPhysBox::IsValid)
        .endClass();
}