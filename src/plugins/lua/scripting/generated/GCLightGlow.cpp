#include "../../../core/scripting/generated/classes/GCLightGlow.h"
#include "../core.h"

void SetupLuaClassGCLightGlow(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightGlow>("CLightGlow")
        .addProperty("HorizontalSize", &GCLightGlow::GetHorizontalSize, &GCLightGlow::SetHorizontalSize)
        .addProperty("VerticalSize", &GCLightGlow::GetVerticalSize, &GCLightGlow::SetVerticalSize)
        .addProperty("MinDist", &GCLightGlow::GetMinDist, &GCLightGlow::SetMinDist)
        .addProperty("MaxDist", &GCLightGlow::GetMaxDist, &GCLightGlow::SetMaxDist)
        .addProperty("OuterMaxDist", &GCLightGlow::GetOuterMaxDist, &GCLightGlow::SetOuterMaxDist)
        .addProperty("GlowProxySize", &GCLightGlow::GetGlowProxySize, &GCLightGlow::SetGlowProxySize)
        .addProperty("HDRColorScale", &GCLightGlow::GetHDRColorScale, &GCLightGlow::SetHDRColorScale)
        .endClass();
}