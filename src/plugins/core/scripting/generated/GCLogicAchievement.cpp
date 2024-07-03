#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicAchievement::GCLogicAchievement(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicAchievement::GCLogicAchievement(void *ptr) {
    m_ptr = ptr;
}
bool GCLogicAchievement::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicAchievement", "m_bDisabled");
}
void GCLogicAchievement::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CLogicAchievement", "m_bDisabled", false, value);
}
std::string GCLogicAchievement::GetAchievementEventID() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicAchievement", "m_iszAchievementEventID").String();
}
void GCLogicAchievement::SetAchievementEventID(std::string value) {
    SetSchemaValue(m_ptr, "CLogicAchievement", "m_iszAchievementEventID", false, CUtlSymbolLarge(value.c_str()));
}
GCEntityIOOutput GCLogicAchievement::GetOnFired() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicAchievement", "m_OnFired"));
    return value;
}
void GCLogicAchievement::SetOnFired(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicAchievement", "m_OnFired", false, value);
}
std::string GCLogicAchievement::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicAchievement::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicAchievement::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicAchievement::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicAchievement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicAchievement>("CLogicAchievement")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCLogicAchievement::GetDisabled, &GCLogicAchievement::SetDisabled)
        .addProperty("AchievementEventID", &GCLogicAchievement::GetAchievementEventID, &GCLogicAchievement::SetAchievementEventID)
        .addProperty("OnFired", &GCLogicAchievement::GetOnFired, &GCLogicAchievement::SetOnFired)
        .addProperty("Parent", &GCLogicAchievement::GetParent, &GCLogicAchievement::SetParent)
        .addFunction("ToPtr", &GCLogicAchievement::ToPtr)
        .addFunction("IsValid", &GCLogicAchievement::IsValid)
        .endClass();
}