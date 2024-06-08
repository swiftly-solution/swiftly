#include "../../../core/scripting/generated/classes/GCBinaryUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCBinaryUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBinaryUpdateNode>("CBinaryUpdateNode")
        .addProperty("Child1", &GCBinaryUpdateNode::GetChild1, &GCBinaryUpdateNode::SetChild1)
        .addProperty("Child2", &GCBinaryUpdateNode::GetChild2, &GCBinaryUpdateNode::SetChild2)
        .addProperty("TimingBehavior", &GCBinaryUpdateNode::GetTimingBehavior, &GCBinaryUpdateNode::SetTimingBehavior)
        .addProperty("TimingBlend", &GCBinaryUpdateNode::GetTimingBlend, &GCBinaryUpdateNode::SetTimingBlend)
        .addProperty("ResetChild1", &GCBinaryUpdateNode::GetResetChild1, &GCBinaryUpdateNode::SetResetChild1)
        .addProperty("ResetChild2", &GCBinaryUpdateNode::GetResetChild2, &GCBinaryUpdateNode::SetResetChild2)
        .endClass();
}