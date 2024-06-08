#include "../../../core/scripting/generated/classes/GCPathHelperUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCPathHelperUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathHelperUpdateNode>("CPathHelperUpdateNode")
        .addProperty("StoppingRadius", &GCPathHelperUpdateNode::GetStoppingRadius, &GCPathHelperUpdateNode::SetStoppingRadius)
        .addProperty("StoppingSpeedScale", &GCPathHelperUpdateNode::GetStoppingSpeedScale, &GCPathHelperUpdateNode::SetStoppingSpeedScale)
        .endClass();
}