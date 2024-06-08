#include "../../../core/scripting/generated/classes/GBakedLightingInfo_t.h"
#include "../core.h"

void SetupLuaClassGBakedLightingInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GBakedLightingInfo_t>("BakedLightingInfo_t")
        .addProperty("LightmapVersionNumber", &GBakedLightingInfo_t::GetLightmapVersionNumber, &GBakedLightingInfo_t::SetLightmapVersionNumber)
        .addProperty("LightmapGameVersionNumber", &GBakedLightingInfo_t::GetLightmapGameVersionNumber, &GBakedLightingInfo_t::SetLightmapGameVersionNumber)
        .addProperty("LightmapUvScale", &GBakedLightingInfo_t::GetLightmapUvScale, &GBakedLightingInfo_t::SetLightmapUvScale)
        .addProperty("HasLightmaps", &GBakedLightingInfo_t::GetHasLightmaps, &GBakedLightingInfo_t::SetHasLightmaps)
        .addProperty("BakedShadowsGamma20", &GBakedLightingInfo_t::GetBakedShadowsGamma20, &GBakedLightingInfo_t::SetBakedShadowsGamma20)
        .addProperty("CompressionEnabled", &GBakedLightingInfo_t::GetCompressionEnabled, &GBakedLightingInfo_t::SetCompressionEnabled)
        .addProperty("ChartPackIterations", &GBakedLightingInfo_t::GetChartPackIterations, &GBakedLightingInfo_t::SetChartPackIterations)
        .addProperty("VradQuality", &GBakedLightingInfo_t::GetVradQuality, &GBakedLightingInfo_t::SetVradQuality)
        .endClass();
}