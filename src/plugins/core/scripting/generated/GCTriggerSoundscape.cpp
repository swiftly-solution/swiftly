#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerSoundscape::GCTriggerSoundscape(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerSoundscape::GCTriggerSoundscape(void *ptr) {
    m_ptr = ptr;
}
GCEnvSoundscapeTriggerable GCTriggerSoundscape::GetSoundscape() const {
    GCEnvSoundscapeTriggerable value(*GetSchemaValuePtr<void*>(m_ptr, "CTriggerSoundscape", "m_hSoundscape"));
    return value;
}
void GCTriggerSoundscape::SetSoundscape(GCEnvSoundscapeTriggerable* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Soundscape' is not possible.\n");
}
std::string GCTriggerSoundscape::GetSoundscapeName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerSoundscape", "m_SoundscapeName").String();
}
void GCTriggerSoundscape::SetSoundscapeName(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerSoundscape", "m_SoundscapeName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCTriggerSoundscape::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerSoundscape::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerSoundscape::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerSoundscape::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerSoundscape(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerSoundscape>("CTriggerSoundscape")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Soundscape", &GCTriggerSoundscape::GetSoundscape, &GCTriggerSoundscape::SetSoundscape)
        .addProperty("SoundscapeName", &GCTriggerSoundscape::GetSoundscapeName, &GCTriggerSoundscape::SetSoundscapeName)
        .addProperty("Parent", &GCTriggerSoundscape::GetParent, &GCTriggerSoundscape::SetParent)
        .addFunction("ToPtr", &GCTriggerSoundscape::ToPtr)
        .addFunction("IsValid", &GCTriggerSoundscape::IsValid)
        .endClass();
}