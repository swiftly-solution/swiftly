#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSkeletonAnimCapture_t__FrameStamp_t::GSkeletonAnimCapture_t__FrameStamp_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSkeletonAnimCapture_t__FrameStamp_t::GSkeletonAnimCapture_t__FrameStamp_t(void *ptr) {
    m_ptr = ptr;
}
float GSkeletonAnimCapture_t__FrameStamp_t::GetTime() const {
    return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flTime");
}
void GSkeletonAnimCapture_t__FrameStamp_t::SetTime(float value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flTime", true, value);
}
float GSkeletonAnimCapture_t__FrameStamp_t::GetEntitySimTime() const {
    return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flEntitySimTime");
}
void GSkeletonAnimCapture_t__FrameStamp_t::SetEntitySimTime(float value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flEntitySimTime", true, value);
}
bool GSkeletonAnimCapture_t__FrameStamp_t::GetTeleportTick() const {
    return GetSchemaValue<bool>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_bTeleportTick");
}
void GSkeletonAnimCapture_t__FrameStamp_t::SetTeleportTick(bool value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_bTeleportTick", true, value);
}
bool GSkeletonAnimCapture_t__FrameStamp_t::GetPredicted() const {
    return GetSchemaValue<bool>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_bPredicted");
}
void GSkeletonAnimCapture_t__FrameStamp_t::SetPredicted(bool value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_bPredicted", true, value);
}
float GSkeletonAnimCapture_t__FrameStamp_t::GetCurTime() const {
    return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flCurTime");
}
void GSkeletonAnimCapture_t__FrameStamp_t::SetCurTime(float value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flCurTime", true, value);
}
float GSkeletonAnimCapture_t__FrameStamp_t::GetRealTime() const {
    return GetSchemaValue<float>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flRealTime");
}
void GSkeletonAnimCapture_t__FrameStamp_t::SetRealTime(float value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_flRealTime", true, value);
}
int32_t GSkeletonAnimCapture_t__FrameStamp_t::GetFrameCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_nFrameCount");
}
void GSkeletonAnimCapture_t__FrameStamp_t::SetFrameCount(int32_t value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_nFrameCount", true, value);
}
int32_t GSkeletonAnimCapture_t__FrameStamp_t::GetTickCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_nTickCount");
}
void GSkeletonAnimCapture_t__FrameStamp_t::SetTickCount(int32_t value) {
    SetSchemaValue(m_ptr, "SkeletonAnimCapture_t__FrameStamp_t", "m_nTickCount", true, value);
}
std::string GSkeletonAnimCapture_t__FrameStamp_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSkeletonAnimCapture_t__FrameStamp_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSkeletonAnimCapture_t__FrameStamp_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonAnimCapture_t__FrameStamp_t>("SkeletonAnimCapture_t__FrameStamp_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Time", &GSkeletonAnimCapture_t__FrameStamp_t::GetTime, &GSkeletonAnimCapture_t__FrameStamp_t::SetTime)
        .addProperty("EntitySimTime", &GSkeletonAnimCapture_t__FrameStamp_t::GetEntitySimTime, &GSkeletonAnimCapture_t__FrameStamp_t::SetEntitySimTime)
        .addProperty("TeleportTick", &GSkeletonAnimCapture_t__FrameStamp_t::GetTeleportTick, &GSkeletonAnimCapture_t__FrameStamp_t::SetTeleportTick)
        .addProperty("Predicted", &GSkeletonAnimCapture_t__FrameStamp_t::GetPredicted, &GSkeletonAnimCapture_t__FrameStamp_t::SetPredicted)
        .addProperty("CurTime", &GSkeletonAnimCapture_t__FrameStamp_t::GetCurTime, &GSkeletonAnimCapture_t__FrameStamp_t::SetCurTime)
        .addProperty("RealTime", &GSkeletonAnimCapture_t__FrameStamp_t::GetRealTime, &GSkeletonAnimCapture_t__FrameStamp_t::SetRealTime)
        .addProperty("FrameCount", &GSkeletonAnimCapture_t__FrameStamp_t::GetFrameCount, &GSkeletonAnimCapture_t__FrameStamp_t::SetFrameCount)
        .addProperty("TickCount", &GSkeletonAnimCapture_t__FrameStamp_t::GetTickCount, &GSkeletonAnimCapture_t__FrameStamp_t::SetTickCount)
        .addFunction("ToPtr", &GSkeletonAnimCapture_t__FrameStamp_t::ToPtr)
        .addFunction("IsValid", &GSkeletonAnimCapture_t__FrameStamp_t::IsValid)
        .endClass();
}