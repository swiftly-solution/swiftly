#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRuleEntity::GCRuleEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRuleEntity::GCRuleEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCRuleEntity::GetMaster() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CRuleEntity", "m_iszMaster").String();
}
void GCRuleEntity::SetMaster(std::string value) {
    SetSchemaValue(m_ptr, "CRuleEntity", "m_iszMaster", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCRuleEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRuleEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCRuleEntity::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCRuleEntity::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRuleEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRuleEntity>("CRuleEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Master", &GCRuleEntity::GetMaster, &GCRuleEntity::SetMaster)
        .addProperty("Parent", &GCRuleEntity::GetParent, &GCRuleEntity::SetParent)
        .addFunction("ToPtr", &GCRuleEntity::ToPtr)
        .addFunction("IsValid", &GCRuleEntity::IsValid)
        .endClass();
}