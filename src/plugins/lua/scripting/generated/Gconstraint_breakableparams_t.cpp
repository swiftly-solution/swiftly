#include "../../../core/scripting/generated/classes/Gconstraint_breakableparams_t.h"
#include "../core.h"

void SetupLuaClassGconstraint_breakableparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gconstraint_breakableparams_t>("constraint_breakableparams_t")
        .addProperty("Strength", &Gconstraint_breakableparams_t::GetStrength, &Gconstraint_breakableparams_t::SetStrength)
        .addProperty("ForceLimit", &Gconstraint_breakableparams_t::GetForceLimit, &Gconstraint_breakableparams_t::SetForceLimit)
        .addProperty("TorqueLimit", &Gconstraint_breakableparams_t::GetTorqueLimit, &Gconstraint_breakableparams_t::SetTorqueLimit)
        .addProperty("BodyMassScale", &Gconstraint_breakableparams_t::GetBodyMassScale, &Gconstraint_breakableparams_t::SetBodyMassScale)
        .addProperty("IsActive", &Gconstraint_breakableparams_t::GetIsActive, &Gconstraint_breakableparams_t::SetIsActive)
        .endClass();
}