#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientPreOutput_t::GEventClientPreOutput_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientPreOutput_t::GEventClientPreOutput_t(void *ptr) {
    m_ptr = ptr;
}
GEngineLoopState_t GEventClientPreOutput_t::GetLoopState() const {
    GEngineLoopState_t value(GetSchemaPtr(m_ptr, "EventClientPreOutput_t", "m_LoopState"));
    return value;
}
void GEventClientPreOutput_t::SetLoopState(GEngineLoopState_t value) {
    SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_LoopState", true, value);
}
double GEventClientPreOutput_t::GetRenderTime() const {
    return GetSchemaValue<double>(m_ptr, "EventClientPreOutput_t", "m_flRenderTime");
}
void GEventClientPreOutput_t::SetRenderTime(double value) {
    SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_flRenderTime", true, value);
}
double GEventClientPreOutput_t::GetRenderFrameTime() const {
    return GetSchemaValue<double>(m_ptr, "EventClientPreOutput_t", "m_flRenderFrameTime");
}
void GEventClientPreOutput_t::SetRenderFrameTime(double value) {
    SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_flRenderFrameTime", true, value);
}
double GEventClientPreOutput_t::GetRenderFrameTimeUnbounded() const {
    return GetSchemaValue<double>(m_ptr, "EventClientPreOutput_t", "m_flRenderFrameTimeUnbounded");
}
void GEventClientPreOutput_t::SetRenderFrameTimeUnbounded(double value) {
    SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_flRenderFrameTimeUnbounded", true, value);
}
float GEventClientPreOutput_t::GetRealTime() const {
    return GetSchemaValue<float>(m_ptr, "EventClientPreOutput_t", "m_flRealTime");
}
void GEventClientPreOutput_t::SetRealTime(float value) {
    SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_flRealTime", true, value);
}
bool GEventClientPreOutput_t::GetRenderOnly() const {
    return GetSchemaValue<bool>(m_ptr, "EventClientPreOutput_t", "m_bRenderOnly");
}
void GEventClientPreOutput_t::SetRenderOnly(bool value) {
    SetSchemaValue(m_ptr, "EventClientPreOutput_t", "m_bRenderOnly", true, value);
}
std::string GEventClientPreOutput_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientPreOutput_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientPreOutput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPreOutput_t>("EventClientPreOutput_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoopState", &GEventClientPreOutput_t::GetLoopState, &GEventClientPreOutput_t::SetLoopState)
        .addProperty("RenderTime", &GEventClientPreOutput_t::GetRenderTime, &GEventClientPreOutput_t::SetRenderTime)
        .addProperty("RenderFrameTime", &GEventClientPreOutput_t::GetRenderFrameTime, &GEventClientPreOutput_t::SetRenderFrameTime)
        .addProperty("RenderFrameTimeUnbounded", &GEventClientPreOutput_t::GetRenderFrameTimeUnbounded, &GEventClientPreOutput_t::SetRenderFrameTimeUnbounded)
        .addProperty("RealTime", &GEventClientPreOutput_t::GetRealTime, &GEventClientPreOutput_t::SetRealTime)
        .addProperty("RenderOnly", &GEventClientPreOutput_t::GetRenderOnly, &GEventClientPreOutput_t::SetRenderOnly)
        .addFunction("ToPtr", &GEventClientPreOutput_t::ToPtr)
        .addFunction("IsValid", &GEventClientPreOutput_t::IsValid)
        .endClass();
}