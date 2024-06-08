#include "../../../core/scripting/generated/classes/GCFootStepTriggerUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCFootStepTriggerUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootStepTriggerUpdateNode>("CFootStepTriggerUpdateNode")
        .addProperty("Triggers", &GCFootStepTriggerUpdateNode::GetTriggers, &GCFootStepTriggerUpdateNode::SetTriggers)
        .addProperty("Tolerance", &GCFootStepTriggerUpdateNode::GetTolerance, &GCFootStepTriggerUpdateNode::SetTolerance)
        .endClass();
}