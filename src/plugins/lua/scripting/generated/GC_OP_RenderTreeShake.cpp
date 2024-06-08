#include "../../../core/scripting/generated/classes/GC_OP_RenderTreeShake.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderTreeShake(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderTreeShake>("C_OP_RenderTreeShake")
        .addProperty("PeakStrength", &GC_OP_RenderTreeShake::GetPeakStrength, &GC_OP_RenderTreeShake::SetPeakStrength)
        .addProperty("PeakStrengthFieldOverride", &GC_OP_RenderTreeShake::GetPeakStrengthFieldOverride, &GC_OP_RenderTreeShake::SetPeakStrengthFieldOverride)
        .addProperty("Radius", &GC_OP_RenderTreeShake::GetRadius, &GC_OP_RenderTreeShake::SetRadius)
        .addProperty("RadiusFieldOverride", &GC_OP_RenderTreeShake::GetRadiusFieldOverride, &GC_OP_RenderTreeShake::SetRadiusFieldOverride)
        .addProperty("ShakeDuration", &GC_OP_RenderTreeShake::GetShakeDuration, &GC_OP_RenderTreeShake::SetShakeDuration)
        .addProperty("TransitionTime", &GC_OP_RenderTreeShake::GetTransitionTime, &GC_OP_RenderTreeShake::SetTransitionTime)
        .addProperty("TwistAmount", &GC_OP_RenderTreeShake::GetTwistAmount, &GC_OP_RenderTreeShake::SetTwistAmount)
        .addProperty("RadialAmount", &GC_OP_RenderTreeShake::GetRadialAmount, &GC_OP_RenderTreeShake::SetRadialAmount)
        .addProperty("ControlPointOrientationAmount", &GC_OP_RenderTreeShake::GetControlPointOrientationAmount, &GC_OP_RenderTreeShake::SetControlPointOrientationAmount)
        .addProperty("ControlPointForLinearDirection", &GC_OP_RenderTreeShake::GetControlPointForLinearDirection, &GC_OP_RenderTreeShake::SetControlPointForLinearDirection)
        .endClass();
}