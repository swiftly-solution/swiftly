#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSpriteOriented::GCSpriteOriented(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSpriteOriented::GCSpriteOriented(void *ptr) {
    m_ptr = ptr;
}
std::string GCSpriteOriented::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSpriteOriented::IsValid() {
    return (m_ptr != nullptr);
}
GCSprite GCSpriteOriented::GetParent() const {
    GCSprite value(m_ptr);
    return value;
}
void GCSpriteOriented::SetParent(GCSprite value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSpriteOriented(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSpriteOriented>("CSpriteOriented")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSpriteOriented::GetParent, &GCSpriteOriented::SetParent)
        .addFunction("ToPtr", &GCSpriteOriented::ToPtr)
        .addFunction("IsValid", &GCSpriteOriented::IsValid)
        .endClass();
}