#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientOutput_t::GEventClientOutput_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientOutput_t::GEventClientOutput_t(void *ptr) {
    m_ptr = ptr;
}
GEngineLoopState_t GEventClientOutput_t::GetLoopState() const {
    GEngineLoopState_t value(GetSchemaPtr(m_ptr, "EventClientOutput_t", "m_LoopState"));
    return value;
}
void GEventClientOutput_t::SetLoopState(GEngineLoopState_t value) {
    SetSchemaValue(m_ptr, "EventClientOutput_t", "m_LoopState", true, value);
}
float GEventClientOutput_t::GetRenderTime() const {
    return GetSchemaValue<float>(m_ptr, "EventClientOutput_t", "m_flRenderTime");
}
void GEventClientOutput_t::SetRenderTime(float value) {
    SetSchemaValue(m_ptr, "EventClientOutput_t", "m_flRenderTime", true, value);
}
float GEventClientOutput_t::GetRealTime() const {
    return GetSchemaValue<float>(m_ptr, "EventClientOutput_t", "m_flRealTime");
}
void GEventClientOutput_t::SetRealTime(float value) {
    SetSchemaValue(m_ptr, "EventClientOutput_t", "m_flRealTime", true, value);
}
float GEventClientOutput_t::GetRenderFrameTimeUnbounded() const {
    return GetSchemaValue<float>(m_ptr, "EventClientOutput_t", "m_flRenderFrameTimeUnbounded");
}
void GEventClientOutput_t::SetRenderFrameTimeUnbounded(float value) {
    SetSchemaValue(m_ptr, "EventClientOutput_t", "m_flRenderFrameTimeUnbounded", true, value);
}
bool GEventClientOutput_t::GetRenderOnly() const {
    return GetSchemaValue<bool>(m_ptr, "EventClientOutput_t", "m_bRenderOnly");
}
void GEventClientOutput_t::SetRenderOnly(bool value) {
    SetSchemaValue(m_ptr, "EventClientOutput_t", "m_bRenderOnly", true, value);
}
std::string GEventClientOutput_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientOutput_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientOutput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientOutput_t>("EventClientOutput_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoopState", &GEventClientOutput_t::GetLoopState, &GEventClientOutput_t::SetLoopState)
        .addProperty("RenderTime", &GEventClientOutput_t::GetRenderTime, &GEventClientOutput_t::SetRenderTime)
        .addProperty("RealTime", &GEventClientOutput_t::GetRealTime, &GEventClientOutput_t::SetRealTime)
        .addProperty("RenderFrameTimeUnbounded", &GEventClientOutput_t::GetRenderFrameTimeUnbounded, &GEventClientOutput_t::SetRenderFrameTimeUnbounded)
        .addProperty("RenderOnly", &GEventClientOutput_t::GetRenderOnly, &GEventClientOutput_t::SetRenderOnly)
        .addFunction("ToPtr", &GEventClientOutput_t::ToPtr)
        .addFunction("IsValid", &GEventClientOutput_t::IsValid)
        .endClass();
}