#include "../../../core/scripting/generated/classes/GC_OP_RenderBlobs.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderBlobs(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderBlobs>("C_OP_RenderBlobs")
        .addProperty("CubeWidth", &GC_OP_RenderBlobs::GetCubeWidth, &GC_OP_RenderBlobs::SetCubeWidth)
        .addProperty("CutoffRadius", &GC_OP_RenderBlobs::GetCutoffRadius, &GC_OP_RenderBlobs::SetCutoffRadius)
        .addProperty("RenderRadius", &GC_OP_RenderBlobs::GetRenderRadius, &GC_OP_RenderBlobs::SetRenderRadius)
        .addProperty("VertexCountKb", &GC_OP_RenderBlobs::GetVertexCountKb, &GC_OP_RenderBlobs::SetVertexCountKb)
        .addProperty("IndexCountKb", &GC_OP_RenderBlobs::GetIndexCountKb, &GC_OP_RenderBlobs::SetIndexCountKb)
        .addProperty("ScaleCP", &GC_OP_RenderBlobs::GetScaleCP, &GC_OP_RenderBlobs::SetScaleCP)
        .addProperty("MaterialVars", &GC_OP_RenderBlobs::GetMaterialVars, &GC_OP_RenderBlobs::SetMaterialVars)
        .endClass();
}