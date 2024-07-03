#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientProcessGameInput_t::GEventClientProcessGameInput_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientProcessGameInput_t::GEventClientProcessGameInput_t(void *ptr) {
    m_ptr = ptr;
}
GEngineLoopState_t GEventClientProcessGameInput_t::GetLoopState() const {
    GEngineLoopState_t value(GetSchemaPtr(m_ptr, "EventClientProcessGameInput_t", "m_LoopState"));
    return value;
}
void GEventClientProcessGameInput_t::SetLoopState(GEngineLoopState_t value) {
    SetSchemaValue(m_ptr, "EventClientProcessGameInput_t", "m_LoopState", true, value);
}
float GEventClientProcessGameInput_t::GetRealTime() const {
    return GetSchemaValue<float>(m_ptr, "EventClientProcessGameInput_t", "m_flRealTime");
}
void GEventClientProcessGameInput_t::SetRealTime(float value) {
    SetSchemaValue(m_ptr, "EventClientProcessGameInput_t", "m_flRealTime", true, value);
}
float GEventClientProcessGameInput_t::GetFrameTime() const {
    return GetSchemaValue<float>(m_ptr, "EventClientProcessGameInput_t", "m_flFrameTime");
}
void GEventClientProcessGameInput_t::SetFrameTime(float value) {
    SetSchemaValue(m_ptr, "EventClientProcessGameInput_t", "m_flFrameTime", true, value);
}
std::string GEventClientProcessGameInput_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientProcessGameInput_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientProcessGameInput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientProcessGameInput_t>("EventClientProcessGameInput_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoopState", &GEventClientProcessGameInput_t::GetLoopState, &GEventClientProcessGameInput_t::SetLoopState)
        .addProperty("RealTime", &GEventClientProcessGameInput_t::GetRealTime, &GEventClientProcessGameInput_t::SetRealTime)
        .addProperty("FrameTime", &GEventClientProcessGameInput_t::GetFrameTime, &GEventClientProcessGameInput_t::SetFrameTime)
        .addFunction("ToPtr", &GEventClientProcessGameInput_t::ToPtr)
        .addFunction("IsValid", &GEventClientProcessGameInput_t::IsValid)
        .endClass();
}