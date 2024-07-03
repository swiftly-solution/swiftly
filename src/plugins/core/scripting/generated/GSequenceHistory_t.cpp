#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSequenceHistory_t::GSequenceHistory_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSequenceHistory_t::GSequenceHistory_t(void *ptr) {
    m_ptr = ptr;
}
float GSequenceHistory_t::GetSeqStartTime() const {
    return GetSchemaValue<float>(m_ptr, "SequenceHistory_t", "m_flSeqStartTime");
}
void GSequenceHistory_t::SetSeqStartTime(float value) {
    SetSchemaValue(m_ptr, "SequenceHistory_t", "m_flSeqStartTime", true, value);
}
float GSequenceHistory_t::GetSeqFixedCycle() const {
    return GetSchemaValue<float>(m_ptr, "SequenceHistory_t", "m_flSeqFixedCycle");
}
void GSequenceHistory_t::SetSeqFixedCycle(float value) {
    SetSchemaValue(m_ptr, "SequenceHistory_t", "m_flSeqFixedCycle", true, value);
}
uint64_t GSequenceHistory_t::GetSeqLoopMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "SequenceHistory_t", "m_nSeqLoopMode");
}
void GSequenceHistory_t::SetSeqLoopMode(uint64_t value) {
    SetSchemaValue(m_ptr, "SequenceHistory_t", "m_nSeqLoopMode", true, value);
}
float GSequenceHistory_t::GetPlaybackRate() const {
    return GetSchemaValue<float>(m_ptr, "SequenceHistory_t", "m_flPlaybackRate");
}
void GSequenceHistory_t::SetPlaybackRate(float value) {
    SetSchemaValue(m_ptr, "SequenceHistory_t", "m_flPlaybackRate", true, value);
}
float GSequenceHistory_t::GetCyclesPerSecond() const {
    return GetSchemaValue<float>(m_ptr, "SequenceHistory_t", "m_flCyclesPerSecond");
}
void GSequenceHistory_t::SetCyclesPerSecond(float value) {
    SetSchemaValue(m_ptr, "SequenceHistory_t", "m_flCyclesPerSecond", true, value);
}
std::string GSequenceHistory_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSequenceHistory_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSequenceHistory_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSequenceHistory_t>("SequenceHistory_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SeqStartTime", &GSequenceHistory_t::GetSeqStartTime, &GSequenceHistory_t::SetSeqStartTime)
        .addProperty("SeqFixedCycle", &GSequenceHistory_t::GetSeqFixedCycle, &GSequenceHistory_t::SetSeqFixedCycle)
        .addProperty("SeqLoopMode", &GSequenceHistory_t::GetSeqLoopMode, &GSequenceHistory_t::SetSeqLoopMode)
        .addProperty("PlaybackRate", &GSequenceHistory_t::GetPlaybackRate, &GSequenceHistory_t::SetPlaybackRate)
        .addProperty("CyclesPerSecond", &GSequenceHistory_t::GetCyclesPerSecond, &GSequenceHistory_t::SetCyclesPerSecond)
        .addFunction("ToPtr", &GSequenceHistory_t::ToPtr)
        .addFunction("IsValid", &GSequenceHistory_t::IsValid)
        .endClass();
}