#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFilterEnemy::GCFilterEnemy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFilterEnemy::GCFilterEnemy(void *ptr) {
    m_ptr = ptr;
}
std::string GCFilterEnemy::GetEnemyName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterEnemy", "m_iszEnemyName").String();
}
void GCFilterEnemy::SetEnemyName(std::string value) {
    SetSchemaValue(m_ptr, "CFilterEnemy", "m_iszEnemyName", false, CUtlSymbolLarge(value.c_str()));
}
float GCFilterEnemy::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CFilterEnemy", "m_flRadius");
}
void GCFilterEnemy::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CFilterEnemy", "m_flRadius", false, value);
}
float GCFilterEnemy::GetOuterRadius() const {
    return GetSchemaValue<float>(m_ptr, "CFilterEnemy", "m_flOuterRadius");
}
void GCFilterEnemy::SetOuterRadius(float value) {
    SetSchemaValue(m_ptr, "CFilterEnemy", "m_flOuterRadius", false, value);
}
int32_t GCFilterEnemy::GetMaxSquadmatesPerEnemy() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFilterEnemy", "m_nMaxSquadmatesPerEnemy");
}
void GCFilterEnemy::SetMaxSquadmatesPerEnemy(int32_t value) {
    SetSchemaValue(m_ptr, "CFilterEnemy", "m_nMaxSquadmatesPerEnemy", false, value);
}
std::string GCFilterEnemy::GetPlayerName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CFilterEnemy", "m_iszPlayerName").String();
}
void GCFilterEnemy::SetPlayerName(std::string value) {
    SetSchemaValue(m_ptr, "CFilterEnemy", "m_iszPlayerName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCFilterEnemy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFilterEnemy::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseFilter GCFilterEnemy::GetParent() const {
    GCBaseFilter value(m_ptr);
    return value;
}
void GCFilterEnemy::SetParent(GCBaseFilter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFilterEnemy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterEnemy>("CFilterEnemy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EnemyName", &GCFilterEnemy::GetEnemyName, &GCFilterEnemy::SetEnemyName)
        .addProperty("Radius", &GCFilterEnemy::GetRadius, &GCFilterEnemy::SetRadius)
        .addProperty("OuterRadius", &GCFilterEnemy::GetOuterRadius, &GCFilterEnemy::SetOuterRadius)
        .addProperty("MaxSquadmatesPerEnemy", &GCFilterEnemy::GetMaxSquadmatesPerEnemy, &GCFilterEnemy::SetMaxSquadmatesPerEnemy)
        .addProperty("PlayerName", &GCFilterEnemy::GetPlayerName, &GCFilterEnemy::SetPlayerName)
        .addProperty("Parent", &GCFilterEnemy::GetParent, &GCFilterEnemy::SetParent)
        .addFunction("ToPtr", &GCFilterEnemy::ToPtr)
        .addFunction("IsValid", &GCFilterEnemy::IsValid)
        .endClass();
}