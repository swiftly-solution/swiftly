#include "../../../core/scripting/generated/classes/GCDamageRecord.h"
#include "../core.h"

void SetupLuaClassGCDamageRecord(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDamageRecord>("CDamageRecord")
        .addProperty("PlayerDamager", &GCDamageRecord::GetPlayerDamager, &GCDamageRecord::SetPlayerDamager)
        .addProperty("PlayerRecipient", &GCDamageRecord::GetPlayerRecipient, &GCDamageRecord::SetPlayerRecipient)
        .addProperty("PlayerControllerDamager", &GCDamageRecord::GetPlayerControllerDamager, &GCDamageRecord::SetPlayerControllerDamager)
        .addProperty("PlayerControllerRecipient", &GCDamageRecord::GetPlayerControllerRecipient, &GCDamageRecord::SetPlayerControllerRecipient)
        .addProperty("PlayerDamagerName", &GCDamageRecord::GetPlayerDamagerName, &GCDamageRecord::SetPlayerDamagerName)
        .addProperty("PlayerRecipientName", &GCDamageRecord::GetPlayerRecipientName, &GCDamageRecord::SetPlayerRecipientName)
        .addProperty("DamagerXuid", &GCDamageRecord::GetDamagerXuid, &GCDamageRecord::SetDamagerXuid)
        .addProperty("RecipientXuid", &GCDamageRecord::GetRecipientXuid, &GCDamageRecord::SetRecipientXuid)
        .addProperty("Damage", &GCDamageRecord::GetDamage, &GCDamageRecord::SetDamage)
        .addProperty("ActualHealthRemoved", &GCDamageRecord::GetActualHealthRemoved, &GCDamageRecord::SetActualHealthRemoved)
        .addProperty("NumHits", &GCDamageRecord::GetNumHits, &GCDamageRecord::SetNumHits)
        .addProperty("LastBulletUpdate", &GCDamageRecord::GetLastBulletUpdate, &GCDamageRecord::SetLastBulletUpdate)
        .addProperty("IsOtherEnemy", &GCDamageRecord::GetIsOtherEnemy, &GCDamageRecord::SetIsOtherEnemy)
        .addProperty("KillType", &GCDamageRecord::GetKillType, &GCDamageRecord::SetKillType)
        .endClass();
}