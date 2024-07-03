#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerActiveWeaponDetect::GCTriggerActiveWeaponDetect(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerActiveWeaponDetect::GCTriggerActiveWeaponDetect(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCTriggerActiveWeaponDetect::GetOnTouchedActiveWeapon() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerActiveWeaponDetect", "m_OnTouchedActiveWeapon"));
    return value;
}
void GCTriggerActiveWeaponDetect::SetOnTouchedActiveWeapon(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerActiveWeaponDetect", "m_OnTouchedActiveWeapon", false, value);
}
std::string GCTriggerActiveWeaponDetect::GetWeaponClassName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerActiveWeaponDetect", "m_iszWeaponClassName").String();
}
void GCTriggerActiveWeaponDetect::SetWeaponClassName(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerActiveWeaponDetect", "m_iszWeaponClassName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCTriggerActiveWeaponDetect::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerActiveWeaponDetect::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerActiveWeaponDetect::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerActiveWeaponDetect::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerActiveWeaponDetect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerActiveWeaponDetect>("CTriggerActiveWeaponDetect")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnTouchedActiveWeapon", &GCTriggerActiveWeaponDetect::GetOnTouchedActiveWeapon, &GCTriggerActiveWeaponDetect::SetOnTouchedActiveWeapon)
        .addProperty("WeaponClassName", &GCTriggerActiveWeaponDetect::GetWeaponClassName, &GCTriggerActiveWeaponDetect::SetWeaponClassName)
        .addProperty("Parent", &GCTriggerActiveWeaponDetect::GetParent, &GCTriggerActiveWeaponDetect::SetParent)
        .addFunction("ToPtr", &GCTriggerActiveWeaponDetect::ToPtr)
        .addFunction("IsValid", &GCTriggerActiveWeaponDetect::IsValid)
        .endClass();
}