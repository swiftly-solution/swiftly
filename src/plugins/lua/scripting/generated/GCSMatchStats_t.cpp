#include "../../../core/scripting/generated/classes/GCSMatchStats_t.h"
#include "../core.h"

void SetupLuaClassGCSMatchStats_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSMatchStats_t>("CSMatchStats_t")
        .addProperty("Enemy5Ks", &GCSMatchStats_t::GetEnemy5Ks, &GCSMatchStats_t::SetEnemy5Ks)
        .addProperty("Enemy4Ks", &GCSMatchStats_t::GetEnemy4Ks, &GCSMatchStats_t::SetEnemy4Ks)
        .addProperty("Enemy3Ks", &GCSMatchStats_t::GetEnemy3Ks, &GCSMatchStats_t::SetEnemy3Ks)
        .addProperty("EnemyKnifeKills", &GCSMatchStats_t::GetEnemyKnifeKills, &GCSMatchStats_t::SetEnemyKnifeKills)
        .addProperty("EnemyTaserKills", &GCSMatchStats_t::GetEnemyTaserKills, &GCSMatchStats_t::SetEnemyTaserKills)
        .addProperty("Enemy2Ks", &GCSMatchStats_t::GetEnemy2Ks, &GCSMatchStats_t::SetEnemy2Ks)
        .addProperty("Utility_Count", &GCSMatchStats_t::GetUtility_Count, &GCSMatchStats_t::SetUtility_Count)
        .addProperty("Utility_Successes", &GCSMatchStats_t::GetUtility_Successes, &GCSMatchStats_t::SetUtility_Successes)
        .addProperty("Utility_Enemies", &GCSMatchStats_t::GetUtility_Enemies, &GCSMatchStats_t::SetUtility_Enemies)
        .addProperty("Flash_Count", &GCSMatchStats_t::GetFlash_Count, &GCSMatchStats_t::SetFlash_Count)
        .addProperty("Flash_Successes", &GCSMatchStats_t::GetFlash_Successes, &GCSMatchStats_t::SetFlash_Successes)
        .addProperty("HealthPointsRemovedTotal", &GCSMatchStats_t::GetHealthPointsRemovedTotal, &GCSMatchStats_t::SetHealthPointsRemovedTotal)
        .addProperty("HealthPointsDealtTotal", &GCSMatchStats_t::GetHealthPointsDealtTotal, &GCSMatchStats_t::SetHealthPointsDealtTotal)
        .addProperty("ShotsFiredTotal", &GCSMatchStats_t::GetShotsFiredTotal, &GCSMatchStats_t::SetShotsFiredTotal)
        .addProperty("ShotsOnTargetTotal", &GCSMatchStats_t::GetShotsOnTargetTotal, &GCSMatchStats_t::SetShotsOnTargetTotal)
        .addProperty("1v1Count", &GCSMatchStats_t::Get1v1Count, &GCSMatchStats_t::Set1v1Count)
        .addProperty("1v1Wins", &GCSMatchStats_t::Get1v1Wins, &GCSMatchStats_t::Set1v1Wins)
        .addProperty("1v2Count", &GCSMatchStats_t::Get1v2Count, &GCSMatchStats_t::Set1v2Count)
        .addProperty("1v2Wins", &GCSMatchStats_t::Get1v2Wins, &GCSMatchStats_t::Set1v2Wins)
        .addProperty("EntryCount", &GCSMatchStats_t::GetEntryCount, &GCSMatchStats_t::SetEntryCount)
        .addProperty("EntryWins", &GCSMatchStats_t::GetEntryWins, &GCSMatchStats_t::SetEntryWins)
        .endClass();
}