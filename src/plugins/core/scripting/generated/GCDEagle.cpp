#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDEagle::GCDEagle(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDEagle::GCDEagle(void *ptr) {
    m_ptr = ptr;
}
std::string GCDEagle::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDEagle::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCDEagle::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCDEagle::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDEagle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDEagle>("CDEagle")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCDEagle::GetParent, &GCDEagle::SetParent)
        .addFunction("ToPtr", &GCDEagle::ToPtr)
        .addFunction("IsValid", &GCDEagle::IsValid)
        .endClass();
}