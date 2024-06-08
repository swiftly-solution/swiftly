#include "../../../core/scripting/generated/classes/GCTriggerFan.h"
#include "../core.h"

void SetupLuaClassGCTriggerFan(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerFan>("CTriggerFan")
        .addProperty("FanOrigin", &GCTriggerFan::GetFanOrigin, &GCTriggerFan::SetFanOrigin)
        .addProperty("FanEnd", &GCTriggerFan::GetFanEnd, &GCTriggerFan::SetFanEnd)
        .addProperty("Noise", &GCTriggerFan::GetNoise, &GCTriggerFan::SetNoise)
        .addProperty("Force", &GCTriggerFan::GetForce, &GCTriggerFan::SetForce)
        .addProperty("RopeForceScale", &GCTriggerFan::GetRopeForceScale, &GCTriggerFan::SetRopeForceScale)
        .addProperty("PlayerForce", &GCTriggerFan::GetPlayerForce, &GCTriggerFan::SetPlayerForce)
        .addProperty("RampTime", &GCTriggerFan::GetRampTime, &GCTriggerFan::SetRampTime)
        .addProperty("Falloff", &GCTriggerFan::GetFalloff, &GCTriggerFan::SetFalloff)
        .addProperty("PushPlayer", &GCTriggerFan::GetPushPlayer, &GCTriggerFan::SetPushPlayer)
        .addProperty("RampDown", &GCTriggerFan::GetRampDown, &GCTriggerFan::SetRampDown)
        .addProperty("AddNoise", &GCTriggerFan::GetAddNoise, &GCTriggerFan::SetAddNoise)
        .addProperty("RampTimer", &GCTriggerFan::GetRampTimer, &GCTriggerFan::SetRampTimer)
        .endClass();
}