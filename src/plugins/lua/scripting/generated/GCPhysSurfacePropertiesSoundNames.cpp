#include "../../../core/scripting/generated/classes/GCPhysSurfacePropertiesSoundNames.h"
#include "../core.h"

void SetupLuaClassGCPhysSurfacePropertiesSoundNames(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysSurfacePropertiesSoundNames>("CPhysSurfacePropertiesSoundNames")
        .addProperty("ImpactSoft", &GCPhysSurfacePropertiesSoundNames::GetImpactSoft, &GCPhysSurfacePropertiesSoundNames::SetImpactSoft)
        .addProperty("ImpactHard", &GCPhysSurfacePropertiesSoundNames::GetImpactHard, &GCPhysSurfacePropertiesSoundNames::SetImpactHard)
        .addProperty("ScrapeSmooth", &GCPhysSurfacePropertiesSoundNames::GetScrapeSmooth, &GCPhysSurfacePropertiesSoundNames::SetScrapeSmooth)
        .addProperty("ScrapeRough", &GCPhysSurfacePropertiesSoundNames::GetScrapeRough, &GCPhysSurfacePropertiesSoundNames::SetScrapeRough)
        .addProperty("BulletImpact", &GCPhysSurfacePropertiesSoundNames::GetBulletImpact, &GCPhysSurfacePropertiesSoundNames::SetBulletImpact)
        .addProperty("Rolling", &GCPhysSurfacePropertiesSoundNames::GetRolling, &GCPhysSurfacePropertiesSoundNames::SetRolling)
        .addProperty("Break", &GCPhysSurfacePropertiesSoundNames::GetBreak, &GCPhysSurfacePropertiesSoundNames::SetBreak)
        .addProperty("Strain", &GCPhysSurfacePropertiesSoundNames::GetStrain, &GCPhysSurfacePropertiesSoundNames::SetStrain)
        .addProperty("MeleeImpact", &GCPhysSurfacePropertiesSoundNames::GetMeleeImpact, &GCPhysSurfacePropertiesSoundNames::SetMeleeImpact)
        .addProperty("PushOff", &GCPhysSurfacePropertiesSoundNames::GetPushOff, &GCPhysSurfacePropertiesSoundNames::SetPushOff)
        .addProperty("SkidStop", &GCPhysSurfacePropertiesSoundNames::GetSkidStop, &GCPhysSurfacePropertiesSoundNames::SetSkidStop)
        .endClass();
}