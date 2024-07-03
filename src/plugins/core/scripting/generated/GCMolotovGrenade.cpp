#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMolotovGrenade::GCMolotovGrenade(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMolotovGrenade::GCMolotovGrenade(void *ptr) {
    m_ptr = ptr;
}
std::string GCMolotovGrenade::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMolotovGrenade::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenade GCMolotovGrenade::GetParent() const {
    GCBaseCSGrenade value(m_ptr);
    return value;
}
void GCMolotovGrenade::SetParent(GCBaseCSGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMolotovGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMolotovGrenade>("CMolotovGrenade")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCMolotovGrenade::GetParent, &GCMolotovGrenade::SetParent)
        .addFunction("ToPtr", &GCMolotovGrenade::ToPtr)
        .addFunction("IsValid", &GCMolotovGrenade::IsValid)
        .endClass();
}