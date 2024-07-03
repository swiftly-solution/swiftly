#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSceneListManager::GCSceneListManager(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSceneListManager::GCSceneListManager(void *ptr) {
    m_ptr = ptr;
}
std::vector<CUtlSymbolLarge> GCSceneListManager::GetScenes() const {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CSceneListManager", "m_iszScenes"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 16; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCSceneListManager::SetScenes(std::vector<CUtlSymbolLarge> value) {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "CSceneListManager", "m_iszScenes"); for(int i = 0; i < 16; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSceneListManager", "m_iszScenes", false, outValue);
}
std::vector<GCBaseEntity*> GCSceneListManager::GetScenes1() const {
    GCBaseEntity** outValue = GetSchemaValue<GCBaseEntity**>(m_ptr, "CSceneListManager", "m_hScenes"); std::vector<GCBaseEntity*> ret; for(int i = 0; i < 16; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCSceneListManager::SetScenes1(std::vector<GCBaseEntity*> value) {
    GCBaseEntity** outValue = GetSchemaValue<GCBaseEntity**>(m_ptr, "CSceneListManager", "m_hScenes"); for(int i = 0; i < 16; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSceneListManager", "m_hScenes", false, outValue);
}
std::string GCSceneListManager::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSceneListManager::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCSceneListManager::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCSceneListManager::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSceneListManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSceneListManager>("CSceneListManager")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Scenes", &GCSceneListManager::GetScenes, &GCSceneListManager::SetScenes)
        .addProperty("Scenes1", &GCSceneListManager::GetScenes1, &GCSceneListManager::SetScenes1)
        .addProperty("Parent", &GCSceneListManager::GetParent, &GCSceneListManager::SetParent)
        .addFunction("ToPtr", &GCSceneListManager::ToPtr)
        .addFunction("IsValid", &GCSceneListManager::IsValid)
        .endClass();
}