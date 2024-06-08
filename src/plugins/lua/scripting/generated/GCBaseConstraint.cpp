#include "../../../core/scripting/generated/classes/GCBaseConstraint.h"
#include "../core.h"

void SetupLuaClassGCBaseConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseConstraint>("CBaseConstraint")
        .addProperty("Name", &GCBaseConstraint::GetName, &GCBaseConstraint::SetName)
        .addProperty("UpVector", &GCBaseConstraint::GetUpVector, &GCBaseConstraint::SetUpVector)
        .addProperty("Slaves", &GCBaseConstraint::GetSlaves, &GCBaseConstraint::SetSlaves)
        .addProperty("Targets", &GCBaseConstraint::GetTargets, &GCBaseConstraint::SetTargets)
        .endClass();
}