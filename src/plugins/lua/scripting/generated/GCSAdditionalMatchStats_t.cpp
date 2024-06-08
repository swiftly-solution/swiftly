#include "../../../core/scripting/generated/classes/GCSAdditionalMatchStats_t.h"
#include "../core.h"

void SetupLuaClassGCSAdditionalMatchStats_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSAdditionalMatchStats_t>("CSAdditionalMatchStats_t")
        .addProperty("NumRoundsSurvived", &GCSAdditionalMatchStats_t::GetNumRoundsSurvived, &GCSAdditionalMatchStats_t::SetNumRoundsSurvived)
        .addProperty("MaxNumRoundsSurvived", &GCSAdditionalMatchStats_t::GetMaxNumRoundsSurvived, &GCSAdditionalMatchStats_t::SetMaxNumRoundsSurvived)
        .addProperty("NumRoundsSurvivedTotal", &GCSAdditionalMatchStats_t::GetNumRoundsSurvivedTotal, &GCSAdditionalMatchStats_t::SetNumRoundsSurvivedTotal)
        .addProperty("RoundsWonWithoutPurchase", &GCSAdditionalMatchStats_t::GetRoundsWonWithoutPurchase, &GCSAdditionalMatchStats_t::SetRoundsWonWithoutPurchase)
        .addProperty("RoundsWonWithoutPurchaseTotal", &GCSAdditionalMatchStats_t::GetRoundsWonWithoutPurchaseTotal, &GCSAdditionalMatchStats_t::SetRoundsWonWithoutPurchaseTotal)
        .addProperty("NumFirstKills", &GCSAdditionalMatchStats_t::GetNumFirstKills, &GCSAdditionalMatchStats_t::SetNumFirstKills)
        .addProperty("NumClutchKills", &GCSAdditionalMatchStats_t::GetNumClutchKills, &GCSAdditionalMatchStats_t::SetNumClutchKills)
        .addProperty("NumPistolKills", &GCSAdditionalMatchStats_t::GetNumPistolKills, &GCSAdditionalMatchStats_t::SetNumPistolKills)
        .addProperty("NumSniperKills", &GCSAdditionalMatchStats_t::GetNumSniperKills, &GCSAdditionalMatchStats_t::SetNumSniperKills)
        .addProperty("NumSuicides", &GCSAdditionalMatchStats_t::GetNumSuicides, &GCSAdditionalMatchStats_t::SetNumSuicides)
        .addProperty("NumTeamKills", &GCSAdditionalMatchStats_t::GetNumTeamKills, &GCSAdditionalMatchStats_t::SetNumTeamKills)
        .addProperty("TeamDamage", &GCSAdditionalMatchStats_t::GetTeamDamage, &GCSAdditionalMatchStats_t::SetTeamDamage)
        .endClass();
}