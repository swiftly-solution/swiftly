#include "../../../core/scripting/generated/classes/GCSAdditionalPerRoundStats_t.h"
#include "../core.h"

void SetupLuaClassGCSAdditionalPerRoundStats_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSAdditionalPerRoundStats_t>("CSAdditionalPerRoundStats_t")
        .addProperty("NumChickensKilled", &GCSAdditionalPerRoundStats_t::GetNumChickensKilled, &GCSAdditionalPerRoundStats_t::SetNumChickensKilled)
        .addProperty("KillsWhileBlind", &GCSAdditionalPerRoundStats_t::GetKillsWhileBlind, &GCSAdditionalPerRoundStats_t::SetKillsWhileBlind)
        .addProperty("BombCarrierkills", &GCSAdditionalPerRoundStats_t::GetBombCarrierkills, &GCSAdditionalPerRoundStats_t::SetBombCarrierkills)
        .addProperty("BurnDamageInflicted", &GCSAdditionalPerRoundStats_t::GetBurnDamageInflicted, &GCSAdditionalPerRoundStats_t::SetBurnDamageInflicted)
        .addProperty("BlastDamageInflicted", &GCSAdditionalPerRoundStats_t::GetBlastDamageInflicted, &GCSAdditionalPerRoundStats_t::SetBlastDamageInflicted)
        .addProperty("Dinks", &GCSAdditionalPerRoundStats_t::GetDinks, &GCSAdditionalPerRoundStats_t::SetDinks)
        .endClass();
}