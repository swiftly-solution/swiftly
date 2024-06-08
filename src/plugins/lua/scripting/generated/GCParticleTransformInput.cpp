#include "../../../core/scripting/generated/classes/GCParticleTransformInput.h"
#include "../core.h"

void SetupLuaClassGCParticleTransformInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleTransformInput>("CParticleTransformInput")
        .addProperty("Type", &GCParticleTransformInput::GetType, &GCParticleTransformInput::SetType)
        .addProperty("FollowNamedValue", &GCParticleTransformInput::GetFollowNamedValue, &GCParticleTransformInput::SetFollowNamedValue)
        .addProperty("SupportsDisabled", &GCParticleTransformInput::GetSupportsDisabled, &GCParticleTransformInput::SetSupportsDisabled)
        .addProperty("UseOrientation", &GCParticleTransformInput::GetUseOrientation, &GCParticleTransformInput::SetUseOrientation)
        .addProperty("ControlPoint", &GCParticleTransformInput::GetControlPoint, &GCParticleTransformInput::SetControlPoint)
        .addProperty("ControlPointRangeMax", &GCParticleTransformInput::GetControlPointRangeMax, &GCParticleTransformInput::SetControlPointRangeMax)
        .addProperty("EndCPGrowthTime", &GCParticleTransformInput::GetEndCPGrowthTime, &GCParticleTransformInput::SetEndCPGrowthTime)
        .endClass();
}