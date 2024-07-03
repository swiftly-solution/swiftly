#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEconEntity::GCEconEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEconEntity::GCEconEntity(void *ptr) {
    m_ptr = ptr;
}
GCAttributeContainer GCEconEntity::GetAttributeManager() const {
    GCAttributeContainer value(GetSchemaPtr(m_ptr, "CEconEntity", "m_AttributeManager"));
    return value;
}
void GCEconEntity::SetAttributeManager(GCAttributeContainer value) {
    SetSchemaValue(m_ptr, "CEconEntity", "m_AttributeManager", false, value);
}
uint32_t GCEconEntity::GetOriginalOwnerXuidLow() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEconEntity", "m_OriginalOwnerXuidLow");
}
void GCEconEntity::SetOriginalOwnerXuidLow(uint32_t value) {
    SetSchemaValue(m_ptr, "CEconEntity", "m_OriginalOwnerXuidLow", false, value);
}
uint32_t GCEconEntity::GetOriginalOwnerXuidHigh() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEconEntity", "m_OriginalOwnerXuidHigh");
}
void GCEconEntity::SetOriginalOwnerXuidHigh(uint32_t value) {
    SetSchemaValue(m_ptr, "CEconEntity", "m_OriginalOwnerXuidHigh", false, value);
}
int32_t GCEconEntity::GetFallbackPaintKit() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEconEntity", "m_nFallbackPaintKit");
}
void GCEconEntity::SetFallbackPaintKit(int32_t value) {
    SetSchemaValue(m_ptr, "CEconEntity", "m_nFallbackPaintKit", false, value);
}
int32_t GCEconEntity::GetFallbackSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEconEntity", "m_nFallbackSeed");
}
void GCEconEntity::SetFallbackSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CEconEntity", "m_nFallbackSeed", false, value);
}
float GCEconEntity::GetFallbackWear() const {
    return GetSchemaValue<float>(m_ptr, "CEconEntity", "m_flFallbackWear");
}
void GCEconEntity::SetFallbackWear(float value) {
    SetSchemaValue(m_ptr, "CEconEntity", "m_flFallbackWear", false, value);
}
int32_t GCEconEntity::GetFallbackStatTrak() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEconEntity", "m_nFallbackStatTrak");
}
void GCEconEntity::SetFallbackStatTrak(int32_t value) {
    SetSchemaValue(m_ptr, "CEconEntity", "m_nFallbackStatTrak", false, value);
}
GCBaseEntity GCEconEntity::GetOldProvidee() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEconEntity", "m_hOldProvidee"));
    return value;
}
void GCEconEntity::SetOldProvidee(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'OldProvidee' is not possible.\n");
}
int32_t GCEconEntity::GetOldOwnerClass() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEconEntity", "m_iOldOwnerClass");
}
void GCEconEntity::SetOldOwnerClass(int32_t value) {
    SetSchemaValue(m_ptr, "CEconEntity", "m_iOldOwnerClass", false, value);
}
std::string GCEconEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEconEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFlex GCEconEntity::GetParent() const {
    GCBaseFlex value(m_ptr);
    return value;
}
void GCEconEntity::SetParent(GCBaseFlex value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEconEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEconEntity>("CEconEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AttributeManager", &GCEconEntity::GetAttributeManager, &GCEconEntity::SetAttributeManager)
        .addProperty("OriginalOwnerXuidLow", &GCEconEntity::GetOriginalOwnerXuidLow, &GCEconEntity::SetOriginalOwnerXuidLow)
        .addProperty("OriginalOwnerXuidHigh", &GCEconEntity::GetOriginalOwnerXuidHigh, &GCEconEntity::SetOriginalOwnerXuidHigh)
        .addProperty("FallbackPaintKit", &GCEconEntity::GetFallbackPaintKit, &GCEconEntity::SetFallbackPaintKit)
        .addProperty("FallbackSeed", &GCEconEntity::GetFallbackSeed, &GCEconEntity::SetFallbackSeed)
        .addProperty("FallbackWear", &GCEconEntity::GetFallbackWear, &GCEconEntity::SetFallbackWear)
        .addProperty("FallbackStatTrak", &GCEconEntity::GetFallbackStatTrak, &GCEconEntity::SetFallbackStatTrak)
        .addProperty("OldProvidee", &GCEconEntity::GetOldProvidee, &GCEconEntity::SetOldProvidee)
        .addProperty("OldOwnerClass", &GCEconEntity::GetOldOwnerClass, &GCEconEntity::SetOldOwnerClass)
        .addProperty("Parent", &GCEconEntity::GetParent, &GCEconEntity::SetParent)
        .addFunction("ToPtr", &GCEconEntity::ToPtr)
        .addFunction("IsValid", &GCEconEntity::IsValid)
        .endClass();
}