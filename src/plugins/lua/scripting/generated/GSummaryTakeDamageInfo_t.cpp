#include "../../../core/scripting/generated/classes/GSummaryTakeDamageInfo_t.h"
#include "../core.h"

void SetupLuaClassGSummaryTakeDamageInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSummaryTakeDamageInfo_t>("SummaryTakeDamageInfo_t")
        .addProperty("SummarisedCount", &GSummaryTakeDamageInfo_t::GetSummarisedCount, &GSummaryTakeDamageInfo_t::SetSummarisedCount)
        .addProperty("Info", &GSummaryTakeDamageInfo_t::GetInfo, &GSummaryTakeDamageInfo_t::SetInfo)
        .addProperty("Result", &GSummaryTakeDamageInfo_t::GetResult, &GSummaryTakeDamageInfo_t::SetResult)
        .addProperty("Target", &GSummaryTakeDamageInfo_t::GetTarget, &GSummaryTakeDamageInfo_t::SetTarget)
        .endClass();
}