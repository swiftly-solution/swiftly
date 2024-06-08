#include "../../../core/scripting/generated/classes/Gconstraint_hingeparams_t.h"
#include "../core.h"

void SetupLuaClassGconstraint_hingeparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gconstraint_hingeparams_t>("constraint_hingeparams_t")
        .addProperty("WorldPosition", &Gconstraint_hingeparams_t::GetWorldPosition, &Gconstraint_hingeparams_t::SetWorldPosition)
        .addProperty("WorldAxisDirection", &Gconstraint_hingeparams_t::GetWorldAxisDirection, &Gconstraint_hingeparams_t::SetWorldAxisDirection)
        .addProperty("HingeAxis", &Gconstraint_hingeparams_t::GetHingeAxis, &Gconstraint_hingeparams_t::SetHingeAxis)
        .addProperty("Constraint", &Gconstraint_hingeparams_t::GetConstraint, &Gconstraint_hingeparams_t::SetConstraint)
        .endClass();
}