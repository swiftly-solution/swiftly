#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_MovementServices_Humanoid::GCPlayer_MovementServices_Humanoid(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_MovementServices_Humanoid::GCPlayer_MovementServices_Humanoid(void *ptr) {
    m_ptr = ptr;
}
float GCPlayer_MovementServices_Humanoid::GetStepSoundTime() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flStepSoundTime");
}
void GCPlayer_MovementServices_Humanoid::SetStepSoundTime(float value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flStepSoundTime", false, value);
}
float GCPlayer_MovementServices_Humanoid::GetFallVelocity() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flFallVelocity");
}
void GCPlayer_MovementServices_Humanoid::SetFallVelocity(float value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flFallVelocity", false, value);
}
bool GCPlayer_MovementServices_Humanoid::GetInCrouch() const {
    return GetSchemaValue<bool>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bInCrouch");
}
void GCPlayer_MovementServices_Humanoid::SetInCrouch(bool value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bInCrouch", false, value);
}
uint32_t GCPlayer_MovementServices_Humanoid::GetCrouchState() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_nCrouchState");
}
void GCPlayer_MovementServices_Humanoid::SetCrouchState(uint32_t value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_nCrouchState", false, value);
}
float GCPlayer_MovementServices_Humanoid::GetCrouchTransitionStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flCrouchTransitionStartTime");
}
void GCPlayer_MovementServices_Humanoid::SetCrouchTransitionStartTime(float value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flCrouchTransitionStartTime", false, value);
}
bool GCPlayer_MovementServices_Humanoid::GetDucked() const {
    return GetSchemaValue<bool>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bDucked");
}
void GCPlayer_MovementServices_Humanoid::SetDucked(bool value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bDucked", false, value);
}
bool GCPlayer_MovementServices_Humanoid::GetDucking() const {
    return GetSchemaValue<bool>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bDucking");
}
void GCPlayer_MovementServices_Humanoid::SetDucking(bool value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bDucking", false, value);
}
bool GCPlayer_MovementServices_Humanoid::GetInDuckJump() const {
    return GetSchemaValue<bool>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bInDuckJump");
}
void GCPlayer_MovementServices_Humanoid::SetInDuckJump(bool value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_bInDuckJump", false, value);
}
Vector GCPlayer_MovementServices_Humanoid::GetGroundNormal() const {
    return GetSchemaValue<Vector>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_groundNormal");
}
void GCPlayer_MovementServices_Humanoid::SetGroundNormal(Vector value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_groundNormal", false, value);
}
float GCPlayer_MovementServices_Humanoid::GetSurfaceFriction() const {
    return GetSchemaValue<float>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flSurfaceFriction");
}
void GCPlayer_MovementServices_Humanoid::SetSurfaceFriction(float value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_flSurfaceFriction", false, value);
}
CUtlStringToken GCPlayer_MovementServices_Humanoid::GetSurfaceProps() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_surfaceProps");
}
void GCPlayer_MovementServices_Humanoid::SetSurfaceProps(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_surfaceProps", false, value);
}
int32_t GCPlayer_MovementServices_Humanoid::GetStepside() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_nStepside");
}
void GCPlayer_MovementServices_Humanoid::SetStepside(int32_t value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_nStepside", false, value);
}
int32_t GCPlayer_MovementServices_Humanoid::GetTargetVolume() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_iTargetVolume");
}
void GCPlayer_MovementServices_Humanoid::SetTargetVolume(int32_t value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_iTargetVolume", false, value);
}
Vector GCPlayer_MovementServices_Humanoid::GetSmoothedVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "CPlayer_MovementServices_Humanoid", "m_vecSmoothedVelocity");
}
void GCPlayer_MovementServices_Humanoid::SetSmoothedVelocity(Vector value) {
    SetSchemaValue(m_ptr, "CPlayer_MovementServices_Humanoid", "m_vecSmoothedVelocity", false, value);
}
std::string GCPlayer_MovementServices_Humanoid::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_MovementServices_Humanoid::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_MovementServices GCPlayer_MovementServices_Humanoid::GetParent() const {
    GCPlayer_MovementServices value(m_ptr);
    return value;
}
void GCPlayer_MovementServices_Humanoid::SetParent(GCPlayer_MovementServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_MovementServices_Humanoid(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_MovementServices_Humanoid>("CPlayer_MovementServices_Humanoid")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StepSoundTime", &GCPlayer_MovementServices_Humanoid::GetStepSoundTime, &GCPlayer_MovementServices_Humanoid::SetStepSoundTime)
        .addProperty("FallVelocity", &GCPlayer_MovementServices_Humanoid::GetFallVelocity, &GCPlayer_MovementServices_Humanoid::SetFallVelocity)
        .addProperty("InCrouch", &GCPlayer_MovementServices_Humanoid::GetInCrouch, &GCPlayer_MovementServices_Humanoid::SetInCrouch)
        .addProperty("CrouchState", &GCPlayer_MovementServices_Humanoid::GetCrouchState, &GCPlayer_MovementServices_Humanoid::SetCrouchState)
        .addProperty("CrouchTransitionStartTime", &GCPlayer_MovementServices_Humanoid::GetCrouchTransitionStartTime, &GCPlayer_MovementServices_Humanoid::SetCrouchTransitionStartTime)
        .addProperty("Ducked", &GCPlayer_MovementServices_Humanoid::GetDucked, &GCPlayer_MovementServices_Humanoid::SetDucked)
        .addProperty("Ducking", &GCPlayer_MovementServices_Humanoid::GetDucking, &GCPlayer_MovementServices_Humanoid::SetDucking)
        .addProperty("InDuckJump", &GCPlayer_MovementServices_Humanoid::GetInDuckJump, &GCPlayer_MovementServices_Humanoid::SetInDuckJump)
        .addProperty("GroundNormal", &GCPlayer_MovementServices_Humanoid::GetGroundNormal, &GCPlayer_MovementServices_Humanoid::SetGroundNormal)
        .addProperty("SurfaceFriction", &GCPlayer_MovementServices_Humanoid::GetSurfaceFriction, &GCPlayer_MovementServices_Humanoid::SetSurfaceFriction)
        .addProperty("SurfaceProps", &GCPlayer_MovementServices_Humanoid::GetSurfaceProps, &GCPlayer_MovementServices_Humanoid::SetSurfaceProps)
        .addProperty("Stepside", &GCPlayer_MovementServices_Humanoid::GetStepside, &GCPlayer_MovementServices_Humanoid::SetStepside)
        .addProperty("TargetVolume", &GCPlayer_MovementServices_Humanoid::GetTargetVolume, &GCPlayer_MovementServices_Humanoid::SetTargetVolume)
        .addProperty("SmoothedVelocity", &GCPlayer_MovementServices_Humanoid::GetSmoothedVelocity, &GCPlayer_MovementServices_Humanoid::SetSmoothedVelocity)
        .addProperty("Parent", &GCPlayer_MovementServices_Humanoid::GetParent, &GCPlayer_MovementServices_Humanoid::SetParent)
        .addFunction("ToPtr", &GCPlayer_MovementServices_Humanoid::ToPtr)
        .addFunction("IsValid", &GCPlayer_MovementServices_Humanoid::IsValid)
        .endClass();
}