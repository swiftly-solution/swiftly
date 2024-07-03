#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAK47::GCAK47(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAK47::GCAK47(void *ptr) {
    m_ptr = ptr;
}
std::string GCAK47::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAK47::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCAK47::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCAK47::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAK47(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAK47>("CAK47")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCAK47::GetParent, &GCAK47::SetParent)
        .addFunction("ToPtr", &GCAK47::ToPtr)
        .addFunction("IsValid", &GCAK47::IsValid)
        .endClass();
}