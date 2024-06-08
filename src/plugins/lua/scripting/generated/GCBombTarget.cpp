#include "../../../core/scripting/generated/classes/GCBombTarget.h"
#include "../core.h"

void SetupLuaClassGCBombTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBombTarget>("CBombTarget")
        .addProperty("OnBombExplode", &GCBombTarget::GetOnBombExplode, &GCBombTarget::SetOnBombExplode)
        .addProperty("OnBombPlanted", &GCBombTarget::GetOnBombPlanted, &GCBombTarget::SetOnBombPlanted)
        .addProperty("OnBombDefused", &GCBombTarget::GetOnBombDefused, &GCBombTarget::SetOnBombDefused)
        .addProperty("IsBombSiteB", &GCBombTarget::GetIsBombSiteB, &GCBombTarget::SetIsBombSiteB)
        .addProperty("IsHeistBombTarget", &GCBombTarget::GetIsHeistBombTarget, &GCBombTarget::SetIsHeistBombTarget)
        .addProperty("BombPlantedHere", &GCBombTarget::GetBombPlantedHere, &GCBombTarget::SetBombPlantedHere)
        .addProperty("MountTarget", &GCBombTarget::GetMountTarget, &GCBombTarget::SetMountTarget)
        .addProperty("InstructorHint", &GCBombTarget::GetInstructorHint, &GCBombTarget::SetInstructorHint)
        .addProperty("BombSiteDesignation", &GCBombTarget::GetBombSiteDesignation, &GCBombTarget::SetBombSiteDesignation)
        .endClass();
}