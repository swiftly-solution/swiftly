#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCIncendiaryGrenade::GCIncendiaryGrenade(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCIncendiaryGrenade::GCIncendiaryGrenade(void *ptr) {
    m_ptr = ptr;
}
std::string GCIncendiaryGrenade::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCIncendiaryGrenade::IsValid() {
    return (m_ptr != nullptr);
}
GCMolotovGrenade GCIncendiaryGrenade::GetParent() const {
    GCMolotovGrenade value(m_ptr);
    return value;
}
void GCIncendiaryGrenade::SetParent(GCMolotovGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCIncendiaryGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCIncendiaryGrenade>("CIncendiaryGrenade")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCIncendiaryGrenade::GetParent, &GCIncendiaryGrenade::SetParent)
        .addFunction("ToPtr", &GCIncendiaryGrenade::ToPtr)
        .addFunction("IsValid", &GCIncendiaryGrenade::IsValid)
        .endClass();
}