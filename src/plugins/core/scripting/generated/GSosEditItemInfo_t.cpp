#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSosEditItemInfo_t::GSosEditItemInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSosEditItemInfo_t::GSosEditItemInfo_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GSosEditItemInfo_t::GetItemType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "SosEditItemInfo_t", "itemType");
}
void GSosEditItemInfo_t::SetItemType(uint64_t value) {
    SetSchemaValue(m_ptr, "SosEditItemInfo_t", "itemType", true, value);
}
std::string GSosEditItemInfo_t::GetItemName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "SosEditItemInfo_t", "itemName").Get();
}
void GSosEditItemInfo_t::SetItemName(std::string value) {
    SetSchemaValue(m_ptr, "SosEditItemInfo_t", "itemName", true, CUtlString(value.c_str()));
}
std::string GSosEditItemInfo_t::GetItemTypeName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "SosEditItemInfo_t", "itemTypeName").Get();
}
void GSosEditItemInfo_t::SetItemTypeName(std::string value) {
    SetSchemaValue(m_ptr, "SosEditItemInfo_t", "itemTypeName", true, CUtlString(value.c_str()));
}
std::string GSosEditItemInfo_t::GetItemKVString() const {
    return GetSchemaValue<CUtlString>(m_ptr, "SosEditItemInfo_t", "itemKVString").Get();
}
void GSosEditItemInfo_t::SetItemKVString(std::string value) {
    SetSchemaValue(m_ptr, "SosEditItemInfo_t", "itemKVString", true, CUtlString(value.c_str()));
}
Vector2D GSosEditItemInfo_t::GetItemPos() const {
    return GetSchemaValue<Vector2D>(m_ptr, "SosEditItemInfo_t", "itemPos");
}
void GSosEditItemInfo_t::SetItemPos(Vector2D value) {
    SetSchemaValue(m_ptr, "SosEditItemInfo_t", "itemPos", true, value);
}
std::string GSosEditItemInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSosEditItemInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSosEditItemInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSosEditItemInfo_t>("SosEditItemInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ItemType", &GSosEditItemInfo_t::GetItemType, &GSosEditItemInfo_t::SetItemType)
        .addProperty("ItemName", &GSosEditItemInfo_t::GetItemName, &GSosEditItemInfo_t::SetItemName)
        .addProperty("ItemTypeName", &GSosEditItemInfo_t::GetItemTypeName, &GSosEditItemInfo_t::SetItemTypeName)
        .addProperty("ItemKVString", &GSosEditItemInfo_t::GetItemKVString, &GSosEditItemInfo_t::SetItemKVString)
        .addProperty("ItemPos", &GSosEditItemInfo_t::GetItemPos, &GSosEditItemInfo_t::SetItemPos)
        .addFunction("ToPtr", &GSosEditItemInfo_t::ToPtr)
        .addFunction("IsValid", &GSosEditItemInfo_t::IsValid)
        .endClass();
}