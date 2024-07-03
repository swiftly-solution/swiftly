#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRagdollManager::GCRagdollManager(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRagdollManager::GCRagdollManager(void *ptr) {
    m_ptr = ptr;
}
int8_t GCRagdollManager::GetCurrentMaxRagdollCount() const {
    return GetSchemaValue<int8_t>(m_ptr, "CRagdollManager", "m_iCurrentMaxRagdollCount");
}
void GCRagdollManager::SetCurrentMaxRagdollCount(int8_t value) {
    SetSchemaValue(m_ptr, "CRagdollManager", "m_iCurrentMaxRagdollCount", false, value);
}
int32_t GCRagdollManager::GetMaxRagdollCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRagdollManager", "m_iMaxRagdollCount");
}
void GCRagdollManager::SetMaxRagdollCount(int32_t value) {
    SetSchemaValue(m_ptr, "CRagdollManager", "m_iMaxRagdollCount", false, value);
}
bool GCRagdollManager::GetSaveImportant() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollManager", "m_bSaveImportant");
}
void GCRagdollManager::SetSaveImportant(bool value) {
    SetSchemaValue(m_ptr, "CRagdollManager", "m_bSaveImportant", false, value);
}
std::string GCRagdollManager::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRagdollManager::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCRagdollManager::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCRagdollManager::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRagdollManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollManager>("CRagdollManager")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CurrentMaxRagdollCount", &GCRagdollManager::GetCurrentMaxRagdollCount, &GCRagdollManager::SetCurrentMaxRagdollCount)
        .addProperty("MaxRagdollCount", &GCRagdollManager::GetMaxRagdollCount, &GCRagdollManager::SetMaxRagdollCount)
        .addProperty("SaveImportant", &GCRagdollManager::GetSaveImportant, &GCRagdollManager::SetSaveImportant)
        .addProperty("Parent", &GCRagdollManager::GetParent, &GCRagdollManager::SetParent)
        .addFunction("ToPtr", &GCRagdollManager::ToPtr)
        .addFunction("IsValid", &GCRagdollManager::IsValid)
        .endClass();
}