#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventClientFrameSimulate_t::GEventClientFrameSimulate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventClientFrameSimulate_t::GEventClientFrameSimulate_t(void *ptr) {
    m_ptr = ptr;
}
GEngineLoopState_t GEventClientFrameSimulate_t::GetLoopState() const {
    GEngineLoopState_t value(GetSchemaPtr(m_ptr, "EventClientFrameSimulate_t", "m_LoopState"));
    return value;
}
void GEventClientFrameSimulate_t::SetLoopState(GEngineLoopState_t value) {
    SetSchemaValue(m_ptr, "EventClientFrameSimulate_t", "m_LoopState", true, value);
}
float GEventClientFrameSimulate_t::GetRealTime() const {
    return GetSchemaValue<float>(m_ptr, "EventClientFrameSimulate_t", "m_flRealTime");
}
void GEventClientFrameSimulate_t::SetRealTime(float value) {
    SetSchemaValue(m_ptr, "EventClientFrameSimulate_t", "m_flRealTime", true, value);
}
float GEventClientFrameSimulate_t::GetFrameTime() const {
    return GetSchemaValue<float>(m_ptr, "EventClientFrameSimulate_t", "m_flFrameTime");
}
void GEventClientFrameSimulate_t::SetFrameTime(float value) {
    SetSchemaValue(m_ptr, "EventClientFrameSimulate_t", "m_flFrameTime", true, value);
}
double GEventClientFrameSimulate_t::GetWhenScheduleSendTickPacket() const {
    return GetSchemaValue<double>(m_ptr, "EventClientFrameSimulate_t", "m_flWhenScheduleSendTickPacket");
}
void GEventClientFrameSimulate_t::SetWhenScheduleSendTickPacket(double value) {
    SetSchemaValue(m_ptr, "EventClientFrameSimulate_t", "m_flWhenScheduleSendTickPacket", true, value);
}
std::string GEventClientFrameSimulate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventClientFrameSimulate_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventClientFrameSimulate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventClientFrameSimulate_t>("EventClientFrameSimulate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LoopState", &GEventClientFrameSimulate_t::GetLoopState, &GEventClientFrameSimulate_t::SetLoopState)
        .addProperty("RealTime", &GEventClientFrameSimulate_t::GetRealTime, &GEventClientFrameSimulate_t::SetRealTime)
        .addProperty("FrameTime", &GEventClientFrameSimulate_t::GetFrameTime, &GEventClientFrameSimulate_t::SetFrameTime)
        .addProperty("WhenScheduleSendTickPacket", &GEventClientFrameSimulate_t::GetWhenScheduleSendTickPacket, &GEventClientFrameSimulate_t::SetWhenScheduleSendTickPacket)
        .addFunction("ToPtr", &GEventClientFrameSimulate_t::ToPtr)
        .addFunction("IsValid", &GEventClientFrameSimulate_t::IsValid)
        .endClass();
}