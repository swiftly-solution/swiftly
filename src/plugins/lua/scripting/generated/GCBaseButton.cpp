#include "../../../core/scripting/generated/classes/GCBaseButton.h"
#include "../core.h"

void SetupLuaClassGCBaseButton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseButton>("CBaseButton")
        .addProperty("MoveEntitySpace", &GCBaseButton::GetMoveEntitySpace, &GCBaseButton::SetMoveEntitySpace)
        .addProperty("StayPushed", &GCBaseButton::GetStayPushed, &GCBaseButton::SetStayPushed)
        .addProperty("Rotating", &GCBaseButton::GetRotating, &GCBaseButton::SetRotating)
        .addProperty("Ls", &GCBaseButton::GetLs, &GCBaseButton::SetLs)
        .addProperty("UseSound", &GCBaseButton::GetUseSound, &GCBaseButton::SetUseSound)
        .addProperty("LockedSound", &GCBaseButton::GetLockedSound, &GCBaseButton::SetLockedSound)
        .addProperty("UnlockedSound", &GCBaseButton::GetUnlockedSound, &GCBaseButton::SetUnlockedSound)
        .addProperty("OverrideAnticipationName", &GCBaseButton::GetOverrideAnticipationName, &GCBaseButton::SetOverrideAnticipationName)
        .addProperty("Locked", &GCBaseButton::GetLocked, &GCBaseButton::SetLocked)
        .addProperty("Disabled", &GCBaseButton::GetDisabled, &GCBaseButton::SetDisabled)
        .addProperty("SolidBsp", &GCBaseButton::GetSolidBsp, &GCBaseButton::SetSolidBsp)
        .addProperty("OnDamaged", &GCBaseButton::GetOnDamaged, &GCBaseButton::SetOnDamaged)
        .addProperty("OnPressed", &GCBaseButton::GetOnPressed, &GCBaseButton::SetOnPressed)
        .addProperty("OnUseLocked", &GCBaseButton::GetOnUseLocked, &GCBaseButton::SetOnUseLocked)
        .addProperty("OnIn", &GCBaseButton::GetOnIn, &GCBaseButton::SetOnIn)
        .addProperty("OnOut", &GCBaseButton::GetOnOut, &GCBaseButton::SetOnOut)
        .addProperty("State", &GCBaseButton::GetState, &GCBaseButton::SetState)
        .addProperty("Constraint", &GCBaseButton::GetConstraint, &GCBaseButton::SetConstraint)
        .addProperty("ConstraintParent", &GCBaseButton::GetConstraintParent, &GCBaseButton::SetConstraintParent)
        .addProperty("ForceNpcExclude", &GCBaseButton::GetForceNpcExclude, &GCBaseButton::SetForceNpcExclude)
        .addProperty("GlowEntity", &GCBaseButton::GetGlowEntity, &GCBaseButton::SetGlowEntity)
        .addProperty("GlowEntity1", &GCBaseButton::GetGlowEntity1, &GCBaseButton::SetGlowEntity1)
        .addProperty("Usable", &GCBaseButton::GetUsable, &GCBaseButton::SetUsable)
        .addProperty("DisplayText", &GCBaseButton::GetDisplayText, &GCBaseButton::SetDisplayText)
        .endClass();
}