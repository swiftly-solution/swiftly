#include "../../../core/scripting/generated/classes/GCParticleVecInput.h"
#include "../core.h"

void SetupLuaClassGCParticleVecInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleVecInput>("CParticleVecInput")
        .addProperty("Type", &GCParticleVecInput::GetType, &GCParticleVecInput::SetType)
        .addProperty("LiteralValue", &GCParticleVecInput::GetLiteralValue, &GCParticleVecInput::SetLiteralValue)
        .addProperty("LiteralColor", &GCParticleVecInput::GetLiteralColor, &GCParticleVecInput::SetLiteralColor)
        .addProperty("FollowNamedValue", &GCParticleVecInput::GetFollowNamedValue, &GCParticleVecInput::SetFollowNamedValue)
        .addProperty("VectorAttribute", &GCParticleVecInput::GetVectorAttribute, &GCParticleVecInput::SetVectorAttribute)
        .addProperty("VectorAttributeScale", &GCParticleVecInput::GetVectorAttributeScale, &GCParticleVecInput::SetVectorAttributeScale)
        .addProperty("ControlPoint", &GCParticleVecInput::GetControlPoint, &GCParticleVecInput::SetControlPoint)
        .addProperty("DeltaControlPoint", &GCParticleVecInput::GetDeltaControlPoint, &GCParticleVecInput::SetDeltaControlPoint)
        .addProperty("CPValueScale", &GCParticleVecInput::GetCPValueScale, &GCParticleVecInput::SetCPValueScale)
        .addProperty("CPRelativePosition", &GCParticleVecInput::GetCPRelativePosition, &GCParticleVecInput::SetCPRelativePosition)
        .addProperty("CPRelativeDir", &GCParticleVecInput::GetCPRelativeDir, &GCParticleVecInput::SetCPRelativeDir)
        .addProperty("FloatComponentX", &GCParticleVecInput::GetFloatComponentX, &GCParticleVecInput::SetFloatComponentX)
        .addProperty("FloatComponentY", &GCParticleVecInput::GetFloatComponentY, &GCParticleVecInput::SetFloatComponentY)
        .addProperty("FloatComponentZ", &GCParticleVecInput::GetFloatComponentZ, &GCParticleVecInput::SetFloatComponentZ)
        .addProperty("FloatInterp", &GCParticleVecInput::GetFloatInterp, &GCParticleVecInput::SetFloatInterp)
        .addProperty("InterpInput0", &GCParticleVecInput::GetInterpInput0, &GCParticleVecInput::SetInterpInput0)
        .addProperty("InterpInput1", &GCParticleVecInput::GetInterpInput1, &GCParticleVecInput::SetInterpInput1)
        .addProperty("InterpOutput0", &GCParticleVecInput::GetInterpOutput0, &GCParticleVecInput::SetInterpOutput0)
        .addProperty("InterpOutput1", &GCParticleVecInput::GetInterpOutput1, &GCParticleVecInput::SetInterpOutput1)
        .addProperty("RandomMin", &GCParticleVecInput::GetRandomMin, &GCParticleVecInput::SetRandomMin)
        .addProperty("RandomMax", &GCParticleVecInput::GetRandomMax, &GCParticleVecInput::SetRandomMax)
        .endClass();
}