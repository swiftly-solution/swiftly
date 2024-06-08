#include "../../../core/scripting/generated/classes/GCCycleControlUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCCycleControlUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCycleControlUpdateNode>("CCycleControlUpdateNode")
        .addProperty("ValueSource", &GCCycleControlUpdateNode::GetValueSource, &GCCycleControlUpdateNode::SetValueSource)
        .addProperty("ParamIndex", &GCCycleControlUpdateNode::GetParamIndex, &GCCycleControlUpdateNode::SetParamIndex)
        .endClass();
}