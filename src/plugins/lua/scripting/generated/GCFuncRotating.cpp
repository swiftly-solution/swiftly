#include "../../../core/scripting/generated/classes/GCFuncRotating.h"
#include "../core.h"

void SetupLuaClassGCFuncRotating(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncRotating>("CFuncRotating")
        .addProperty("OnStopped", &GCFuncRotating::GetOnStopped, &GCFuncRotating::SetOnStopped)
        .addProperty("OnStarted", &GCFuncRotating::GetOnStarted, &GCFuncRotating::SetOnStarted)
        .addProperty("OnReachedStart", &GCFuncRotating::GetOnReachedStart, &GCFuncRotating::SetOnReachedStart)
        .addProperty("LocalRotationVector", &GCFuncRotating::GetLocalRotationVector, &GCFuncRotating::SetLocalRotationVector)
        .addProperty("FanFriction", &GCFuncRotating::GetFanFriction, &GCFuncRotating::SetFanFriction)
        .addProperty("Attenuation", &GCFuncRotating::GetAttenuation, &GCFuncRotating::SetAttenuation)
        .addProperty("Volume", &GCFuncRotating::GetVolume, &GCFuncRotating::SetVolume)
        .addProperty("TargetSpeed", &GCFuncRotating::GetTargetSpeed, &GCFuncRotating::SetTargetSpeed)
        .addProperty("MaxSpeed", &GCFuncRotating::GetMaxSpeed, &GCFuncRotating::SetMaxSpeed)
        .addProperty("BlockDamage", &GCFuncRotating::GetBlockDamage, &GCFuncRotating::SetBlockDamage)
        .addProperty("NoiseRunning", &GCFuncRotating::GetNoiseRunning, &GCFuncRotating::SetNoiseRunning)
        .addProperty("Reversed", &GCFuncRotating::GetReversed, &GCFuncRotating::SetReversed)
        .addProperty("AccelDecel", &GCFuncRotating::GetAccelDecel, &GCFuncRotating::SetAccelDecel)
        .addProperty("PrevLocalAngles", &GCFuncRotating::GetPrevLocalAngles, &GCFuncRotating::SetPrevLocalAngles)
        .addProperty("Start", &GCFuncRotating::GetStart, &GCFuncRotating::SetStart)
        .addProperty("StopAtStartPos", &GCFuncRotating::GetStopAtStartPos, &GCFuncRotating::SetStopAtStartPos)
        .addProperty("ClientOrigin", &GCFuncRotating::GetClientOrigin, &GCFuncRotating::SetClientOrigin)
        .addProperty("ClientAngles", &GCFuncRotating::GetClientAngles, &GCFuncRotating::SetClientAngles)
        .endClass();
}