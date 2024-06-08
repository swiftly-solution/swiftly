#include "../../../core/scripting/generated/classes/GC_IronSightController.h"
#include "../core.h"

void SetupLuaClassGC_IronSightController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_IronSightController>("C_IronSightController")
        .addProperty("IronSightAvailable", &GC_IronSightController::GetIronSightAvailable, &GC_IronSightController::SetIronSightAvailable)
        .addProperty("IronSightAmount", &GC_IronSightController::GetIronSightAmount, &GC_IronSightController::SetIronSightAmount)
        .addProperty("IronSightAmountGained", &GC_IronSightController::GetIronSightAmountGained, &GC_IronSightController::SetIronSightAmountGained)
        .addProperty("IronSightAmountBiased", &GC_IronSightController::GetIronSightAmountBiased, &GC_IronSightController::SetIronSightAmountBiased)
        .addProperty("IronSightAmount_Interpolated", &GC_IronSightController::GetIronSightAmount_Interpolated, &GC_IronSightController::SetIronSightAmount_Interpolated)
        .addProperty("IronSightAmountGained_Interpolated", &GC_IronSightController::GetIronSightAmountGained_Interpolated, &GC_IronSightController::SetIronSightAmountGained_Interpolated)
        .addProperty("IronSightAmountBiased_Interpolated", &GC_IronSightController::GetIronSightAmountBiased_Interpolated, &GC_IronSightController::SetIronSightAmountBiased_Interpolated)
        .addProperty("InterpolationLastUpdated", &GC_IronSightController::GetInterpolationLastUpdated, &GC_IronSightController::SetInterpolationLastUpdated)
        .addProperty("DeltaAverage", &GC_IronSightController::GetDeltaAverage, &GC_IronSightController::SetDeltaAverage)
        .addProperty("ViewLast", &GC_IronSightController::GetViewLast, &GC_IronSightController::SetViewLast)
        .addProperty("DotCoords", &GC_IronSightController::GetDotCoords, &GC_IronSightController::SetDotCoords)
        .addProperty("DotBlur", &GC_IronSightController::GetDotBlur, &GC_IronSightController::SetDotBlur)
        .addProperty("SpeedRatio", &GC_IronSightController::GetSpeedRatio, &GC_IronSightController::SetSpeedRatio)
        .endClass();
}