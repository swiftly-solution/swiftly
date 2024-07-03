#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSSprite::GCCSSprite(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSSprite::GCCSSprite(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSSprite::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSSprite::IsValid() {
    return (m_ptr != nullptr);
}
GCSprite GCCSSprite::GetParent() const {
    GCSprite value(m_ptr);
    return value;
}
void GCCSSprite::SetParent(GCSprite value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSSprite(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSSprite>("CCSSprite")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSSprite::GetParent, &GCCSSprite::SetParent)
        .addFunction("ToPtr", &GCCSSprite::ToPtr)
        .addFunction("IsValid", &GCCSSprite::IsValid)
        .endClass();
}