#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCVoiceContainerDefault::GCVoiceContainerDefault(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCVoiceContainerDefault::GCVoiceContainerDefault(void *ptr) {
    m_ptr = ptr;
}
std::string GCVoiceContainerDefault::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCVoiceContainerDefault::IsValid() {
    return (m_ptr != nullptr);
}
GCVoiceContainerBase GCVoiceContainerDefault::GetParent() const {
    GCVoiceContainerBase value(m_ptr);
    return value;
}
void GCVoiceContainerDefault::SetParent(GCVoiceContainerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCVoiceContainerDefault(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerDefault>("CVoiceContainerDefault")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCVoiceContainerDefault::GetParent, &GCVoiceContainerDefault::SetParent)
        .addFunction("ToPtr", &GCVoiceContainerDefault::ToPtr)
        .addFunction("IsValid", &GCVoiceContainerDefault::IsValid)
        .endClass();
}