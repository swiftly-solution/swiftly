#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGameModeRules_Deathmatch::GCCSGameModeRules_Deathmatch(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGameModeRules_Deathmatch::GCCSGameModeRules_Deathmatch(void *ptr) {
    m_ptr = ptr;
}
float GCCSGameModeRules_Deathmatch::GetDMBonusStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameModeRules_Deathmatch", "m_flDMBonusStartTime");
}
void GCCSGameModeRules_Deathmatch::SetDMBonusStartTime(float value) {
    SetSchemaValue(m_ptr, "CCSGameModeRules_Deathmatch", "m_flDMBonusStartTime", false, value);
}
float GCCSGameModeRules_Deathmatch::GetDMBonusTimeLength() const {
    return GetSchemaValue<float>(m_ptr, "CCSGameModeRules_Deathmatch", "m_flDMBonusTimeLength");
}
void GCCSGameModeRules_Deathmatch::SetDMBonusTimeLength(float value) {
    SetSchemaValue(m_ptr, "CCSGameModeRules_Deathmatch", "m_flDMBonusTimeLength", false, value);
}
std::string GCCSGameModeRules_Deathmatch::GetDMBonusWeapon() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CCSGameModeRules_Deathmatch", "m_sDMBonusWeapon").Get();
}
void GCCSGameModeRules_Deathmatch::SetDMBonusWeapon(std::string value) {
    SetSchemaValue(m_ptr, "CCSGameModeRules_Deathmatch", "m_sDMBonusWeapon", false, CUtlString(value.c_str()));
}
std::string GCCSGameModeRules_Deathmatch::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGameModeRules_Deathmatch::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGameModeRules GCCSGameModeRules_Deathmatch::GetParent() const {
    GCCSGameModeRules value(m_ptr);
    return value;
}
void GCCSGameModeRules_Deathmatch::SetParent(GCCSGameModeRules value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGameModeRules_Deathmatch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGameModeRules_Deathmatch>("CCSGameModeRules_Deathmatch")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DMBonusStartTime", &GCCSGameModeRules_Deathmatch::GetDMBonusStartTime, &GCCSGameModeRules_Deathmatch::SetDMBonusStartTime)
        .addProperty("DMBonusTimeLength", &GCCSGameModeRules_Deathmatch::GetDMBonusTimeLength, &GCCSGameModeRules_Deathmatch::SetDMBonusTimeLength)
        .addProperty("DMBonusWeapon", &GCCSGameModeRules_Deathmatch::GetDMBonusWeapon, &GCCSGameModeRules_Deathmatch::SetDMBonusWeapon)
        .addProperty("Parent", &GCCSGameModeRules_Deathmatch::GetParent, &GCCSGameModeRules_Deathmatch::SetParent)
        .addFunction("ToPtr", &GCCSGameModeRules_Deathmatch::ToPtr)
        .addFunction("IsValid", &GCCSGameModeRules_Deathmatch::IsValid)
        .endClass();
}