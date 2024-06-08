#include "../../../core/scripting/generated/classes/GCPlayer_MovementServices_Humanoid.h"
#include "../core.h"

void SetupLuaClassGCPlayer_MovementServices_Humanoid(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_MovementServices_Humanoid>("CPlayer_MovementServices_Humanoid")
        .addProperty("StepSoundTime", &GCPlayer_MovementServices_Humanoid::GetStepSoundTime, &GCPlayer_MovementServices_Humanoid::SetStepSoundTime)
        .addProperty("FallVelocity", &GCPlayer_MovementServices_Humanoid::GetFallVelocity, &GCPlayer_MovementServices_Humanoid::SetFallVelocity)
        .addProperty("InCrouch", &GCPlayer_MovementServices_Humanoid::GetInCrouch, &GCPlayer_MovementServices_Humanoid::SetInCrouch)
        .addProperty("CrouchState", &GCPlayer_MovementServices_Humanoid::GetCrouchState, &GCPlayer_MovementServices_Humanoid::SetCrouchState)
        .addProperty("Ducked", &GCPlayer_MovementServices_Humanoid::GetDucked, &GCPlayer_MovementServices_Humanoid::SetDucked)
        .addProperty("Ducking", &GCPlayer_MovementServices_Humanoid::GetDucking, &GCPlayer_MovementServices_Humanoid::SetDucking)
        .addProperty("InDuckJump", &GCPlayer_MovementServices_Humanoid::GetInDuckJump, &GCPlayer_MovementServices_Humanoid::SetInDuckJump)
        .addProperty("GroundNormal", &GCPlayer_MovementServices_Humanoid::GetGroundNormal, &GCPlayer_MovementServices_Humanoid::SetGroundNormal)
        .addProperty("SurfaceFriction", &GCPlayer_MovementServices_Humanoid::GetSurfaceFriction, &GCPlayer_MovementServices_Humanoid::SetSurfaceFriction)
        .addProperty("SurfaceProps", &GCPlayer_MovementServices_Humanoid::GetSurfaceProps, &GCPlayer_MovementServices_Humanoid::SetSurfaceProps)
        .addProperty("Stepside", &GCPlayer_MovementServices_Humanoid::GetStepside, &GCPlayer_MovementServices_Humanoid::SetStepside)
        .addProperty("TargetVolume", &GCPlayer_MovementServices_Humanoid::GetTargetVolume, &GCPlayer_MovementServices_Humanoid::SetTargetVolume)
        .addProperty("SmoothedVelocity", &GCPlayer_MovementServices_Humanoid::GetSmoothedVelocity, &GCPlayer_MovementServices_Humanoid::SetSmoothedVelocity)
        .endClass();
}