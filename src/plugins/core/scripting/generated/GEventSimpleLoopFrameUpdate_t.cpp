#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventSimpleLoopFrameUpdate_t::GEventSimpleLoopFrameUpdate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventSimpleLoopFrameUpdate_t::GEventSimpleLoopFrameUpdate_t(void *ptr) {
    m_ptr = ptr;
}
GEngineLoopState_t GEventSimpleLoopFrameUpdate_t::GetLoopState() const {
    GEngineLoopState_t value(GetSchemaPtr(m_ptr, "EventSimpleLoopFrameUpdate_t", "m_LoopState"));
    return value;
}
void GEventSimpleLoopFrameUpdate_t::SetLoopState(GEngineLoopState_t value) {
    SetSchemaValue(m_ptr, "EventSimpleLoopFrameUpdate_t", "m_LoopState", true, value);
}
float GEventSimpleLoopFrameUpdate_t::GetRealTime() const {
    return GetSchemaValue<float>(m_ptr, "EventSimpleLoopFrameUpdate_t", "m_flRealTime");
}
void GEventSimpleLoopFrameUpdate_t::SetRealTime(float value) {
    SetSchemaValue(m_ptr, "EventSimpleLoopFrameUpdate_t", "m_flRealTime", true, value);
}
float GEventSimpleLoopFrameUpdate_t::GetFrameTime() const {
    return GetSchemaValue<float>(m_ptr, "EventSimpleLoopFrameUpdate_t", "m_flFrameTime");
}
void GEventSimpleLoopFrameUpdate_t::SetFrameTime(float value) {
    SetSchemaValue(m_ptr, "EventSimpleLoopFrameUpdate_t", "m_flFrameTime", true, value);
}
std::string GEventSimpleLoopFrameUpdate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventSimpleLoopFrameUpdate_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventSimpleLoopFrameUpdate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventSimpleLoopFrameUpdate_t>("EventSimpleLoopFrameUpdate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoopState", &GEventSimpleLoopFrameUpdate_t::GetLoopState, &GEventSimpleLoopFrameUpdate_t::SetLoopState)
        .addProperty("RealTime", &GEventSimpleLoopFrameUpdate_t::GetRealTime, &GEventSimpleLoopFrameUpdate_t::SetRealTime)
        .addProperty("FrameTime", &GEventSimpleLoopFrameUpdate_t::GetFrameTime, &GEventSimpleLoopFrameUpdate_t::SetFrameTime)
        .addFunction("ToPtr", &GEventSimpleLoopFrameUpdate_t::ToPtr)
        .addFunction("IsValid", &GEventSimpleLoopFrameUpdate_t::IsValid)
        .endClass();
}