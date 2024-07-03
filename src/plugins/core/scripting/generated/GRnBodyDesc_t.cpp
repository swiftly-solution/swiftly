#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnBodyDesc_t::GRnBodyDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnBodyDesc_t::GRnBodyDesc_t(void *ptr) {
    m_ptr = ptr;
}
std::string GRnBodyDesc_t::GetDebugName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "RnBodyDesc_t", "m_sDebugName").Get();
}
void GRnBodyDesc_t::SetDebugName(std::string value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_sDebugName", true, CUtlString(value.c_str()));
}
Vector GRnBodyDesc_t::GetPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vPosition");
}
void GRnBodyDesc_t::SetPosition(Vector value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vPosition", true, value);
}
Vector GRnBodyDesc_t::GetLinearVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vLinearVelocity");
}
void GRnBodyDesc_t::SetLinearVelocity(Vector value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vLinearVelocity", true, value);
}
Vector GRnBodyDesc_t::GetAngularVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vAngularVelocity");
}
void GRnBodyDesc_t::SetAngularVelocity(Vector value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vAngularVelocity", true, value);
}
Vector GRnBodyDesc_t::GetLocalMassCenter() const {
    return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vLocalMassCenter");
}
void GRnBodyDesc_t::SetLocalMassCenter(Vector value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vLocalMassCenter", true, value);
}
std::vector<Vector> GRnBodyDesc_t::GetLocalInertiaInv() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnBodyDesc_t", "m_LocalInertiaInv"); std::vector<Vector> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GRnBodyDesc_t::SetLocalInertiaInv(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "RnBodyDesc_t", "m_LocalInertiaInv"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_LocalInertiaInv", true, outValue);
}
float GRnBodyDesc_t::GetMassInv() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flMassInv");
}
void GRnBodyDesc_t::SetMassInv(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flMassInv", true, value);
}
float GRnBodyDesc_t::GetGameMass() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flGameMass");
}
void GRnBodyDesc_t::SetGameMass(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flGameMass", true, value);
}
float GRnBodyDesc_t::GetInertiaScaleInv() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flInertiaScaleInv");
}
void GRnBodyDesc_t::SetInertiaScaleInv(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flInertiaScaleInv", true, value);
}
float GRnBodyDesc_t::GetLinearDamping() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flLinearDamping");
}
void GRnBodyDesc_t::SetLinearDamping(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flLinearDamping", true, value);
}
float GRnBodyDesc_t::GetAngularDamping() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flAngularDamping");
}
void GRnBodyDesc_t::SetAngularDamping(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flAngularDamping", true, value);
}
float GRnBodyDesc_t::GetLinearDrag() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flLinearDrag");
}
void GRnBodyDesc_t::SetLinearDrag(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flLinearDrag", true, value);
}
float GRnBodyDesc_t::GetAngularDrag() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flAngularDrag");
}
void GRnBodyDesc_t::SetAngularDrag(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flAngularDrag", true, value);
}
float GRnBodyDesc_t::GetLinearBuoyancyDrag() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flLinearBuoyancyDrag");
}
void GRnBodyDesc_t::SetLinearBuoyancyDrag(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flLinearBuoyancyDrag", true, value);
}
float GRnBodyDesc_t::GetAngularBuoyancyDrag() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flAngularBuoyancyDrag");
}
void GRnBodyDesc_t::SetAngularBuoyancyDrag(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flAngularBuoyancyDrag", true, value);
}
Vector GRnBodyDesc_t::GetLastAwakeForceAccum() const {
    return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vLastAwakeForceAccum");
}
void GRnBodyDesc_t::SetLastAwakeForceAccum(Vector value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vLastAwakeForceAccum", true, value);
}
Vector GRnBodyDesc_t::GetLastAwakeTorqueAccum() const {
    return GetSchemaValue<Vector>(m_ptr, "RnBodyDesc_t", "m_vLastAwakeTorqueAccum");
}
void GRnBodyDesc_t::SetLastAwakeTorqueAccum(Vector value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_vLastAwakeTorqueAccum", true, value);
}
float GRnBodyDesc_t::GetBuoyancyFactor() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flBuoyancyFactor");
}
void GRnBodyDesc_t::SetBuoyancyFactor(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flBuoyancyFactor", true, value);
}
float GRnBodyDesc_t::GetGravityScale() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flGravityScale");
}
void GRnBodyDesc_t::SetGravityScale(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flGravityScale", true, value);
}
float GRnBodyDesc_t::GetTimeScale() const {
    return GetSchemaValue<float>(m_ptr, "RnBodyDesc_t", "m_flTimeScale");
}
void GRnBodyDesc_t::SetTimeScale(float value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_flTimeScale", true, value);
}
int32_t GRnBodyDesc_t::GetBodyType() const {
    return GetSchemaValue<int32_t>(m_ptr, "RnBodyDesc_t", "m_nBodyType");
}
void GRnBodyDesc_t::SetBodyType(int32_t value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nBodyType", true, value);
}
uint32_t GRnBodyDesc_t::GetGameIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RnBodyDesc_t", "m_nGameIndex");
}
void GRnBodyDesc_t::SetGameIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nGameIndex", true, value);
}
uint32_t GRnBodyDesc_t::GetGameFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RnBodyDesc_t", "m_nGameFlags");
}
void GRnBodyDesc_t::SetGameFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nGameFlags", true, value);
}
int8_t GRnBodyDesc_t::GetMinVelocityIterations() const {
    return GetSchemaValue<int8_t>(m_ptr, "RnBodyDesc_t", "m_nMinVelocityIterations");
}
void GRnBodyDesc_t::SetMinVelocityIterations(int8_t value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nMinVelocityIterations", true, value);
}
int8_t GRnBodyDesc_t::GetMinPositionIterations() const {
    return GetSchemaValue<int8_t>(m_ptr, "RnBodyDesc_t", "m_nMinPositionIterations");
}
void GRnBodyDesc_t::SetMinPositionIterations(int8_t value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nMinPositionIterations", true, value);
}
int8_t GRnBodyDesc_t::GetMassPriority() const {
    return GetSchemaValue<int8_t>(m_ptr, "RnBodyDesc_t", "m_nMassPriority");
}
void GRnBodyDesc_t::SetMassPriority(int8_t value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_nMassPriority", true, value);
}
bool GRnBodyDesc_t::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bEnabled");
}
void GRnBodyDesc_t::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bEnabled", true, value);
}
bool GRnBodyDesc_t::GetSleeping() const {
    return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bSleeping");
}
void GRnBodyDesc_t::SetSleeping(bool value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bSleeping", true, value);
}
bool GRnBodyDesc_t::GetIsContinuousEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bIsContinuousEnabled");
}
void GRnBodyDesc_t::SetIsContinuousEnabled(bool value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bIsContinuousEnabled", true, value);
}
bool GRnBodyDesc_t::GetDragEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bDragEnabled");
}
void GRnBodyDesc_t::SetDragEnabled(bool value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bDragEnabled", true, value);
}
bool GRnBodyDesc_t::GetBuoyancyDragEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bBuoyancyDragEnabled");
}
void GRnBodyDesc_t::SetBuoyancyDragEnabled(bool value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bBuoyancyDragEnabled", true, value);
}
bool GRnBodyDesc_t::GetGravityDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bGravityDisabled");
}
void GRnBodyDesc_t::SetGravityDisabled(bool value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bGravityDisabled", true, value);
}
bool GRnBodyDesc_t::GetSpeculativeEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bSpeculativeEnabled");
}
void GRnBodyDesc_t::SetSpeculativeEnabled(bool value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bSpeculativeEnabled", true, value);
}
bool GRnBodyDesc_t::GetHasShadowController() const {
    return GetSchemaValue<bool>(m_ptr, "RnBodyDesc_t", "m_bHasShadowController");
}
void GRnBodyDesc_t::SetHasShadowController(bool value) {
    SetSchemaValue(m_ptr, "RnBodyDesc_t", "m_bHasShadowController", true, value);
}
std::string GRnBodyDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnBodyDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnBodyDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnBodyDesc_t>("RnBodyDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DebugName", &GRnBodyDesc_t::GetDebugName, &GRnBodyDesc_t::SetDebugName)
        .addProperty("Position", &GRnBodyDesc_t::GetPosition, &GRnBodyDesc_t::SetPosition)
        .addProperty("LinearVelocity", &GRnBodyDesc_t::GetLinearVelocity, &GRnBodyDesc_t::SetLinearVelocity)
        .addProperty("AngularVelocity", &GRnBodyDesc_t::GetAngularVelocity, &GRnBodyDesc_t::SetAngularVelocity)
        .addProperty("LocalMassCenter", &GRnBodyDesc_t::GetLocalMassCenter, &GRnBodyDesc_t::SetLocalMassCenter)
        .addProperty("LocalInertiaInv", &GRnBodyDesc_t::GetLocalInertiaInv, &GRnBodyDesc_t::SetLocalInertiaInv)
        .addProperty("MassInv", &GRnBodyDesc_t::GetMassInv, &GRnBodyDesc_t::SetMassInv)
        .addProperty("GameMass", &GRnBodyDesc_t::GetGameMass, &GRnBodyDesc_t::SetGameMass)
        .addProperty("InertiaScaleInv", &GRnBodyDesc_t::GetInertiaScaleInv, &GRnBodyDesc_t::SetInertiaScaleInv)
        .addProperty("LinearDamping", &GRnBodyDesc_t::GetLinearDamping, &GRnBodyDesc_t::SetLinearDamping)
        .addProperty("AngularDamping", &GRnBodyDesc_t::GetAngularDamping, &GRnBodyDesc_t::SetAngularDamping)
        .addProperty("LinearDrag", &GRnBodyDesc_t::GetLinearDrag, &GRnBodyDesc_t::SetLinearDrag)
        .addProperty("AngularDrag", &GRnBodyDesc_t::GetAngularDrag, &GRnBodyDesc_t::SetAngularDrag)
        .addProperty("LinearBuoyancyDrag", &GRnBodyDesc_t::GetLinearBuoyancyDrag, &GRnBodyDesc_t::SetLinearBuoyancyDrag)
        .addProperty("AngularBuoyancyDrag", &GRnBodyDesc_t::GetAngularBuoyancyDrag, &GRnBodyDesc_t::SetAngularBuoyancyDrag)
        .addProperty("LastAwakeForceAccum", &GRnBodyDesc_t::GetLastAwakeForceAccum, &GRnBodyDesc_t::SetLastAwakeForceAccum)
        .addProperty("LastAwakeTorqueAccum", &GRnBodyDesc_t::GetLastAwakeTorqueAccum, &GRnBodyDesc_t::SetLastAwakeTorqueAccum)
        .addProperty("BuoyancyFactor", &GRnBodyDesc_t::GetBuoyancyFactor, &GRnBodyDesc_t::SetBuoyancyFactor)
        .addProperty("GravityScale", &GRnBodyDesc_t::GetGravityScale, &GRnBodyDesc_t::SetGravityScale)
        .addProperty("TimeScale", &GRnBodyDesc_t::GetTimeScale, &GRnBodyDesc_t::SetTimeScale)
        .addProperty("BodyType", &GRnBodyDesc_t::GetBodyType, &GRnBodyDesc_t::SetBodyType)
        .addProperty("GameIndex", &GRnBodyDesc_t::GetGameIndex, &GRnBodyDesc_t::SetGameIndex)
        .addProperty("GameFlags", &GRnBodyDesc_t::GetGameFlags, &GRnBodyDesc_t::SetGameFlags)
        .addProperty("MinVelocityIterations", &GRnBodyDesc_t::GetMinVelocityIterations, &GRnBodyDesc_t::SetMinVelocityIterations)
        .addProperty("MinPositionIterations", &GRnBodyDesc_t::GetMinPositionIterations, &GRnBodyDesc_t::SetMinPositionIterations)
        .addProperty("MassPriority", &GRnBodyDesc_t::GetMassPriority, &GRnBodyDesc_t::SetMassPriority)
        .addProperty("Enabled", &GRnBodyDesc_t::GetEnabled, &GRnBodyDesc_t::SetEnabled)
        .addProperty("Sleeping", &GRnBodyDesc_t::GetSleeping, &GRnBodyDesc_t::SetSleeping)
        .addProperty("IsContinuousEnabled", &GRnBodyDesc_t::GetIsContinuousEnabled, &GRnBodyDesc_t::SetIsContinuousEnabled)
        .addProperty("DragEnabled", &GRnBodyDesc_t::GetDragEnabled, &GRnBodyDesc_t::SetDragEnabled)
        .addProperty("BuoyancyDragEnabled", &GRnBodyDesc_t::GetBuoyancyDragEnabled, &GRnBodyDesc_t::SetBuoyancyDragEnabled)
        .addProperty("GravityDisabled", &GRnBodyDesc_t::GetGravityDisabled, &GRnBodyDesc_t::SetGravityDisabled)
        .addProperty("SpeculativeEnabled", &GRnBodyDesc_t::GetSpeculativeEnabled, &GRnBodyDesc_t::SetSpeculativeEnabled)
        .addProperty("HasShadowController", &GRnBodyDesc_t::GetHasShadowController, &GRnBodyDesc_t::SetHasShadowController)
        .addFunction("ToPtr", &GRnBodyDesc_t::ToPtr)
        .addFunction("IsValid", &GRnBodyDesc_t::IsValid)
        .endClass();
}