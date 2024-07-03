#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponBaseItem::GCWeaponBaseItem(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponBaseItem::GCWeaponBaseItem(void *ptr) {
    m_ptr = ptr;
}
GCountdownTimer GCWeaponBaseItem::GetSequenceCompleteTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CWeaponBaseItem", "m_SequenceCompleteTimer"));
    return value;
}
void GCWeaponBaseItem::SetSequenceCompleteTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CWeaponBaseItem", "m_SequenceCompleteTimer", false, value);
}
bool GCWeaponBaseItem::GetRedraw() const {
    return GetSchemaValue<bool>(m_ptr, "CWeaponBaseItem", "m_bRedraw");
}
void GCWeaponBaseItem::SetRedraw(bool value) {
    SetSchemaValue(m_ptr, "CWeaponBaseItem", "m_bRedraw", false, value);
}
std::string GCWeaponBaseItem::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponBaseItem::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCWeaponBaseItem::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCWeaponBaseItem::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponBaseItem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponBaseItem>("CWeaponBaseItem")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SequenceCompleteTimer", &GCWeaponBaseItem::GetSequenceCompleteTimer, &GCWeaponBaseItem::SetSequenceCompleteTimer)
        .addProperty("Redraw", &GCWeaponBaseItem::GetRedraw, &GCWeaponBaseItem::SetRedraw)
        .addProperty("Parent", &GCWeaponBaseItem::GetParent, &GCWeaponBaseItem::SetParent)
        .addFunction("ToPtr", &GCWeaponBaseItem::ToPtr)
        .addFunction("IsValid", &GCWeaponBaseItem::IsValid)
        .endClass();
}