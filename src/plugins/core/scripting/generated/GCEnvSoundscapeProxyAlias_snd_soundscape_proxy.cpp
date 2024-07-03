#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvSoundscapeProxyAlias_snd_soundscape_proxy::GCEnvSoundscapeProxyAlias_snd_soundscape_proxy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvSoundscapeProxyAlias_snd_soundscape_proxy::GCEnvSoundscapeProxyAlias_snd_soundscape_proxy(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvSoundscapeProxyAlias_snd_soundscape_proxy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvSoundscapeProxyAlias_snd_soundscape_proxy::IsValid() {
    return (m_ptr != nullptr);
}
GCEnvSoundscapeProxy GCEnvSoundscapeProxyAlias_snd_soundscape_proxy::GetParent() const {
    GCEnvSoundscapeProxy value(m_ptr);
    return value;
}
void GCEnvSoundscapeProxyAlias_snd_soundscape_proxy::SetParent(GCEnvSoundscapeProxy value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvSoundscapeProxyAlias_snd_soundscape_proxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscapeProxyAlias_snd_soundscape_proxy>("CEnvSoundscapeProxyAlias_snd_soundscape_proxy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCEnvSoundscapeProxyAlias_snd_soundscape_proxy::GetParent, &GCEnvSoundscapeProxyAlias_snd_soundscape_proxy::SetParent)
        .addFunction("ToPtr", &GCEnvSoundscapeProxyAlias_snd_soundscape_proxy::ToPtr)
        .addFunction("IsValid", &GCEnvSoundscapeProxyAlias_snd_soundscape_proxy::IsValid)
        .endClass();
}