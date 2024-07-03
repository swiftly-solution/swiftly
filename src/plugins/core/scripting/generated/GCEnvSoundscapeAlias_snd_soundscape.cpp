#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvSoundscapeAlias_snd_soundscape::GCEnvSoundscapeAlias_snd_soundscape(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvSoundscapeAlias_snd_soundscape::GCEnvSoundscapeAlias_snd_soundscape(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvSoundscapeAlias_snd_soundscape::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvSoundscapeAlias_snd_soundscape::IsValid() {
    return (m_ptr != nullptr);
}
GCEnvSoundscape GCEnvSoundscapeAlias_snd_soundscape::GetParent() const {
    GCEnvSoundscape value(m_ptr);
    return value;
}
void GCEnvSoundscapeAlias_snd_soundscape::SetParent(GCEnvSoundscape value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvSoundscapeAlias_snd_soundscape(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscapeAlias_snd_soundscape>("CEnvSoundscapeAlias_snd_soundscape")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCEnvSoundscapeAlias_snd_soundscape::GetParent, &GCEnvSoundscapeAlias_snd_soundscape::SetParent)
        .addFunction("ToPtr", &GCEnvSoundscapeAlias_snd_soundscape::ToPtr)
        .addFunction("IsValid", &GCEnvSoundscapeAlias_snd_soundscape::IsValid)
        .endClass();
}