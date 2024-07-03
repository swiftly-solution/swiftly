#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseMoveBehavior::GCBaseMoveBehavior(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseMoveBehavior::GCBaseMoveBehavior(void *ptr) {
    m_ptr = ptr;
}
int32_t GCBaseMoveBehavior::GetPositionInterpolator() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseMoveBehavior", "m_iPositionInterpolator");
}
void GCBaseMoveBehavior::SetPositionInterpolator(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_iPositionInterpolator", false, value);
}
int32_t GCBaseMoveBehavior::GetRotationInterpolator() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseMoveBehavior", "m_iRotationInterpolator");
}
void GCBaseMoveBehavior::SetRotationInterpolator(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_iRotationInterpolator", false, value);
}
float GCBaseMoveBehavior::GetAnimStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseMoveBehavior", "m_flAnimStartTime");
}
void GCBaseMoveBehavior::SetAnimStartTime(float value) {
    SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_flAnimStartTime", false, value);
}
float GCBaseMoveBehavior::GetAnimEndTime() const {
    return GetSchemaValue<float>(m_ptr, "CBaseMoveBehavior", "m_flAnimEndTime");
}
void GCBaseMoveBehavior::SetAnimEndTime(float value) {
    SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_flAnimEndTime", false, value);
}
float GCBaseMoveBehavior::GetAverageSpeedAcrossFrame() const {
    return GetSchemaValue<float>(m_ptr, "CBaseMoveBehavior", "m_flAverageSpeedAcrossFrame");
}
void GCBaseMoveBehavior::SetAverageSpeedAcrossFrame(float value) {
    SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_flAverageSpeedAcrossFrame", false, value);
}
GCPathKeyFrame GCBaseMoveBehavior::GetCurrentKeyFrame() const {
    GCPathKeyFrame value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseMoveBehavior", "m_pCurrentKeyFrame"));
    return value;
}
void GCBaseMoveBehavior::SetCurrentKeyFrame(GCPathKeyFrame* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CurrentKeyFrame' is not possible.\n");
}
GCPathKeyFrame GCBaseMoveBehavior::GetTargetKeyFrame() const {
    GCPathKeyFrame value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseMoveBehavior", "m_pTargetKeyFrame"));
    return value;
}
void GCBaseMoveBehavior::SetTargetKeyFrame(GCPathKeyFrame* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetKeyFrame' is not possible.\n");
}
GCPathKeyFrame GCBaseMoveBehavior::GetPreKeyFrame() const {
    GCPathKeyFrame value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseMoveBehavior", "m_pPreKeyFrame"));
    return value;
}
void GCBaseMoveBehavior::SetPreKeyFrame(GCPathKeyFrame* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PreKeyFrame' is not possible.\n");
}
GCPathKeyFrame GCBaseMoveBehavior::GetPostKeyFrame() const {
    GCPathKeyFrame value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseMoveBehavior", "m_pPostKeyFrame"));
    return value;
}
void GCBaseMoveBehavior::SetPostKeyFrame(GCPathKeyFrame* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PostKeyFrame' is not possible.\n");
}
float GCBaseMoveBehavior::GetTimeIntoFrame() const {
    return GetSchemaValue<float>(m_ptr, "CBaseMoveBehavior", "m_flTimeIntoFrame");
}
void GCBaseMoveBehavior::SetTimeIntoFrame(float value) {
    SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_flTimeIntoFrame", false, value);
}
int32_t GCBaseMoveBehavior::GetDirection() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseMoveBehavior", "m_iDirection");
}
void GCBaseMoveBehavior::SetDirection(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseMoveBehavior", "m_iDirection", false, value);
}
std::string GCBaseMoveBehavior::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseMoveBehavior::IsValid() {
    return (m_ptr != nullptr);
}
GCPathKeyFrame GCBaseMoveBehavior::GetParent() const {
    GCPathKeyFrame value(m_ptr);
    return value;
}
void GCBaseMoveBehavior::SetParent(GCPathKeyFrame value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseMoveBehavior(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseMoveBehavior>("CBaseMoveBehavior")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PositionInterpolator", &GCBaseMoveBehavior::GetPositionInterpolator, &GCBaseMoveBehavior::SetPositionInterpolator)
        .addProperty("RotationInterpolator", &GCBaseMoveBehavior::GetRotationInterpolator, &GCBaseMoveBehavior::SetRotationInterpolator)
        .addProperty("AnimStartTime", &GCBaseMoveBehavior::GetAnimStartTime, &GCBaseMoveBehavior::SetAnimStartTime)
        .addProperty("AnimEndTime", &GCBaseMoveBehavior::GetAnimEndTime, &GCBaseMoveBehavior::SetAnimEndTime)
        .addProperty("AverageSpeedAcrossFrame", &GCBaseMoveBehavior::GetAverageSpeedAcrossFrame, &GCBaseMoveBehavior::SetAverageSpeedAcrossFrame)
        .addProperty("CurrentKeyFrame", &GCBaseMoveBehavior::GetCurrentKeyFrame, &GCBaseMoveBehavior::SetCurrentKeyFrame)
        .addProperty("TargetKeyFrame", &GCBaseMoveBehavior::GetTargetKeyFrame, &GCBaseMoveBehavior::SetTargetKeyFrame)
        .addProperty("PreKeyFrame", &GCBaseMoveBehavior::GetPreKeyFrame, &GCBaseMoveBehavior::SetPreKeyFrame)
        .addProperty("PostKeyFrame", &GCBaseMoveBehavior::GetPostKeyFrame, &GCBaseMoveBehavior::SetPostKeyFrame)
        .addProperty("TimeIntoFrame", &GCBaseMoveBehavior::GetTimeIntoFrame, &GCBaseMoveBehavior::SetTimeIntoFrame)
        .addProperty("Direction", &GCBaseMoveBehavior::GetDirection, &GCBaseMoveBehavior::SetDirection)
        .addProperty("Parent", &GCBaseMoveBehavior::GetParent, &GCBaseMoveBehavior::SetParent)
        .addFunction("ToPtr", &GCBaseMoveBehavior::ToPtr)
        .addFunction("IsValid", &GCBaseMoveBehavior::IsValid)
        .endClass();
}