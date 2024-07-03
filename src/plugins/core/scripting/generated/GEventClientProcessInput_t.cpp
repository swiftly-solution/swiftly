#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientProcessInput_t::GEventClientProcessInput_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientProcessInput_t::GEventClientProcessInput_t(void *ptr) {
    m_ptr = ptr;
}
GEngineLoopState_t GEventClientProcessInput_t::GetLoopState() const {
    GEngineLoopState_t value(GetSchemaPtr(m_ptr, "EventClientProcessInput_t", "m_LoopState"));
    return value;
}
void GEventClientProcessInput_t::SetLoopState(GEngineLoopState_t value) {
    SetSchemaValue(m_ptr, "EventClientProcessInput_t", "m_LoopState", true, value);
}
float GEventClientProcessInput_t::GetRealTime() const {
    return GetSchemaValue<float>(m_ptr, "EventClientProcessInput_t", "m_flRealTime");
}
void GEventClientProcessInput_t::SetRealTime(float value) {
    SetSchemaValue(m_ptr, "EventClientProcessInput_t", "m_flRealTime", true, value);
}
float GEventClientProcessInput_t::GetTickInterval() const {
    return GetSchemaValue<float>(m_ptr, "EventClientProcessInput_t", "m_flTickInterval");
}
void GEventClientProcessInput_t::SetTickInterval(float value) {
    SetSchemaValue(m_ptr, "EventClientProcessInput_t", "m_flTickInterval", true, value);
}
double GEventClientProcessInput_t::GetTickStartTime() const {
    return GetSchemaValue<double>(m_ptr, "EventClientProcessInput_t", "m_flTickStartTime");
}
void GEventClientProcessInput_t::SetTickStartTime(double value) {
    SetSchemaValue(m_ptr, "EventClientProcessInput_t", "m_flTickStartTime", true, value);
}
std::string GEventClientProcessInput_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientProcessInput_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientProcessInput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientProcessInput_t>("EventClientProcessInput_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoopState", &GEventClientProcessInput_t::GetLoopState, &GEventClientProcessInput_t::SetLoopState)
        .addProperty("RealTime", &GEventClientProcessInput_t::GetRealTime, &GEventClientProcessInput_t::SetRealTime)
        .addProperty("TickInterval", &GEventClientProcessInput_t::GetTickInterval, &GEventClientProcessInput_t::SetTickInterval)
        .addProperty("TickStartTime", &GEventClientProcessInput_t::GetTickStartTime, &GEventClientProcessInput_t::SetTickStartTime)
        .addFunction("ToPtr", &GEventClientProcessInput_t::ToPtr)
        .addFunction("IsValid", &GEventClientProcessInput_t::IsValid)
        .endClass();
}