#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientPostOutput_t::GEventClientPostOutput_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientPostOutput_t::GEventClientPostOutput_t(void *ptr) {
    m_ptr = ptr;
}
GEngineLoopState_t GEventClientPostOutput_t::GetLoopState() const {
    GEngineLoopState_t value(GetSchemaPtr(m_ptr, "EventClientPostOutput_t", "m_LoopState"));
    return value;
}
void GEventClientPostOutput_t::SetLoopState(GEngineLoopState_t value) {
    SetSchemaValue(m_ptr, "EventClientPostOutput_t", "m_LoopState", true, value);
}
double GEventClientPostOutput_t::GetRenderTime() const {
    return GetSchemaValue<double>(m_ptr, "EventClientPostOutput_t", "m_flRenderTime");
}
void GEventClientPostOutput_t::SetRenderTime(double value) {
    SetSchemaValue(m_ptr, "EventClientPostOutput_t", "m_flRenderTime", true, value);
}
float GEventClientPostOutput_t::GetRenderFrameTime() const {
    return GetSchemaValue<float>(m_ptr, "EventClientPostOutput_t", "m_flRenderFrameTime");
}
void GEventClientPostOutput_t::SetRenderFrameTime(float value) {
    SetSchemaValue(m_ptr, "EventClientPostOutput_t", "m_flRenderFrameTime", true, value);
}
float GEventClientPostOutput_t::GetRenderFrameTimeUnbounded() const {
    return GetSchemaValue<float>(m_ptr, "EventClientPostOutput_t", "m_flRenderFrameTimeUnbounded");
}
void GEventClientPostOutput_t::SetRenderFrameTimeUnbounded(float value) {
    SetSchemaValue(m_ptr, "EventClientPostOutput_t", "m_flRenderFrameTimeUnbounded", true, value);
}
bool GEventClientPostOutput_t::GetRenderOnly() const {
    return GetSchemaValue<bool>(m_ptr, "EventClientPostOutput_t", "m_bRenderOnly");
}
void GEventClientPostOutput_t::SetRenderOnly(bool value) {
    SetSchemaValue(m_ptr, "EventClientPostOutput_t", "m_bRenderOnly", true, value);
}
std::string GEventClientPostOutput_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientPostOutput_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientPostOutput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPostOutput_t>("EventClientPostOutput_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoopState", &GEventClientPostOutput_t::GetLoopState, &GEventClientPostOutput_t::SetLoopState)
        .addProperty("RenderTime", &GEventClientPostOutput_t::GetRenderTime, &GEventClientPostOutput_t::SetRenderTime)
        .addProperty("RenderFrameTime", &GEventClientPostOutput_t::GetRenderFrameTime, &GEventClientPostOutput_t::SetRenderFrameTime)
        .addProperty("RenderFrameTimeUnbounded", &GEventClientPostOutput_t::GetRenderFrameTimeUnbounded, &GEventClientPostOutput_t::SetRenderFrameTimeUnbounded)
        .addProperty("RenderOnly", &GEventClientPostOutput_t::GetRenderOnly, &GEventClientPostOutput_t::SetRenderOnly)
        .addFunction("ToPtr", &GEventClientPostOutput_t::ToPtr)
        .addFunction("IsValid", &GEventClientPostOutput_t::IsValid)
        .endClass();
}