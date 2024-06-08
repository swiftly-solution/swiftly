#include "../../../core/scripting/generated/classes/GC_LightGlowOverlay.h"
#include "../core.h"

void SetupLuaClassGC_LightGlowOverlay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_LightGlowOverlay>("C_LightGlowOverlay")
        .addProperty("Origin", &GC_LightGlowOverlay::GetOrigin, &GC_LightGlowOverlay::SetOrigin)
        .addProperty("Direction", &GC_LightGlowOverlay::GetDirection, &GC_LightGlowOverlay::SetDirection)
        .addProperty("MinDist", &GC_LightGlowOverlay::GetMinDist, &GC_LightGlowOverlay::SetMinDist)
        .addProperty("MaxDist", &GC_LightGlowOverlay::GetMaxDist, &GC_LightGlowOverlay::SetMaxDist)
        .addProperty("OuterMaxDist", &GC_LightGlowOverlay::GetOuterMaxDist, &GC_LightGlowOverlay::SetOuterMaxDist)
        .addProperty("OneSided", &GC_LightGlowOverlay::GetOneSided, &GC_LightGlowOverlay::SetOneSided)
        .addProperty("ModulateByDot", &GC_LightGlowOverlay::GetModulateByDot, &GC_LightGlowOverlay::SetModulateByDot)
        .endClass();
}