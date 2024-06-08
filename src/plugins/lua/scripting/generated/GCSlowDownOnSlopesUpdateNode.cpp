#include "../../../core/scripting/generated/classes/GCSlowDownOnSlopesUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCSlowDownOnSlopesUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSlowDownOnSlopesUpdateNode>("CSlowDownOnSlopesUpdateNode")
        .addProperty("SlowDownStrength", &GCSlowDownOnSlopesUpdateNode::GetSlowDownStrength, &GCSlowDownOnSlopesUpdateNode::SetSlowDownStrength)
        .endClass();
}