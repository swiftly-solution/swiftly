#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventSetTime_t::GEventSetTime_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventSetTime_t::GEventSetTime_t(void *ptr) {
    m_ptr = ptr;
}
GEngineLoopState_t GEventSetTime_t::GetLoopState() const {
    GEngineLoopState_t value(GetSchemaPtr(m_ptr, "EventSetTime_t", "m_LoopState"));
    return value;
}
void GEventSetTime_t::SetLoopState(GEngineLoopState_t value) {
    SetSchemaValue(m_ptr, "EventSetTime_t", "m_LoopState", true, value);
}
int32_t GEventSetTime_t::GetClientOutputFrames() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventSetTime_t", "m_nClientOutputFrames");
}
void GEventSetTime_t::SetClientOutputFrames(int32_t value) {
    SetSchemaValue(m_ptr, "EventSetTime_t", "m_nClientOutputFrames", true, value);
}
double GEventSetTime_t::GetRealTime() const {
    return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flRealTime");
}
void GEventSetTime_t::SetRealTime(double value) {
    SetSchemaValue(m_ptr, "EventSetTime_t", "m_flRealTime", true, value);
}
double GEventSetTime_t::GetRenderTime() const {
    return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flRenderTime");
}
void GEventSetTime_t::SetRenderTime(double value) {
    SetSchemaValue(m_ptr, "EventSetTime_t", "m_flRenderTime", true, value);
}
double GEventSetTime_t::GetRenderFrameTime() const {
    return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flRenderFrameTime");
}
void GEventSetTime_t::SetRenderFrameTime(double value) {
    SetSchemaValue(m_ptr, "EventSetTime_t", "m_flRenderFrameTime", true, value);
}
double GEventSetTime_t::GetRenderFrameTimeUnbounded() const {
    return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flRenderFrameTimeUnbounded");
}
void GEventSetTime_t::SetRenderFrameTimeUnbounded(double value) {
    SetSchemaValue(m_ptr, "EventSetTime_t", "m_flRenderFrameTimeUnbounded", true, value);
}
double GEventSetTime_t::GetRenderFrameTimeUnscaled() const {
    return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flRenderFrameTimeUnscaled");
}
void GEventSetTime_t::SetRenderFrameTimeUnscaled(double value) {
    SetSchemaValue(m_ptr, "EventSetTime_t", "m_flRenderFrameTimeUnscaled", true, value);
}
double GEventSetTime_t::GetTickRemainder() const {
    return GetSchemaValue<double>(m_ptr, "EventSetTime_t", "m_flTickRemainder");
}
void GEventSetTime_t::SetTickRemainder(double value) {
    SetSchemaValue(m_ptr, "EventSetTime_t", "m_flTickRemainder", true, value);
}
std::string GEventSetTime_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventSetTime_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventSetTime_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventSetTime_t>("EventSetTime_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoopState", &GEventSetTime_t::GetLoopState, &GEventSetTime_t::SetLoopState)
        .addProperty("ClientOutputFrames", &GEventSetTime_t::GetClientOutputFrames, &GEventSetTime_t::SetClientOutputFrames)
        .addProperty("RealTime", &GEventSetTime_t::GetRealTime, &GEventSetTime_t::SetRealTime)
        .addProperty("RenderTime", &GEventSetTime_t::GetRenderTime, &GEventSetTime_t::SetRenderTime)
        .addProperty("RenderFrameTime", &GEventSetTime_t::GetRenderFrameTime, &GEventSetTime_t::SetRenderFrameTime)
        .addProperty("RenderFrameTimeUnbounded", &GEventSetTime_t::GetRenderFrameTimeUnbounded, &GEventSetTime_t::SetRenderFrameTimeUnbounded)
        .addProperty("RenderFrameTimeUnscaled", &GEventSetTime_t::GetRenderFrameTimeUnscaled, &GEventSetTime_t::SetRenderFrameTimeUnscaled)
        .addProperty("TickRemainder", &GEventSetTime_t::GetTickRemainder, &GEventSetTime_t::SetTickRemainder)
        .addFunction("ToPtr", &GEventSetTime_t::ToPtr)
        .addFunction("IsValid", &GEventSetTime_t::IsValid)
        .endClass();
}