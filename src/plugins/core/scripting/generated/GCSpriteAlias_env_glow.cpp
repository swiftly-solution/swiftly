#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSpriteAlias_env_glow::GCSpriteAlias_env_glow(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSpriteAlias_env_glow::GCSpriteAlias_env_glow(void *ptr) {
    m_ptr = ptr;
}
std::string GCSpriteAlias_env_glow::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSpriteAlias_env_glow::IsValid() {
    return (m_ptr != nullptr);
}
GCSprite GCSpriteAlias_env_glow::GetParent() const {
    GCSprite value(m_ptr);
    return value;
}
void GCSpriteAlias_env_glow::SetParent(GCSprite value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSpriteAlias_env_glow(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSpriteAlias_env_glow>("CSpriteAlias_env_glow")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSpriteAlias_env_glow::GetParent, &GCSpriteAlias_env_glow::SetParent)
        .addFunction("ToPtr", &GCSpriteAlias_env_glow::ToPtr)
        .addFunction("IsValid", &GCSpriteAlias_env_glow::IsValid)
        .endClass();
}