#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGameGibManager::GCGameGibManager(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGameGibManager::GCGameGibManager(void *ptr) {
    m_ptr = ptr;
}
bool GCGameGibManager::GetAllowNewGibs() const {
    return GetSchemaValue<bool>(m_ptr, "CGameGibManager", "m_bAllowNewGibs");
}
void GCGameGibManager::SetAllowNewGibs(bool value) {
    SetSchemaValue(m_ptr, "CGameGibManager", "m_bAllowNewGibs", false, value);
}
int32_t GCGameGibManager::GetCurrentMaxPieces() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGameGibManager", "m_iCurrentMaxPieces");
}
void GCGameGibManager::SetCurrentMaxPieces(int32_t value) {
    SetSchemaValue(m_ptr, "CGameGibManager", "m_iCurrentMaxPieces", false, value);
}
int32_t GCGameGibManager::GetMaxPieces() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGameGibManager", "m_iMaxPieces");
}
void GCGameGibManager::SetMaxPieces(int32_t value) {
    SetSchemaValue(m_ptr, "CGameGibManager", "m_iMaxPieces", false, value);
}
int32_t GCGameGibManager::GetLastFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGameGibManager", "m_iLastFrame");
}
void GCGameGibManager::SetLastFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CGameGibManager", "m_iLastFrame", false, value);
}
std::string GCGameGibManager::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGameGibManager::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCGameGibManager::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCGameGibManager::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGameGibManager(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameGibManager>("CGameGibManager")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AllowNewGibs", &GCGameGibManager::GetAllowNewGibs, &GCGameGibManager::SetAllowNewGibs)
        .addProperty("CurrentMaxPieces", &GCGameGibManager::GetCurrentMaxPieces, &GCGameGibManager::SetCurrentMaxPieces)
        .addProperty("MaxPieces", &GCGameGibManager::GetMaxPieces, &GCGameGibManager::SetMaxPieces)
        .addProperty("LastFrame", &GCGameGibManager::GetLastFrame, &GCGameGibManager::SetLastFrame)
        .addProperty("Parent", &GCGameGibManager::GetParent, &GCGameGibManager::SetParent)
        .addFunction("ToPtr", &GCGameGibManager::ToPtr)
        .addFunction("IsValid", &GCGameGibManager::IsValid)
        .endClass();
}