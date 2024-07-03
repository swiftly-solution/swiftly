#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerSelector::GCVoiceContainerSelector(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerSelector::GCVoiceContainerSelector(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCVoiceContainerSelector::GetMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CVoiceContainerSelector", "m_mode");
}
void GCVoiceContainerSelector::SetMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CVoiceContainerSelector", "m_mode", false, value);
}
bool GCVoiceContainerSelector::GetRetrigger() const {
    return GetSchemaValue<bool>(m_ptr, "CVoiceContainerSelector", "m_bRetrigger");
}
void GCVoiceContainerSelector::SetRetrigger(bool value) {
    SetSchemaValue(m_ptr, "CVoiceContainerSelector", "m_bRetrigger", false, value);
}
std::string GCVoiceContainerSelector::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerSelector::IsValid() {
    return (m_ptr != nullptr);
}
GCVoiceContainerBase GCVoiceContainerSelector::GetParent() const {
    GCVoiceContainerBase value(m_ptr);
    return value;
}
void GCVoiceContainerSelector::SetParent(GCVoiceContainerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVoiceContainerSelector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerSelector>("CVoiceContainerSelector")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Mode", &GCVoiceContainerSelector::GetMode, &GCVoiceContainerSelector::SetMode)
        .addProperty("Retrigger", &GCVoiceContainerSelector::GetRetrigger, &GCVoiceContainerSelector::SetRetrigger)
        .addProperty("Parent", &GCVoiceContainerSelector::GetParent, &GCVoiceContainerSelector::SetParent)
        .addFunction("ToPtr", &GCVoiceContainerSelector::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerSelector::IsValid)
        .endClass();
}