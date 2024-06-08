#include "../../../core/scripting/generated/classes/GCClientAlphaProperty.h"
#include "../core.h"

void SetupLuaClassGCClientAlphaProperty(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCClientAlphaProperty>("CClientAlphaProperty")
        .addProperty("RenderFX", &GCClientAlphaProperty::GetRenderFX, &GCClientAlphaProperty::SetRenderFX)
        .addProperty("RenderMode", &GCClientAlphaProperty::GetRenderMode, &GCClientAlphaProperty::SetRenderMode)
        .addProperty("Alpha", &GCClientAlphaProperty::GetAlpha, &GCClientAlphaProperty::SetAlpha)
        .addProperty("DesyncOffset", &GCClientAlphaProperty::GetDesyncOffset, &GCClientAlphaProperty::SetDesyncOffset)
        .addProperty("Reserved2", &GCClientAlphaProperty::GetReserved2, &GCClientAlphaProperty::SetReserved2)
        .addProperty("DistFadeStart", &GCClientAlphaProperty::GetDistFadeStart, &GCClientAlphaProperty::SetDistFadeStart)
        .addProperty("DistFadeEnd", &GCClientAlphaProperty::GetDistFadeEnd, &GCClientAlphaProperty::SetDistFadeEnd)
        .addProperty("FadeScale", &GCClientAlphaProperty::GetFadeScale, &GCClientAlphaProperty::SetFadeScale)
        .addProperty("RenderFxDuration", &GCClientAlphaProperty::GetRenderFxDuration, &GCClientAlphaProperty::SetRenderFxDuration)
        .endClass();
}