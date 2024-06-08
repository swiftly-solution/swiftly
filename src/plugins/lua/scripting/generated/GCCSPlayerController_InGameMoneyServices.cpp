#include "../../../core/scripting/generated/classes/GCCSPlayerController_InGameMoneyServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayerController_InGameMoneyServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerController_InGameMoneyServices>("CCSPlayerController_InGameMoneyServices")
        .addProperty("ReceivesMoneyNextRound", &GCCSPlayerController_InGameMoneyServices::GetReceivesMoneyNextRound, &GCCSPlayerController_InGameMoneyServices::SetReceivesMoneyNextRound)
        .addProperty("MoneyEarnedForNextRound", &GCCSPlayerController_InGameMoneyServices::GetMoneyEarnedForNextRound, &GCCSPlayerController_InGameMoneyServices::SetMoneyEarnedForNextRound)
        .addProperty("Account", &GCCSPlayerController_InGameMoneyServices::GetAccount, &GCCSPlayerController_InGameMoneyServices::SetAccount)
        .addProperty("StartAccount", &GCCSPlayerController_InGameMoneyServices::GetStartAccount, &GCCSPlayerController_InGameMoneyServices::SetStartAccount)
        .addProperty("TotalCashSpent", &GCCSPlayerController_InGameMoneyServices::GetTotalCashSpent, &GCCSPlayerController_InGameMoneyServices::SetTotalCashSpent)
        .addProperty("CashSpentThisRound", &GCCSPlayerController_InGameMoneyServices::GetCashSpentThisRound, &GCCSPlayerController_InGameMoneyServices::SetCashSpentThisRound)
        .endClass();
}