#include "../../../core/scripting/generated/classes/GCConstantForceController.h"
#include "../core.h"

void SetupLuaClassGCConstantForceController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCConstantForceController>("CConstantForceController")
        .addProperty("Linear", &GCConstantForceController::GetLinear, &GCConstantForceController::SetLinear)
        .addProperty("Angular", &GCConstantForceController::GetAngular, &GCConstantForceController::SetAngular)
        .addProperty("LinearSave", &GCConstantForceController::GetLinearSave, &GCConstantForceController::SetLinearSave)
        .addProperty("AngularSave", &GCConstantForceController::GetAngularSave, &GCConstantForceController::SetAngularSave)
        .endClass();
}