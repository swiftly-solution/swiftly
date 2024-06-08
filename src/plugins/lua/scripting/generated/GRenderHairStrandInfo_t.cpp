#include "../../../core/scripting/generated/classes/GRenderHairStrandInfo_t.h"
#include "../core.h"

void SetupLuaClassGRenderHairStrandInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRenderHairStrandInfo_t>("RenderHairStrandInfo_t")
        .addProperty("GuideHairIndices_nSurfaceTriIndex", &GRenderHairStrandInfo_t::GetGuideHairIndices_nSurfaceTriIndex, &GRenderHairStrandInfo_t::SetGuideHairIndices_nSurfaceTriIndex)
        .addProperty("GuideBary_vBaseBary", &GRenderHairStrandInfo_t::GetGuideBary_vBaseBary, &GRenderHairStrandInfo_t::SetGuideBary_vBaseBary)
        .addProperty("RootOffset_flLengthScale", &GRenderHairStrandInfo_t::GetRootOffset_flLengthScale, &GRenderHairStrandInfo_t::SetRootOffset_flLengthScale)
        .addProperty("PackedBaseUv", &GRenderHairStrandInfo_t::GetPackedBaseUv, &GRenderHairStrandInfo_t::SetPackedBaseUv)
        .addProperty("PackedSurfaceNormalOs", &GRenderHairStrandInfo_t::GetPackedSurfaceNormalOs, &GRenderHairStrandInfo_t::SetPackedSurfaceNormalOs)
        .addProperty("PackedSurfaceTangentOs", &GRenderHairStrandInfo_t::GetPackedSurfaceTangentOs, &GRenderHairStrandInfo_t::SetPackedSurfaceTangentOs)
        .endClass();
}