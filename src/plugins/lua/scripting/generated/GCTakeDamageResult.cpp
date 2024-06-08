#include "../../../core/scripting/generated/classes/GCTakeDamageResult.h"
#include "../core.h"

void SetupLuaClassGCTakeDamageResult(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTakeDamageResult>("CTakeDamageResult")
        .addProperty("OriginatingInfo", &GCTakeDamageResult::GetOriginatingInfo, &GCTakeDamageResult::SetOriginatingInfo)
        .addProperty("HealthLost", &GCTakeDamageResult::GetHealthLost, &GCTakeDamageResult::SetHealthLost)
        .addProperty("DamageTaken", &GCTakeDamageResult::GetDamageTaken, &GCTakeDamageResult::SetDamageTaken)
        .addProperty("TotalledHealthLost", &GCTakeDamageResult::GetTotalledHealthLost, &GCTakeDamageResult::SetTotalledHealthLost)
        .addProperty("TotalledDamageTaken", &GCTakeDamageResult::GetTotalledDamageTaken, &GCTakeDamageResult::SetTotalledDamageTaken)
        .endClass();
}