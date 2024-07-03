#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvCubemapBox::GCEnvCubemapBox(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvCubemapBox::GCEnvCubemapBox(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvCubemapBox::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvCubemapBox::IsValid() {
    return (m_ptr != nullptr);
}
GCEnvCubemap GCEnvCubemapBox::GetParent() const {
    GCEnvCubemap value(m_ptr);
    return value;
}
void GCEnvCubemapBox::SetParent(GCEnvCubemap value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvCubemapBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvCubemapBox>("CEnvCubemapBox")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCEnvCubemapBox::GetParent, &GCEnvCubemapBox::SetParent)
        .addFunction("ToPtr", &GCEnvCubemapBox::ToPtr)
        .addFunction("IsValid", &GCEnvCubemapBox::IsValid)
        .endClass();
}