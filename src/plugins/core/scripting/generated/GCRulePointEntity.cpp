#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRulePointEntity::GCRulePointEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRulePointEntity::GCRulePointEntity(void *ptr) {
    m_ptr = ptr;
}
int32_t GCRulePointEntity::GetScore() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRulePointEntity", "m_Score");
}
void GCRulePointEntity::SetScore(int32_t value) {
    SetSchemaValue(m_ptr, "CRulePointEntity", "m_Score", false, value);
}
std::string GCRulePointEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRulePointEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCRuleEntity GCRulePointEntity::GetParent() const {
    GCRuleEntity value(m_ptr);
    return value;
}
void GCRulePointEntity::SetParent(GCRuleEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRulePointEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRulePointEntity>("CRulePointEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Score", &GCRulePointEntity::GetScore, &GCRulePointEntity::SetScore)
        .addProperty("Parent", &GCRulePointEntity::GetParent, &GCRulePointEntity::SetParent)
        .addFunction("ToPtr", &GCRulePointEntity::ToPtr)
        .addFunction("IsValid", &GCRulePointEntity::IsValid)
        .endClass();
}