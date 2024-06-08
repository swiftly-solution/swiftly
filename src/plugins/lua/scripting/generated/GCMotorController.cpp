#include "../../../core/scripting/generated/classes/GCMotorController.h"
#include "../core.h"

void SetupLuaClassGCMotorController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotorController>("CMotorController")
        .addProperty("Speed", &GCMotorController::GetSpeed, &GCMotorController::SetSpeed)
        .addProperty("MaxTorque", &GCMotorController::GetMaxTorque, &GCMotorController::SetMaxTorque)
        .addProperty("Axis", &GCMotorController::GetAxis, &GCMotorController::SetAxis)
        .addProperty("InertiaFactor", &GCMotorController::GetInertiaFactor, &GCMotorController::SetInertiaFactor)
        .endClass();
}