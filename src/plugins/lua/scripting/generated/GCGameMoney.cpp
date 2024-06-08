#include "../../../core/scripting/generated/classes/GCGameMoney.h"
#include "../core.h"

void SetupLuaClassGCGameMoney(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameMoney>("CGameMoney")
        .addProperty("OnMoneySpent", &GCGameMoney::GetOnMoneySpent, &GCGameMoney::SetOnMoneySpent)
        .addProperty("OnMoneySpentFail", &GCGameMoney::GetOnMoneySpentFail, &GCGameMoney::SetOnMoneySpentFail)
        .addProperty("Money", &GCGameMoney::GetMoney, &GCGameMoney::SetMoney)
        .addProperty("StrAwardText", &GCGameMoney::GetStrAwardText, &GCGameMoney::SetStrAwardText)
        .endClass();
}