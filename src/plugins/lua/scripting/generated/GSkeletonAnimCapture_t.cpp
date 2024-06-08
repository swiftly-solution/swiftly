#include "../../../core/scripting/generated/classes/GSkeletonAnimCapture_t.h"
#include "../core.h"

void SetupLuaClassGSkeletonAnimCapture_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonAnimCapture_t>("SkeletonAnimCapture_t")
        .addProperty("EntIndex", &GSkeletonAnimCapture_t::GetEntIndex, &GSkeletonAnimCapture_t::SetEntIndex)
        .addProperty("EntParent", &GSkeletonAnimCapture_t::GetEntParent, &GSkeletonAnimCapture_t::SetEntParent)
        .addProperty("ImportedCollision", &GSkeletonAnimCapture_t::GetImportedCollision, &GSkeletonAnimCapture_t::SetImportedCollision)
        .addProperty("ModelName", &GSkeletonAnimCapture_t::GetModelName, &GSkeletonAnimCapture_t::SetModelName)
        .addProperty("CaptureName", &GSkeletonAnimCapture_t::GetCaptureName, &GSkeletonAnimCapture_t::SetCaptureName)
        .addProperty("ModelBindPose", &GSkeletonAnimCapture_t::GetModelBindPose, &GSkeletonAnimCapture_t::SetModelBindPose)
        .addProperty("FeModelInitPose", &GSkeletonAnimCapture_t::GetFeModelInitPose, &GSkeletonAnimCapture_t::SetFeModelInitPose)
        .addProperty("FlexControllers", &GSkeletonAnimCapture_t::GetFlexControllers, &GSkeletonAnimCapture_t::SetFlexControllers)
        .addProperty("Predicted", &GSkeletonAnimCapture_t::GetPredicted, &GSkeletonAnimCapture_t::SetPredicted)
        .addProperty("Frames", &GSkeletonAnimCapture_t::GetFrames, &GSkeletonAnimCapture_t::SetFrames)
        .endClass();
}