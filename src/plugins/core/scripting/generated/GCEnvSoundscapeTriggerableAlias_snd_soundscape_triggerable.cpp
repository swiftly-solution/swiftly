#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable::GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable::GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable::IsValid() {
    return (m_ptr != nullptr);
}
GCEnvSoundscapeTriggerable GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable::GetParent() const {
    GCEnvSoundscapeTriggerable value(m_ptr);
    return value;
}
void GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable::SetParent(GCEnvSoundscapeTriggerable value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable>("CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable::GetParent, &GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable::SetParent)
        .addFunction("ToPtr", &GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable::ToPtr)
        .addFunction("IsValid", &GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable::IsValid)
        .endClass();
}