#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGameMoney::GCGameMoney(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGameMoney::GCGameMoney(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCGameMoney::GetOnMoneySpent() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CGameMoney", "m_OnMoneySpent"));
    return value;
}
void GCGameMoney::SetOnMoneySpent(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CGameMoney", "m_OnMoneySpent", false, value);
}
GCEntityIOOutput GCGameMoney::GetOnMoneySpentFail() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CGameMoney", "m_OnMoneySpentFail"));
    return value;
}
void GCGameMoney::SetOnMoneySpentFail(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CGameMoney", "m_OnMoneySpentFail", false, value);
}
int32_t GCGameMoney::GetMoney() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGameMoney", "m_nMoney");
}
void GCGameMoney::SetMoney(int32_t value) {
    SetSchemaValue(m_ptr, "CGameMoney", "m_nMoney", false, value);
}
std::string GCGameMoney::GetStrAwardText() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CGameMoney", "m_strAwardText").Get();
}
void GCGameMoney::SetStrAwardText(std::string value) {
    SetSchemaValue(m_ptr, "CGameMoney", "m_strAwardText", false, CUtlString(value.c_str()));
}
std::string GCGameMoney::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGameMoney::IsValid() {
    return (m_ptr != nullptr);
}
GCRulePointEntity GCGameMoney::GetParent() const {
    GCRulePointEntity value(m_ptr);
    return value;
}
void GCGameMoney::SetParent(GCRulePointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGameMoney(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameMoney>("CGameMoney")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnMoneySpent", &GCGameMoney::GetOnMoneySpent, &GCGameMoney::SetOnMoneySpent)
        .addProperty("OnMoneySpentFail", &GCGameMoney::GetOnMoneySpentFail, &GCGameMoney::SetOnMoneySpentFail)
        .addProperty("Money", &GCGameMoney::GetMoney, &GCGameMoney::SetMoney)
        .addProperty("StrAwardText", &GCGameMoney::GetStrAwardText, &GCGameMoney::SetStrAwardText)
        .addProperty("Parent", &GCGameMoney::GetParent, &GCGameMoney::SetParent)
        .addFunction("ToPtr", &GCGameMoney::ToPtr)
        .addFunction("IsValid", &GCGameMoney::IsValid)
        .endClass();
}