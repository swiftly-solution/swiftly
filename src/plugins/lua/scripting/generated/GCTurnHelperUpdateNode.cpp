#include "../../../core/scripting/generated/classes/GCTurnHelperUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCTurnHelperUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTurnHelperUpdateNode>("CTurnHelperUpdateNode")
        .addProperty("FacingTarget", &GCTurnHelperUpdateNode::GetFacingTarget, &GCTurnHelperUpdateNode::SetFacingTarget)
        .addProperty("TurnStartTimeOffset", &GCTurnHelperUpdateNode::GetTurnStartTimeOffset, &GCTurnHelperUpdateNode::SetTurnStartTimeOffset)
        .addProperty("TurnDuration", &GCTurnHelperUpdateNode::GetTurnDuration, &GCTurnHelperUpdateNode::SetTurnDuration)
        .addProperty("MatchChildDuration", &GCTurnHelperUpdateNode::GetMatchChildDuration, &GCTurnHelperUpdateNode::SetMatchChildDuration)
        .addProperty("ManualTurnOffset", &GCTurnHelperUpdateNode::GetManualTurnOffset, &GCTurnHelperUpdateNode::SetManualTurnOffset)
        .addProperty("UseManualTurnOffset", &GCTurnHelperUpdateNode::GetUseManualTurnOffset, &GCTurnHelperUpdateNode::SetUseManualTurnOffset)
        .endClass();
}