#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBumpMine::GCBumpMine(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBumpMine::GCBumpMine(void *ptr) {
    m_ptr = ptr;
}
std::string GCBumpMine::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBumpMine::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCBumpMine::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCBumpMine::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBumpMine(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBumpMine>("CBumpMine")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCBumpMine::GetParent, &GCBumpMine::SetParent)
        .addFunction("ToPtr", &GCBumpMine::ToPtr)
        .addFunction("IsValid", &GCBumpMine::IsValid)
        .endClass();
}