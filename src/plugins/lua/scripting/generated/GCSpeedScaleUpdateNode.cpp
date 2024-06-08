#include "../../../core/scripting/generated/classes/GCSpeedScaleUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCSpeedScaleUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSpeedScaleUpdateNode>("CSpeedScaleUpdateNode")
        .addProperty("ParamIndex", &GCSpeedScaleUpdateNode::GetParamIndex, &GCSpeedScaleUpdateNode::SetParamIndex)
        .endClass();
}