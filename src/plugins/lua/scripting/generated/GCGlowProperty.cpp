#include "../../../core/scripting/generated/classes/GCGlowProperty.h"
#include "../core.h"

void SetupLuaClassGCGlowProperty(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGlowProperty>("CGlowProperty")
        .addProperty("GlowColor", &GCGlowProperty::GetGlowColor, &GCGlowProperty::SetGlowColor)
        .addProperty("GlowType", &GCGlowProperty::GetGlowType, &GCGlowProperty::SetGlowType)
        .addProperty("GlowTeam", &GCGlowProperty::GetGlowTeam, &GCGlowProperty::SetGlowTeam)
        .addProperty("GlowRange", &GCGlowProperty::GetGlowRange, &GCGlowProperty::SetGlowRange)
        .addProperty("GlowRangeMin", &GCGlowProperty::GetGlowRangeMin, &GCGlowProperty::SetGlowRangeMin)
        .addProperty("GlowColorOverride", &GCGlowProperty::GetGlowColorOverride, &GCGlowProperty::SetGlowColorOverride)
        .addProperty("Flashing", &GCGlowProperty::GetFlashing, &GCGlowProperty::SetFlashing)
        .addProperty("GlowTime", &GCGlowProperty::GetGlowTime, &GCGlowProperty::SetGlowTime)
        .addProperty("GlowStartTime", &GCGlowProperty::GetGlowStartTime, &GCGlowProperty::SetGlowStartTime)
        .addProperty("EligibleForScreenHighlight", &GCGlowProperty::GetEligibleForScreenHighlight, &GCGlowProperty::SetEligibleForScreenHighlight)
        .addProperty("Glowing", &GCGlowProperty::GetGlowing, &GCGlowProperty::SetGlowing)
        .endClass();
}