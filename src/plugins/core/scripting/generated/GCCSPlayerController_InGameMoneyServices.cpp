#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayerController_InGameMoneyServices::GCCSPlayerController_InGameMoneyServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayerController_InGameMoneyServices::GCCSPlayerController_InGameMoneyServices(void *ptr) {
    m_ptr = ptr;
}
bool GCCSPlayerController_InGameMoneyServices::GetReceivesMoneyNextRound() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_bReceivesMoneyNextRound");
}
void GCCSPlayerController_InGameMoneyServices::SetReceivesMoneyNextRound(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_bReceivesMoneyNextRound", false, value);
}
int32_t GCCSPlayerController_InGameMoneyServices::GetMoneyEarnedForNextRound() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iMoneyEarnedForNextRound");
}
void GCCSPlayerController_InGameMoneyServices::SetMoneyEarnedForNextRound(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iMoneyEarnedForNextRound", false, value);
}
int32_t GCCSPlayerController_InGameMoneyServices::GetAccount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iAccount");
}
void GCCSPlayerController_InGameMoneyServices::SetAccount(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iAccount", false, value);
}
int32_t GCCSPlayerController_InGameMoneyServices::GetStartAccount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iStartAccount");
}
void GCCSPlayerController_InGameMoneyServices::SetStartAccount(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iStartAccount", false, value);
}
int32_t GCCSPlayerController_InGameMoneyServices::GetTotalCashSpent() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iTotalCashSpent");
}
void GCCSPlayerController_InGameMoneyServices::SetTotalCashSpent(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iTotalCashSpent", false, value);
}
int32_t GCCSPlayerController_InGameMoneyServices::GetCashSpentThisRound() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iCashSpentThisRound");
}
void GCCSPlayerController_InGameMoneyServices::SetCashSpentThisRound(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerController_InGameMoneyServices", "m_iCashSpentThisRound", false, value);
}
std::string GCCSPlayerController_InGameMoneyServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayerController_InGameMoneyServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerControllerComponent GCCSPlayerController_InGameMoneyServices::GetParent() const {
    GCPlayerControllerComponent value(m_ptr);
    return value;
}
void GCCSPlayerController_InGameMoneyServices::SetParent(GCPlayerControllerComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayerController_InGameMoneyServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerController_InGameMoneyServices>("CCSPlayerController_InGameMoneyServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ReceivesMoneyNextRound", &GCCSPlayerController_InGameMoneyServices::GetReceivesMoneyNextRound, &GCCSPlayerController_InGameMoneyServices::SetReceivesMoneyNextRound)
        .addProperty("MoneyEarnedForNextRound", &GCCSPlayerController_InGameMoneyServices::GetMoneyEarnedForNextRound, &GCCSPlayerController_InGameMoneyServices::SetMoneyEarnedForNextRound)
        .addProperty("Account", &GCCSPlayerController_InGameMoneyServices::GetAccount, &GCCSPlayerController_InGameMoneyServices::SetAccount)
        .addProperty("StartAccount", &GCCSPlayerController_InGameMoneyServices::GetStartAccount, &GCCSPlayerController_InGameMoneyServices::SetStartAccount)
        .addProperty("TotalCashSpent", &GCCSPlayerController_InGameMoneyServices::GetTotalCashSpent, &GCCSPlayerController_InGameMoneyServices::SetTotalCashSpent)
        .addProperty("CashSpentThisRound", &GCCSPlayerController_InGameMoneyServices::GetCashSpentThisRound, &GCCSPlayerController_InGameMoneyServices::SetCashSpentThisRound)
        .addProperty("Parent", &GCCSPlayerController_InGameMoneyServices::GetParent, &GCCSPlayerController_InGameMoneyServices::SetParent)
        .addFunction("ToPtr", &GCCSPlayerController_InGameMoneyServices::ToPtr)
        .addFunction("IsValid", &GCCSPlayerController_InGameMoneyServices::IsValid)
        .endClass();
}