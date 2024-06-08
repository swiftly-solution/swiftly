#include "../../../core/scripting/generated/classes/GC_OP_RenderAsModels.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderAsModels(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderAsModels>("C_OP_RenderAsModels")
        .addProperty("ModelList", &GC_OP_RenderAsModels::GetModelList, &GC_OP_RenderAsModels::SetModelList)
        .addProperty("ModelScale", &GC_OP_RenderAsModels::GetModelScale, &GC_OP_RenderAsModels::SetModelScale)
        .addProperty("FitToModelSize", &GC_OP_RenderAsModels::GetFitToModelSize, &GC_OP_RenderAsModels::SetFitToModelSize)
        .addProperty("NonUniformScaling", &GC_OP_RenderAsModels::GetNonUniformScaling, &GC_OP_RenderAsModels::SetNonUniformScaling)
        .addProperty("XAxisScalingAttribute", &GC_OP_RenderAsModels::GetXAxisScalingAttribute, &GC_OP_RenderAsModels::SetXAxisScalingAttribute)
        .addProperty("YAxisScalingAttribute", &GC_OP_RenderAsModels::GetYAxisScalingAttribute, &GC_OP_RenderAsModels::SetYAxisScalingAttribute)
        .addProperty("ZAxisScalingAttribute", &GC_OP_RenderAsModels::GetZAxisScalingAttribute, &GC_OP_RenderAsModels::SetZAxisScalingAttribute)
        .addProperty("SizeCullBloat", &GC_OP_RenderAsModels::GetSizeCullBloat, &GC_OP_RenderAsModels::SetSizeCullBloat)
        .endClass();
}