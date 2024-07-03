#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventSimulate_t::GEventSimulate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventSimulate_t::GEventSimulate_t(void *ptr) {
    m_ptr = ptr;
}
GEngineLoopState_t GEventSimulate_t::GetLoopState() const {
    GEngineLoopState_t value(GetSchemaPtr(m_ptr, "EventSimulate_t", "m_LoopState"));
    return value;
}
void GEventSimulate_t::SetLoopState(GEngineLoopState_t value) {
    SetSchemaValue(m_ptr, "EventSimulate_t", "m_LoopState", true, value);
}
bool GEventSimulate_t::GetFirstTick() const {
    return GetSchemaValue<bool>(m_ptr, "EventSimulate_t", "m_bFirstTick");
}
void GEventSimulate_t::SetFirstTick(bool value) {
    SetSchemaValue(m_ptr, "EventSimulate_t", "m_bFirstTick", true, value);
}
bool GEventSimulate_t::GetLastTick() const {
    return GetSchemaValue<bool>(m_ptr, "EventSimulate_t", "m_bLastTick");
}
void GEventSimulate_t::SetLastTick(bool value) {
    SetSchemaValue(m_ptr, "EventSimulate_t", "m_bLastTick", true, value);
}
std::string GEventSimulate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventSimulate_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventSimulate_t>("EventSimulate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoopState", &GEventSimulate_t::GetLoopState, &GEventSimulate_t::SetLoopState)
        .addProperty("FirstTick", &GEventSimulate_t::GetFirstTick, &GEventSimulate_t::SetFirstTick)
        .addProperty("LastTick", &GEventSimulate_t::GetLastTick, &GEventSimulate_t::SetLastTick)
        .addFunction("ToPtr", &GEventSimulate_t::ToPtr)
        .addFunction("IsValid", &GEventSimulate_t::IsValid)
        .endClass();
}