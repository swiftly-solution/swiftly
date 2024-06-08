#include "../../../core/scripting/generated/classes/GCSolveIKChainUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCSolveIKChainUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSolveIKChainUpdateNode>("CSolveIKChainUpdateNode")
        .addProperty("TargetHandles", &GCSolveIKChainUpdateNode::GetTargetHandles, &GCSolveIKChainUpdateNode::SetTargetHandles)
        .addProperty("OpFixedData", &GCSolveIKChainUpdateNode::GetOpFixedData, &GCSolveIKChainUpdateNode::SetOpFixedData)
        .endClass();
}