#include "../../../core/scripting/generated/classes/GC_OP_RenderScreenShake.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderScreenShake(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderScreenShake>("C_OP_RenderScreenShake")
        .addProperty("DurationScale", &GC_OP_RenderScreenShake::GetDurationScale, &GC_OP_RenderScreenShake::SetDurationScale)
        .addProperty("RadiusScale", &GC_OP_RenderScreenShake::GetRadiusScale, &GC_OP_RenderScreenShake::SetRadiusScale)
        .addProperty("FrequencyScale", &GC_OP_RenderScreenShake::GetFrequencyScale, &GC_OP_RenderScreenShake::SetFrequencyScale)
        .addProperty("AmplitudeScale", &GC_OP_RenderScreenShake::GetAmplitudeScale, &GC_OP_RenderScreenShake::SetAmplitudeScale)
        .addProperty("RadiusField", &GC_OP_RenderScreenShake::GetRadiusField, &GC_OP_RenderScreenShake::SetRadiusField)
        .addProperty("DurationField", &GC_OP_RenderScreenShake::GetDurationField, &GC_OP_RenderScreenShake::SetDurationField)
        .addProperty("FrequencyField", &GC_OP_RenderScreenShake::GetFrequencyField, &GC_OP_RenderScreenShake::SetFrequencyField)
        .addProperty("AmplitudeField", &GC_OP_RenderScreenShake::GetAmplitudeField, &GC_OP_RenderScreenShake::SetAmplitudeField)
        .addProperty("FilterCP", &GC_OP_RenderScreenShake::GetFilterCP, &GC_OP_RenderScreenShake::SetFilterCP)
        .endClass();
}