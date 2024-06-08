#include "../../../core/scripting/generated/classes/GCStopAtGoalUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCStopAtGoalUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStopAtGoalUpdateNode>("CStopAtGoalUpdateNode")
        .addProperty("OuterRadius", &GCStopAtGoalUpdateNode::GetOuterRadius, &GCStopAtGoalUpdateNode::SetOuterRadius)
        .addProperty("InnerRadius", &GCStopAtGoalUpdateNode::GetInnerRadius, &GCStopAtGoalUpdateNode::SetInnerRadius)
        .addProperty("MaxScale", &GCStopAtGoalUpdateNode::GetMaxScale, &GCStopAtGoalUpdateNode::SetMaxScale)
        .addProperty("MinScale", &GCStopAtGoalUpdateNode::GetMinScale, &GCStopAtGoalUpdateNode::SetMinScale)
        .addProperty("Damping", &GCStopAtGoalUpdateNode::GetDamping, &GCStopAtGoalUpdateNode::SetDamping)
        .endClass();
}