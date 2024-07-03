#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEconItemView::GCEconItemView(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEconItemView::GCEconItemView(void *ptr) {
    m_ptr = ptr;
}
uint16_t GCEconItemView::GetItemDefinitionIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CEconItemView", "m_iItemDefinitionIndex");
}
void GCEconItemView::SetItemDefinitionIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_iItemDefinitionIndex", false, value);
}
int32_t GCEconItemView::GetEntityQuality() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEconItemView", "m_iEntityQuality");
}
void GCEconItemView::SetEntityQuality(int32_t value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_iEntityQuality", false, value);
}
uint32_t GCEconItemView::GetEntityLevel() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEconItemView", "m_iEntityLevel");
}
void GCEconItemView::SetEntityLevel(uint32_t value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_iEntityLevel", false, value);
}
uint64_t GCEconItemView::GetItemID() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CEconItemView", "m_iItemID");
}
void GCEconItemView::SetItemID(uint64_t value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_iItemID", false, value);
}
uint32_t GCEconItemView::GetItemIDHigh() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEconItemView", "m_iItemIDHigh");
}
void GCEconItemView::SetItemIDHigh(uint32_t value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_iItemIDHigh", false, value);
}
uint32_t GCEconItemView::GetItemIDLow() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEconItemView", "m_iItemIDLow");
}
void GCEconItemView::SetItemIDLow(uint32_t value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_iItemIDLow", false, value);
}
uint32_t GCEconItemView::GetAccountID() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEconItemView", "m_iAccountID");
}
void GCEconItemView::SetAccountID(uint32_t value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_iAccountID", false, value);
}
uint32_t GCEconItemView::GetInventoryPosition() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEconItemView", "m_iInventoryPosition");
}
void GCEconItemView::SetInventoryPosition(uint32_t value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_iInventoryPosition", false, value);
}
bool GCEconItemView::GetInitialized() const {
    return GetSchemaValue<bool>(m_ptr, "CEconItemView", "m_bInitialized");
}
void GCEconItemView::SetInitialized(bool value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_bInitialized", false, value);
}
GCAttributeList GCEconItemView::GetAttributeList() const {
    GCAttributeList value(GetSchemaPtr(m_ptr, "CEconItemView", "m_AttributeList"));
    return value;
}
void GCEconItemView::SetAttributeList(GCAttributeList value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_AttributeList", false, value);
}
GCAttributeList GCEconItemView::GetNetworkedDynamicAttributes() const {
    GCAttributeList value(GetSchemaPtr(m_ptr, "CEconItemView", "m_NetworkedDynamicAttributes"));
    return value;
}
void GCEconItemView::SetNetworkedDynamicAttributes(GCAttributeList value) {
    SetSchemaValue(m_ptr, "CEconItemView", "m_NetworkedDynamicAttributes", false, value);
}
std::string GCEconItemView::GetCustomName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CEconItemView", "m_szCustomName");
}
void GCEconItemView::SetCustomName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CEconItemView", "m_szCustomName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 161);
}
std::string GCEconItemView::GetCustomNameOverride() const {
    return GetSchemaValuePtr<char>(m_ptr, "CEconItemView", "m_szCustomNameOverride");
}
void GCEconItemView::SetCustomNameOverride(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CEconItemView", "m_szCustomNameOverride", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 161);
}
std::string GCEconItemView::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEconItemView::IsValid() {
    return (m_ptr != nullptr);
}
GIEconItemInterface GCEconItemView::GetParent() const {
    GIEconItemInterface value(m_ptr);
    return value;
}
void GCEconItemView::SetParent(GIEconItemInterface value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEconItemView(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEconItemView>("CEconItemView")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ItemDefinitionIndex", &GCEconItemView::GetItemDefinitionIndex, &GCEconItemView::SetItemDefinitionIndex)
        .addProperty("EntityQuality", &GCEconItemView::GetEntityQuality, &GCEconItemView::SetEntityQuality)
        .addProperty("EntityLevel", &GCEconItemView::GetEntityLevel, &GCEconItemView::SetEntityLevel)
        .addProperty("ItemID", &GCEconItemView::GetItemID, &GCEconItemView::SetItemID)
        .addProperty("ItemIDHigh", &GCEconItemView::GetItemIDHigh, &GCEconItemView::SetItemIDHigh)
        .addProperty("ItemIDLow", &GCEconItemView::GetItemIDLow, &GCEconItemView::SetItemIDLow)
        .addProperty("AccountID", &GCEconItemView::GetAccountID, &GCEconItemView::SetAccountID)
        .addProperty("InventoryPosition", &GCEconItemView::GetInventoryPosition, &GCEconItemView::SetInventoryPosition)
        .addProperty("Initialized", &GCEconItemView::GetInitialized, &GCEconItemView::SetInitialized)
        .addProperty("AttributeList", &GCEconItemView::GetAttributeList, &GCEconItemView::SetAttributeList)
        .addProperty("NetworkedDynamicAttributes", &GCEconItemView::GetNetworkedDynamicAttributes, &GCEconItemView::SetNetworkedDynamicAttributes)
        .addProperty("CustomName", &GCEconItemView::GetCustomName, &GCEconItemView::SetCustomName)
        .addProperty("CustomNameOverride", &GCEconItemView::GetCustomNameOverride, &GCEconItemView::SetCustomNameOverride)
        .addProperty("Parent", &GCEconItemView::GetParent, &GCEconItemView::SetParent)
        .addFunction("ToPtr", &GCEconItemView::ToPtr)
        .addFunction("IsValid", &GCEconItemView::IsValid)
        .endClass();
}