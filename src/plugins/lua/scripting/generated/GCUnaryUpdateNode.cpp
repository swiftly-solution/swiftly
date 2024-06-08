#include "../../../core/scripting/generated/classes/GCUnaryUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCUnaryUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCUnaryUpdateNode>("CUnaryUpdateNode")
        .addProperty("ChildNode", &GCUnaryUpdateNode::GetChildNode, &GCUnaryUpdateNode::SetChildNode)
        .endClass();
}