#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvSoundscapeTriggerable::GCEnvSoundscapeTriggerable(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvSoundscapeTriggerable::GCEnvSoundscapeTriggerable(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvSoundscapeTriggerable::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvSoundscapeTriggerable::IsValid() {
    return (m_ptr != nullptr);
}
GCEnvSoundscape GCEnvSoundscapeTriggerable::GetParent() const {
    GCEnvSoundscape value(m_ptr);
    return value;
}
void GCEnvSoundscapeTriggerable::SetParent(GCEnvSoundscape value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvSoundscapeTriggerable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscapeTriggerable>("CEnvSoundscapeTriggerable")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCEnvSoundscapeTriggerable::GetParent, &GCEnvSoundscapeTriggerable::SetParent)
        .addFunction("ToPtr", &GCEnvSoundscapeTriggerable::ToPtr)
        .addFunction("IsValid", &GCEnvSoundscapeTriggerable::IsValid)
        .endClass();
}