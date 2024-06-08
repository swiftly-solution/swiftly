#include "../../../core/scripting/generated/classes/GC_OP_RenderGpuImplicit.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderGpuImplicit(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderGpuImplicit>("C_OP_RenderGpuImplicit")
        .addProperty("UsePerParticleRadius", &GC_OP_RenderGpuImplicit::GetUsePerParticleRadius, &GC_OP_RenderGpuImplicit::SetUsePerParticleRadius)
        .addProperty("VertexCountKb", &GC_OP_RenderGpuImplicit::GetVertexCountKb, &GC_OP_RenderGpuImplicit::SetVertexCountKb)
        .addProperty("IndexCountKb", &GC_OP_RenderGpuImplicit::GetIndexCountKb, &GC_OP_RenderGpuImplicit::SetIndexCountKb)
        .addProperty("GridSize", &GC_OP_RenderGpuImplicit::GetGridSize, &GC_OP_RenderGpuImplicit::SetGridSize)
        .addProperty("RadiusScale", &GC_OP_RenderGpuImplicit::GetRadiusScale, &GC_OP_RenderGpuImplicit::SetRadiusScale)
        .addProperty("IsosurfaceThreshold", &GC_OP_RenderGpuImplicit::GetIsosurfaceThreshold, &GC_OP_RenderGpuImplicit::SetIsosurfaceThreshold)
        .addProperty("ScaleCP", &GC_OP_RenderGpuImplicit::GetScaleCP, &GC_OP_RenderGpuImplicit::SetScaleCP)
        .endClass();
}