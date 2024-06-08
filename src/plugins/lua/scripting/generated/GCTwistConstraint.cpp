#include "../../../core/scripting/generated/classes/GCTwistConstraint.h"
#include "../core.h"

void SetupLuaClassGCTwistConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTwistConstraint>("CTwistConstraint")
        .addProperty("Inverse", &GCTwistConstraint::GetInverse, &GCTwistConstraint::SetInverse)
        .addProperty("ParentBindRotation", &GCTwistConstraint::GetParentBindRotation, &GCTwistConstraint::SetParentBindRotation)
        .addProperty("ChildBindRotation", &GCTwistConstraint::GetChildBindRotation, &GCTwistConstraint::SetChildBindRotation)
        .endClass();
}