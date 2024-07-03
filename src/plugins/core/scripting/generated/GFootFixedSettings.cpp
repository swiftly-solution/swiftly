#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFootFixedSettings::GFootFixedSettings(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFootFixedSettings::GFootFixedSettings(void *ptr) {
    m_ptr = ptr;
}
GTraceSettings_t GFootFixedSettings::GetTraceSettings() const {
    GTraceSettings_t value(GetSchemaPtr(m_ptr, "FootFixedSettings", "m_traceSettings"));
    return value;
}
void GFootFixedSettings::SetTraceSettings(GTraceSettings_t value) {
    SetSchemaValue(m_ptr, "FootFixedSettings", "m_traceSettings", false, value);
}
Vector GFootFixedSettings::GetFootBaseBindPosePositionMS() const {
    return GetSchemaValue<Vector>(m_ptr, "FootFixedSettings", "m_vFootBaseBindPosePositionMS");
}
void GFootFixedSettings::SetFootBaseBindPosePositionMS(Vector value) {
    SetSchemaValue(m_ptr, "FootFixedSettings", "m_vFootBaseBindPosePositionMS", false, value);
}
float GFootFixedSettings::GetFootBaseLength() const {
    return GetSchemaValue<float>(m_ptr, "FootFixedSettings", "m_flFootBaseLength");
}
void GFootFixedSettings::SetFootBaseLength(float value) {
    SetSchemaValue(m_ptr, "FootFixedSettings", "m_flFootBaseLength", false, value);
}
float GFootFixedSettings::GetMaxRotationLeft() const {
    return GetSchemaValue<float>(m_ptr, "FootFixedSettings", "m_flMaxRotationLeft");
}
void GFootFixedSettings::SetMaxRotationLeft(float value) {
    SetSchemaValue(m_ptr, "FootFixedSettings", "m_flMaxRotationLeft", false, value);
}
float GFootFixedSettings::GetMaxRotationRight() const {
    return GetSchemaValue<float>(m_ptr, "FootFixedSettings", "m_flMaxRotationRight");
}
void GFootFixedSettings::SetMaxRotationRight(float value) {
    SetSchemaValue(m_ptr, "FootFixedSettings", "m_flMaxRotationRight", false, value);
}
int32_t GFootFixedSettings::GetFootstepLandedTagIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootFixedSettings", "m_footstepLandedTagIndex");
}
void GFootFixedSettings::SetFootstepLandedTagIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootFixedSettings", "m_footstepLandedTagIndex", false, value);
}
bool GFootFixedSettings::GetEnableTracing() const {
    return GetSchemaValue<bool>(m_ptr, "FootFixedSettings", "m_bEnableTracing");
}
void GFootFixedSettings::SetEnableTracing(bool value) {
    SetSchemaValue(m_ptr, "FootFixedSettings", "m_bEnableTracing", false, value);
}
float GFootFixedSettings::GetTraceAngleBlend() const {
    return GetSchemaValue<float>(m_ptr, "FootFixedSettings", "m_flTraceAngleBlend");
}
void GFootFixedSettings::SetTraceAngleBlend(float value) {
    SetSchemaValue(m_ptr, "FootFixedSettings", "m_flTraceAngleBlend", false, value);
}
int32_t GFootFixedSettings::GetDisableTagIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootFixedSettings", "m_nDisableTagIndex");
}
void GFootFixedSettings::SetDisableTagIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootFixedSettings", "m_nDisableTagIndex", false, value);
}
int32_t GFootFixedSettings::GetFootIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootFixedSettings", "m_nFootIndex");
}
void GFootFixedSettings::SetFootIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootFixedSettings", "m_nFootIndex", false, value);
}
std::string GFootFixedSettings::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFootFixedSettings::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFootFixedSettings(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFootFixedSettings>("FootFixedSettings")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TraceSettings", &GFootFixedSettings::GetTraceSettings, &GFootFixedSettings::SetTraceSettings)
        .addProperty("FootBaseBindPosePositionMS", &GFootFixedSettings::GetFootBaseBindPosePositionMS, &GFootFixedSettings::SetFootBaseBindPosePositionMS)
        .addProperty("FootBaseLength", &GFootFixedSettings::GetFootBaseLength, &GFootFixedSettings::SetFootBaseLength)
        .addProperty("MaxRotationLeft", &GFootFixedSettings::GetMaxRotationLeft, &GFootFixedSettings::SetMaxRotationLeft)
        .addProperty("MaxRotationRight", &GFootFixedSettings::GetMaxRotationRight, &GFootFixedSettings::SetMaxRotationRight)
        .addProperty("FootstepLandedTagIndex", &GFootFixedSettings::GetFootstepLandedTagIndex, &GFootFixedSettings::SetFootstepLandedTagIndex)
        .addProperty("EnableTracing", &GFootFixedSettings::GetEnableTracing, &GFootFixedSettings::SetEnableTracing)
        .addProperty("TraceAngleBlend", &GFootFixedSettings::GetTraceAngleBlend, &GFootFixedSettings::SetTraceAngleBlend)
        .addProperty("DisableTagIndex", &GFootFixedSettings::GetDisableTagIndex, &GFootFixedSettings::SetDisableTagIndex)
        .addProperty("FootIndex", &GFootFixedSettings::GetFootIndex, &GFootFixedSettings::SetFootIndex)
        .addFunction("ToPtr", &GFootFixedSettings::ToPtr)
        .addFunction("IsValid", &GFootFixedSettings::IsValid)
        .endClass();
}