#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCKnife::GCKnife(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCKnife::GCKnife(void *ptr) {
    m_ptr = ptr;
}
bool GCKnife::GetFirstAttack() const {
    return GetSchemaValue<bool>(m_ptr, "CKnife", "m_bFirstAttack");
}
void GCKnife::SetFirstAttack(bool value) {
    SetSchemaValue(m_ptr, "CKnife", "m_bFirstAttack", false, value);
}
std::string GCKnife::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCKnife::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCKnife::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCKnife::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCKnife(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCKnife>("CKnife")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FirstAttack", &GCKnife::GetFirstAttack, &GCKnife::SetFirstAttack)
        .addProperty("Parent", &GCKnife::GetParent, &GCKnife::SetParent)
        .addFunction("ToPtr", &GCKnife::ToPtr)
        .addFunction("IsValid", &GCKnife::IsValid)
        .endClass();
}