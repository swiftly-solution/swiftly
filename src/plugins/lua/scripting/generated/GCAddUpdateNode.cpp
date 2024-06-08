#include "../../../core/scripting/generated/classes/GCAddUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCAddUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAddUpdateNode>("CAddUpdateNode")
        .addProperty("FootMotionTiming", &GCAddUpdateNode::GetFootMotionTiming, &GCAddUpdateNode::SetFootMotionTiming)
        .addProperty("ApplyToFootMotion", &GCAddUpdateNode::GetApplyToFootMotion, &GCAddUpdateNode::SetApplyToFootMotion)
        .addProperty("ApplyChannelsSeparately", &GCAddUpdateNode::GetApplyChannelsSeparately, &GCAddUpdateNode::SetApplyChannelsSeparately)
        .addProperty("UseModelSpace", &GCAddUpdateNode::GetUseModelSpace, &GCAddUpdateNode::SetUseModelSpace)
        .addProperty("ApplyScale", &GCAddUpdateNode::GetApplyScale, &GCAddUpdateNode::SetApplyScale)
        .endClass();
}