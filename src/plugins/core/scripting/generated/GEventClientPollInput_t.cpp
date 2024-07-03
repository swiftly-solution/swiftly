#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientPollInput_t::GEventClientPollInput_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientPollInput_t::GEventClientPollInput_t(void *ptr) {
    m_ptr = ptr;
}
GEngineLoopState_t GEventClientPollInput_t::GetLoopState() const {
    GEngineLoopState_t value(GetSchemaPtr(m_ptr, "EventClientPollInput_t", "m_LoopState"));
    return value;
}
void GEventClientPollInput_t::SetLoopState(GEngineLoopState_t value) {
    SetSchemaValue(m_ptr, "EventClientPollInput_t", "m_LoopState", true, value);
}
float GEventClientPollInput_t::GetRealTime() const {
    return GetSchemaValue<float>(m_ptr, "EventClientPollInput_t", "m_flRealTime");
}
void GEventClientPollInput_t::SetRealTime(float value) {
    SetSchemaValue(m_ptr, "EventClientPollInput_t", "m_flRealTime", true, value);
}
std::string GEventClientPollInput_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientPollInput_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientPollInput_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientPollInput_t>("EventClientPollInput_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoopState", &GEventClientPollInput_t::GetLoopState, &GEventClientPollInput_t::SetLoopState)
        .addProperty("RealTime", &GEventClientPollInput_t::GetRealTime, &GEventClientPollInput_t::SetRealTime)
        .addFunction("ToPtr", &GEventClientPollInput_t::ToPtr)
        .addFunction("IsValid", &GEventClientPollInput_t::IsValid)
        .endClass();
}