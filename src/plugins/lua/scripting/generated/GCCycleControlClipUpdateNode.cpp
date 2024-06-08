#include "../../../core/scripting/generated/classes/GCCycleControlClipUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCCycleControlClipUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCycleControlClipUpdateNode>("CCycleControlClipUpdateNode")
        .addProperty("Tags", &GCCycleControlClipUpdateNode::GetTags, &GCCycleControlClipUpdateNode::SetTags)
        .addProperty("Duration", &GCCycleControlClipUpdateNode::GetDuration, &GCCycleControlClipUpdateNode::SetDuration)
        .addProperty("ValueSource", &GCCycleControlClipUpdateNode::GetValueSource, &GCCycleControlClipUpdateNode::SetValueSource)
        .addProperty("ParamIndex", &GCCycleControlClipUpdateNode::GetParamIndex, &GCCycleControlClipUpdateNode::SetParamIndex)
        .endClass();
}