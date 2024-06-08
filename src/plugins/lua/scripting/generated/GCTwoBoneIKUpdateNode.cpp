#include "../../../core/scripting/generated/classes/GCTwoBoneIKUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCTwoBoneIKUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTwoBoneIKUpdateNode>("CTwoBoneIKUpdateNode")
        .addProperty("OpFixedData", &GCTwoBoneIKUpdateNode::GetOpFixedData, &GCTwoBoneIKUpdateNode::SetOpFixedData)
        .endClass();
}