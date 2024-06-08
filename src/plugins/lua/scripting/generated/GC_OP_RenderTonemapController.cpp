#include "../../../core/scripting/generated/classes/GC_OP_RenderTonemapController.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderTonemapController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderTonemapController>("C_OP_RenderTonemapController")
        .addProperty("TonemapLevel", &GC_OP_RenderTonemapController::GetTonemapLevel, &GC_OP_RenderTonemapController::SetTonemapLevel)
        .addProperty("TonemapWeight", &GC_OP_RenderTonemapController::GetTonemapWeight, &GC_OP_RenderTonemapController::SetTonemapWeight)
        .addProperty("TonemapLevelField", &GC_OP_RenderTonemapController::GetTonemapLevelField, &GC_OP_RenderTonemapController::SetTonemapLevelField)
        .addProperty("TonemapWeightField", &GC_OP_RenderTonemapController::GetTonemapWeightField, &GC_OP_RenderTonemapController::SetTonemapWeightField)
        .endClass();
}