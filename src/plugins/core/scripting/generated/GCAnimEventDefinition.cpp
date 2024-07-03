#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimEventDefinition::GCAnimEventDefinition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimEventDefinition::GCAnimEventDefinition(void *ptr) {
    m_ptr = ptr;
}
int32_t GCAnimEventDefinition::GetFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimEventDefinition", "m_nFrame");
}
void GCAnimEventDefinition::SetFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimEventDefinition", "m_nFrame", false, value);
}
int32_t GCAnimEventDefinition::GetEndFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimEventDefinition", "m_nEndFrame");
}
void GCAnimEventDefinition::SetEndFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimEventDefinition", "m_nEndFrame", false, value);
}
float GCAnimEventDefinition::GetCycle() const {
    return GetSchemaValue<float>(m_ptr, "CAnimEventDefinition", "m_flCycle");
}
void GCAnimEventDefinition::SetCycle(float value) {
    SetSchemaValue(m_ptr, "CAnimEventDefinition", "m_flCycle", false, value);
}
float GCAnimEventDefinition::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CAnimEventDefinition", "m_flDuration");
}
void GCAnimEventDefinition::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CAnimEventDefinition", "m_flDuration", false, value);
}
CBufferString GCAnimEventDefinition::GetLegacyOptions() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimEventDefinition", "m_sLegacyOptions");
}
void GCAnimEventDefinition::SetLegacyOptions(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimEventDefinition", "m_sLegacyOptions", false, value);
}
std::string GCAnimEventDefinition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimEventDefinition::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimEventDefinition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEventDefinition>("CAnimEventDefinition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Frame", &GCAnimEventDefinition::GetFrame, &GCAnimEventDefinition::SetFrame)
        .addProperty("EndFrame", &GCAnimEventDefinition::GetEndFrame, &GCAnimEventDefinition::SetEndFrame)
        .addProperty("Cycle", &GCAnimEventDefinition::GetCycle, &GCAnimEventDefinition::SetCycle)
        .addProperty("Duration", &GCAnimEventDefinition::GetDuration, &GCAnimEventDefinition::SetDuration)
        .addProperty("LegacyOptions", &GCAnimEventDefinition::GetLegacyOptions, &GCAnimEventDefinition::SetLegacyOptions)
        .addFunction("ToPtr", &GCAnimEventDefinition::ToPtr)
        .addFunction("IsValid", &GCAnimEventDefinition::IsValid)
        .endClass();
}