#include "../../../core/scripting/generated/classes/GCBaseCSGrenade.h"
#include "../core.h"

void SetupLuaClassGCBaseCSGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseCSGrenade>("CBaseCSGrenade")
        .addProperty("Redraw", &GCBaseCSGrenade::GetRedraw, &GCBaseCSGrenade::SetRedraw)
        .addProperty("IsHeldByPlayer", &GCBaseCSGrenade::GetIsHeldByPlayer, &GCBaseCSGrenade::SetIsHeldByPlayer)
        .addProperty("PinPulled", &GCBaseCSGrenade::GetPinPulled, &GCBaseCSGrenade::SetPinPulled)
        .addProperty("JumpThrow", &GCBaseCSGrenade::GetJumpThrow, &GCBaseCSGrenade::SetJumpThrow)
        .addProperty("ThrowAnimating", &GCBaseCSGrenade::GetThrowAnimating, &GCBaseCSGrenade::SetThrowAnimating)
        .addProperty("ThrowStrength", &GCBaseCSGrenade::GetThrowStrength, &GCBaseCSGrenade::SetThrowStrength)
        .addProperty("ThrowStrengthApproach", &GCBaseCSGrenade::GetThrowStrengthApproach, &GCBaseCSGrenade::SetThrowStrengthApproach)
        .addProperty("JustPulledPin", &GCBaseCSGrenade::GetJustPulledPin, &GCBaseCSGrenade::SetJustPulledPin)
        .addProperty("NextHoldFrac", &GCBaseCSGrenade::GetNextHoldFrac, &GCBaseCSGrenade::SetNextHoldFrac)
        .addProperty("SwitchToWeaponAfterThrow", &GCBaseCSGrenade::GetSwitchToWeaponAfterThrow, &GCBaseCSGrenade::SetSwitchToWeaponAfterThrow)
        .endClass();
}