#include "../../../core/scripting/generated/classes/GFeTwistConstraint_t.h"
#include "../core.h"

void SetupLuaClassGFeTwistConstraint_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeTwistConstraint_t>("FeTwistConstraint_t")
        .addProperty("NodeOrient", &GFeTwistConstraint_t::GetNodeOrient, &GFeTwistConstraint_t::SetNodeOrient)
        .addProperty("NodeEnd", &GFeTwistConstraint_t::GetNodeEnd, &GFeTwistConstraint_t::SetNodeEnd)
        .addProperty("TwistRelax", &GFeTwistConstraint_t::GetTwistRelax, &GFeTwistConstraint_t::SetTwistRelax)
        .addProperty("SwingRelax", &GFeTwistConstraint_t::GetSwingRelax, &GFeTwistConstraint_t::SetSwingRelax)
        .endClass();
}