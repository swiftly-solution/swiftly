#include "../../../core/scripting/generated/classes/GCParticleFunction.h"
#include "../core.h"

void SetupLuaClassGCParticleFunction(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunction>("CParticleFunction")
        .addProperty("OpStrength", &GCParticleFunction::GetOpStrength, &GCParticleFunction::SetOpStrength)
        .addProperty("OpEndCapState", &GCParticleFunction::GetOpEndCapState, &GCParticleFunction::SetOpEndCapState)
        .addProperty("OpStartFadeInTime", &GCParticleFunction::GetOpStartFadeInTime, &GCParticleFunction::SetOpStartFadeInTime)
        .addProperty("OpEndFadeInTime", &GCParticleFunction::GetOpEndFadeInTime, &GCParticleFunction::SetOpEndFadeInTime)
        .addProperty("OpStartFadeOutTime", &GCParticleFunction::GetOpStartFadeOutTime, &GCParticleFunction::SetOpStartFadeOutTime)
        .addProperty("OpEndFadeOutTime", &GCParticleFunction::GetOpEndFadeOutTime, &GCParticleFunction::SetOpEndFadeOutTime)
        .addProperty("OpFadeOscillatePeriod", &GCParticleFunction::GetOpFadeOscillatePeriod, &GCParticleFunction::SetOpFadeOscillatePeriod)
        .addProperty("NormalizeToStopTime", &GCParticleFunction::GetNormalizeToStopTime, &GCParticleFunction::SetNormalizeToStopTime)
        .addProperty("OpTimeOffsetMin", &GCParticleFunction::GetOpTimeOffsetMin, &GCParticleFunction::SetOpTimeOffsetMin)
        .addProperty("OpTimeOffsetMax", &GCParticleFunction::GetOpTimeOffsetMax, &GCParticleFunction::SetOpTimeOffsetMax)
        .addProperty("OpTimeOffsetSeed", &GCParticleFunction::GetOpTimeOffsetSeed, &GCParticleFunction::SetOpTimeOffsetSeed)
        .addProperty("OpTimeScaleSeed", &GCParticleFunction::GetOpTimeScaleSeed, &GCParticleFunction::SetOpTimeScaleSeed)
        .addProperty("OpTimeScaleMin", &GCParticleFunction::GetOpTimeScaleMin, &GCParticleFunction::SetOpTimeScaleMin)
        .addProperty("OpTimeScaleMax", &GCParticleFunction::GetOpTimeScaleMax, &GCParticleFunction::SetOpTimeScaleMax)
        .addProperty("DisableOperator", &GCParticleFunction::GetDisableOperator, &GCParticleFunction::SetDisableOperator)
        .addProperty("Notes", &GCParticleFunction::GetNotes, &GCParticleFunction::SetNotes)
        .endClass();
}