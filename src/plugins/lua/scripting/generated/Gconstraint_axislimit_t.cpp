#include "../../../core/scripting/generated/classes/Gconstraint_axislimit_t.h"
#include "../core.h"

void SetupLuaClassGconstraint_axislimit_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gconstraint_axislimit_t>("constraint_axislimit_t")
        .addProperty("MinRotation", &Gconstraint_axislimit_t::GetMinRotation, &Gconstraint_axislimit_t::SetMinRotation)
        .addProperty("MaxRotation", &Gconstraint_axislimit_t::GetMaxRotation, &Gconstraint_axislimit_t::SetMaxRotation)
        .addProperty("MotorTargetAngSpeed", &Gconstraint_axislimit_t::GetMotorTargetAngSpeed, &Gconstraint_axislimit_t::SetMotorTargetAngSpeed)
        .addProperty("MotorMaxTorque", &Gconstraint_axislimit_t::GetMotorMaxTorque, &Gconstraint_axislimit_t::SetMotorMaxTorque)
        .endClass();
}