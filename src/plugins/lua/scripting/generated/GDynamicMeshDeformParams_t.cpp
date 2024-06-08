#include "../../../core/scripting/generated/classes/GDynamicMeshDeformParams_t.h"
#include "../core.h"

void SetupLuaClassGDynamicMeshDeformParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GDynamicMeshDeformParams_t>("DynamicMeshDeformParams_t")
        .addProperty("TensionCompressScale", &GDynamicMeshDeformParams_t::GetTensionCompressScale, &GDynamicMeshDeformParams_t::SetTensionCompressScale)
        .addProperty("TensionStretchScale", &GDynamicMeshDeformParams_t::GetTensionStretchScale, &GDynamicMeshDeformParams_t::SetTensionStretchScale)
        .addProperty("RecomputeSmoothNormalsAfterAnimation", &GDynamicMeshDeformParams_t::GetRecomputeSmoothNormalsAfterAnimation, &GDynamicMeshDeformParams_t::SetRecomputeSmoothNormalsAfterAnimation)
        .addProperty("ComputeDynamicMeshTensionAfterAnimation", &GDynamicMeshDeformParams_t::GetComputeDynamicMeshTensionAfterAnimation, &GDynamicMeshDeformParams_t::SetComputeDynamicMeshTensionAfterAnimation)
        .endClass();
}