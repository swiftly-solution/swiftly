#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponM249::GCWeaponM249(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponM249::GCWeaponM249(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponM249::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponM249::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponM249::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponM249::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponM249(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponM249>("CWeaponM249")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponM249::GetParent, &GCWeaponM249::SetParent)
        .addFunction("ToPtr", &GCWeaponM249::ToPtr)
        .addFunction("IsValid", &GCWeaponM249::IsValid)
        .endClass();
}