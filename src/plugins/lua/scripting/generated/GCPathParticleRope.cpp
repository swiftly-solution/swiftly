#include "../../../core/scripting/generated/classes/GCPathParticleRope.h"
#include "../core.h"

void SetupLuaClassGCPathParticleRope(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathParticleRope>("CPathParticleRope")
        .addProperty("StartActive", &GCPathParticleRope::GetStartActive, &GCPathParticleRope::SetStartActive)
        .addProperty("MaxSimulationTime", &GCPathParticleRope::GetMaxSimulationTime, &GCPathParticleRope::SetMaxSimulationTime)
        .addProperty("EffectName", &GCPathParticleRope::GetEffectName, &GCPathParticleRope::SetEffectName)
        .addProperty("PathNodes_Name", &GCPathParticleRope::GetPathNodes_Name, &GCPathParticleRope::SetPathNodes_Name)
        .addProperty("ParticleSpacing", &GCPathParticleRope::GetParticleSpacing, &GCPathParticleRope::SetParticleSpacing)
        .addProperty("Slack", &GCPathParticleRope::GetSlack, &GCPathParticleRope::SetSlack)
        .addProperty("Radius", &GCPathParticleRope::GetRadius, &GCPathParticleRope::SetRadius)
        .addProperty("ColorTint", &GCPathParticleRope::GetColorTint, &GCPathParticleRope::SetColorTint)
        .addProperty("EffectState", &GCPathParticleRope::GetEffectState, &GCPathParticleRope::SetEffectState)
        .addProperty("PathNodes_Position", &GCPathParticleRope::GetPathNodes_Position, &GCPathParticleRope::SetPathNodes_Position)
        .addProperty("PathNodes_TangentIn", &GCPathParticleRope::GetPathNodes_TangentIn, &GCPathParticleRope::SetPathNodes_TangentIn)
        .addProperty("PathNodes_TangentOut", &GCPathParticleRope::GetPathNodes_TangentOut, &GCPathParticleRope::SetPathNodes_TangentOut)
        .addProperty("PathNodes_Color", &GCPathParticleRope::GetPathNodes_Color, &GCPathParticleRope::SetPathNodes_Color)
        .addProperty("PathNodes_PinEnabled", &GCPathParticleRope::GetPathNodes_PinEnabled, &GCPathParticleRope::SetPathNodes_PinEnabled)
        .addProperty("PathNodes_RadiusScale", &GCPathParticleRope::GetPathNodes_RadiusScale, &GCPathParticleRope::SetPathNodes_RadiusScale)
        .endClass();
}