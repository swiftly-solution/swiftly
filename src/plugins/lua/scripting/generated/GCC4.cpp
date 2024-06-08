#include "../../../core/scripting/generated/classes/GCC4.h"
#include "../core.h"

void SetupLuaClassGCC4(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCC4>("CC4")
        .addProperty("LastValidPlayerHeldPosition", &GCC4::GetLastValidPlayerHeldPosition, &GCC4::SetLastValidPlayerHeldPosition)
        .addProperty("LastValidDroppedPosition", &GCC4::GetLastValidDroppedPosition, &GCC4::SetLastValidDroppedPosition)
        .addProperty("DoValidDroppedPositionCheck", &GCC4::GetDoValidDroppedPositionCheck, &GCC4::SetDoValidDroppedPositionCheck)
        .addProperty("StartedArming", &GCC4::GetStartedArming, &GCC4::SetStartedArming)
        .addProperty("BombPlacedAnimation", &GCC4::GetBombPlacedAnimation, &GCC4::SetBombPlacedAnimation)
        .addProperty("IsPlantingViaUse", &GCC4::GetIsPlantingViaUse, &GCC4::SetIsPlantingViaUse)
        .addProperty("EntitySpottedState", &GCC4::GetEntitySpottedState, &GCC4::SetEntitySpottedState)
        .addProperty("SpotRules", &GCC4::GetSpotRules, &GCC4::SetSpotRules)
        .addProperty("PlayedArmingBeeps", &GCC4::GetPlayedArmingBeeps, &GCC4::SetPlayedArmingBeeps)
        .addProperty("BombPlanted", &GCC4::GetBombPlanted, &GCC4::SetBombPlanted)
        .endClass();
}