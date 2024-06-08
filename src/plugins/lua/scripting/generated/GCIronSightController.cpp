#include "../../../core/scripting/generated/classes/GCIronSightController.h"
#include "../core.h"

void SetupLuaClassGCIronSightController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCIronSightController>("CIronSightController")
        .addProperty("IronSightAvailable", &GCIronSightController::GetIronSightAvailable, &GCIronSightController::SetIronSightAvailable)
        .addProperty("IronSightAmount", &GCIronSightController::GetIronSightAmount, &GCIronSightController::SetIronSightAmount)
        .addProperty("IronSightAmountGained", &GCIronSightController::GetIronSightAmountGained, &GCIronSightController::SetIronSightAmountGained)
        .addProperty("IronSightAmountBiased", &GCIronSightController::GetIronSightAmountBiased, &GCIronSightController::SetIronSightAmountBiased)
        .endClass();
}