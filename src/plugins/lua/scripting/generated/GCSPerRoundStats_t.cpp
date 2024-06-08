#include "../../../core/scripting/generated/classes/GCSPerRoundStats_t.h"
#include "../core.h"

void SetupLuaClassGCSPerRoundStats_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSPerRoundStats_t>("CSPerRoundStats_t")
        .addProperty("Kills", &GCSPerRoundStats_t::GetKills, &GCSPerRoundStats_t::SetKills)
        .addProperty("Deaths", &GCSPerRoundStats_t::GetDeaths, &GCSPerRoundStats_t::SetDeaths)
        .addProperty("Assists", &GCSPerRoundStats_t::GetAssists, &GCSPerRoundStats_t::SetAssists)
        .addProperty("Damage", &GCSPerRoundStats_t::GetDamage, &GCSPerRoundStats_t::SetDamage)
        .addProperty("EquipmentValue", &GCSPerRoundStats_t::GetEquipmentValue, &GCSPerRoundStats_t::SetEquipmentValue)
        .addProperty("MoneySaved", &GCSPerRoundStats_t::GetMoneySaved, &GCSPerRoundStats_t::SetMoneySaved)
        .addProperty("KillReward", &GCSPerRoundStats_t::GetKillReward, &GCSPerRoundStats_t::SetKillReward)
        .addProperty("LiveTime", &GCSPerRoundStats_t::GetLiveTime, &GCSPerRoundStats_t::SetLiveTime)
        .addProperty("HeadShotKills", &GCSPerRoundStats_t::GetHeadShotKills, &GCSPerRoundStats_t::SetHeadShotKills)
        .addProperty("Objective", &GCSPerRoundStats_t::GetObjective, &GCSPerRoundStats_t::SetObjective)
        .addProperty("CashEarned", &GCSPerRoundStats_t::GetCashEarned, &GCSPerRoundStats_t::SetCashEarned)
        .addProperty("UtilityDamage", &GCSPerRoundStats_t::GetUtilityDamage, &GCSPerRoundStats_t::SetUtilityDamage)
        .addProperty("EnemiesFlashed", &GCSPerRoundStats_t::GetEnemiesFlashed, &GCSPerRoundStats_t::SetEnemiesFlashed)
        .endClass();
}