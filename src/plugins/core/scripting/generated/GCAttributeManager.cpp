#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAttributeManager::GCAttributeManager(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAttributeManager::GCAttributeManager(void *ptr) {
    m_ptr = ptr;
}
int32_t GCAttributeManager::GetReapplyProvisionParity() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAttributeManager", "m_iReapplyProvisionParity");
}
void GCAttributeManager::SetReapplyProvisionParity(int32_t value) {
    SetSchemaValue(m_ptr, "CAttributeManager", "m_iReapplyProvisionParity", false, value);
}
GCBaseEntity GCAttributeManager::GetOuter() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CAttributeManager", "m_hOuter"));
    return value;
}
void GCAttributeManager::SetOuter(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Outer' is not possible.\n");
}
bool GCAttributeManager::GetPreventLoopback() const {
    return GetSchemaValue<bool>(m_ptr, "CAttributeManager", "m_bPreventLoopback");
}
void GCAttributeManager::SetPreventLoopback(bool value) {
    SetSchemaValue(m_ptr, "CAttributeManager", "m_bPreventLoopback", false, value);
}
uint64_t GCAttributeManager::GetProviderType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CAttributeManager", "m_ProviderType");
}
void GCAttributeManager::SetProviderType(uint64_t value) {
    SetSchemaValue(m_ptr, "CAttributeManager", "m_ProviderType", false, value);
}
std::vector<GCAttributeManager> GCAttributeManager::GetCachedResults() const {
    CUtlVector<GCAttributeManager>* vec = GetSchemaValue<CUtlVector<GCAttributeManager>*>(m_ptr, "CAttributeManager", "m_CachedResults"); std::vector<GCAttributeManager> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAttributeManager::SetCachedResults(std::vector<GCAttributeManager> value) {
    SetSchemaValueCUtlVector<GCAttributeManager>(m_ptr, "CAttributeManager", "m_CachedResults", false, value);
}
std::string GCAttributeManager::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAttributeManager::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAttributeManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAttributeManager>("CAttributeManager")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ReapplyProvisionParity", &GCAttributeManager::GetReapplyProvisionParity, &GCAttributeManager::SetReapplyProvisionParity)
        .addProperty("Outer", &GCAttributeManager::GetOuter, &GCAttributeManager::SetOuter)
        .addProperty("PreventLoopback", &GCAttributeManager::GetPreventLoopback, &GCAttributeManager::SetPreventLoopback)
        .addProperty("ProviderType", &GCAttributeManager::GetProviderType, &GCAttributeManager::SetProviderType)
        .addProperty("CachedResults", &GCAttributeManager::GetCachedResults, &GCAttributeManager::SetCachedResults)
        .addFunction("ToPtr", &GCAttributeManager::ToPtr)
        .addFunction("IsValid", &GCAttributeManager::IsValid)
        .endClass();
}