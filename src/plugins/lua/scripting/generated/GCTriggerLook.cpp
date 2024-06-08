#include "../../../core/scripting/generated/classes/GCTriggerLook.h"
#include "../core.h"

void SetupLuaClassGCTriggerLook(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerLook>("CTriggerLook")
        .addProperty("LookTarget", &GCTriggerLook::GetLookTarget, &GCTriggerLook::SetLookTarget)
        .addProperty("FieldOfView", &GCTriggerLook::GetFieldOfView, &GCTriggerLook::SetFieldOfView)
        .addProperty("LookTime", &GCTriggerLook::GetLookTime, &GCTriggerLook::SetLookTime)
        .addProperty("LookTimeTotal", &GCTriggerLook::GetLookTimeTotal, &GCTriggerLook::SetLookTimeTotal)
        .addProperty("TimeoutDuration", &GCTriggerLook::GetTimeoutDuration, &GCTriggerLook::SetTimeoutDuration)
        .addProperty("TimeoutFired", &GCTriggerLook::GetTimeoutFired, &GCTriggerLook::SetTimeoutFired)
        .addProperty("IsLooking", &GCTriggerLook::GetIsLooking, &GCTriggerLook::SetIsLooking)
        .addProperty("2DFOV", &GCTriggerLook::Get2DFOV, &GCTriggerLook::Set2DFOV)
        .addProperty("UseVelocity", &GCTriggerLook::GetUseVelocity, &GCTriggerLook::SetUseVelocity)
        .addProperty("TestOcclusion", &GCTriggerLook::GetTestOcclusion, &GCTriggerLook::SetTestOcclusion)
        .addProperty("OnTimeout", &GCTriggerLook::GetOnTimeout, &GCTriggerLook::SetOnTimeout)
        .addProperty("OnStartLook", &GCTriggerLook::GetOnStartLook, &GCTriggerLook::SetOnStartLook)
        .addProperty("OnEndLook", &GCTriggerLook::GetOnEndLook, &GCTriggerLook::SetOnEndLook)
        .endClass();
}