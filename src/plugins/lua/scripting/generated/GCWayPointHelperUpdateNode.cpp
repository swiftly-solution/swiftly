#include "../../../core/scripting/generated/classes/GCWayPointHelperUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCWayPointHelperUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWayPointHelperUpdateNode>("CWayPointHelperUpdateNode")
        .addProperty("StartCycle", &GCWayPointHelperUpdateNode::GetStartCycle, &GCWayPointHelperUpdateNode::SetStartCycle)
        .addProperty("EndCycle", &GCWayPointHelperUpdateNode::GetEndCycle, &GCWayPointHelperUpdateNode::SetEndCycle)
        .addProperty("OnlyGoals", &GCWayPointHelperUpdateNode::GetOnlyGoals, &GCWayPointHelperUpdateNode::SetOnlyGoals)
        .addProperty("PreventOvershoot", &GCWayPointHelperUpdateNode::GetPreventOvershoot, &GCWayPointHelperUpdateNode::SetPreventOvershoot)
        .addProperty("PreventUndershoot", &GCWayPointHelperUpdateNode::GetPreventUndershoot, &GCWayPointHelperUpdateNode::SetPreventUndershoot)
        .endClass();
}