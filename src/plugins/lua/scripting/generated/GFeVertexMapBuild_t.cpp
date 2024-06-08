#include "../../../core/scripting/generated/classes/GFeVertexMapBuild_t.h"
#include "../core.h"

void SetupLuaClassGFeVertexMapBuild_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeVertexMapBuild_t>("FeVertexMapBuild_t")
        .addProperty("VertexMapName", &GFeVertexMapBuild_t::GetVertexMapName, &GFeVertexMapBuild_t::SetVertexMapName)
        .addProperty("NameHash", &GFeVertexMapBuild_t::GetNameHash, &GFeVertexMapBuild_t::SetNameHash)
        .addProperty("Color", &GFeVertexMapBuild_t::GetColor, &GFeVertexMapBuild_t::SetColor)
        .addProperty("VolumetricSolveStrength", &GFeVertexMapBuild_t::GetVolumetricSolveStrength, &GFeVertexMapBuild_t::SetVolumetricSolveStrength)
        .addProperty("ScaleSourceNode", &GFeVertexMapBuild_t::GetScaleSourceNode, &GFeVertexMapBuild_t::SetScaleSourceNode)
        .addProperty("Weights", &GFeVertexMapBuild_t::GetWeights, &GFeVertexMapBuild_t::SetWeights)
        .endClass();
}