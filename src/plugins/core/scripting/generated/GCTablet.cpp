#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTablet::GCTablet(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTablet::GCTablet(void *ptr) {
    m_ptr = ptr;
}
std::string GCTablet::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTablet::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCTablet::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCTablet::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTablet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTablet>("CTablet")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTablet::GetParent, &GCTablet::SetParent)
        .addFunction("ToPtr", &GCTablet::ToPtr)
        .addFunction("IsValid", &GCTablet::IsValid)
        .endClass();
}