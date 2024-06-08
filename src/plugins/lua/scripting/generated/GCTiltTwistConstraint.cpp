#include "../../../core/scripting/generated/classes/GCTiltTwistConstraint.h"
#include "../core.h"

void SetupLuaClassGCTiltTwistConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTiltTwistConstraint>("CTiltTwistConstraint")
        .addProperty("TargetAxis", &GCTiltTwistConstraint::GetTargetAxis, &GCTiltTwistConstraint::SetTargetAxis)
        .addProperty("SlaveAxis", &GCTiltTwistConstraint::GetSlaveAxis, &GCTiltTwistConstraint::SetSlaveAxis)
        .endClass();
}