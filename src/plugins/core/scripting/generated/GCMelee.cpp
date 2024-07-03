#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMelee::GCMelee(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMelee::GCMelee(void *ptr) {
    m_ptr = ptr;
}
std::string GCMelee::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMelee::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCMelee::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCMelee::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMelee(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMelee>("CMelee")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCMelee::GetParent, &GCMelee::SetParent)
        .addFunction("ToPtr", &GCMelee::ToPtr)
        .addFunction("IsValid", &GCMelee::IsValid)
        .endClass();
}