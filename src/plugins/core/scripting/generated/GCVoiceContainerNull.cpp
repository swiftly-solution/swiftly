#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerNull::GCVoiceContainerNull(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerNull::GCVoiceContainerNull(void *ptr) {
    m_ptr = ptr;
}
std::string GCVoiceContainerNull::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerNull::IsValid() {
    return (m_ptr != nullptr);
}
GCVoiceContainerBase GCVoiceContainerNull::GetParent() const {
    GCVoiceContainerBase value(m_ptr);
    return value;
}
void GCVoiceContainerNull::SetParent(GCVoiceContainerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVoiceContainerNull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerNull>("CVoiceContainerNull")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCVoiceContainerNull::GetParent, &GCVoiceContainerNull::SetParent)
        .addFunction("ToPtr", &GCVoiceContainerNull::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerNull::IsValid)
        .endClass();
}