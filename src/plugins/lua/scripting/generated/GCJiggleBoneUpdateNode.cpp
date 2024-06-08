#include "../../../core/scripting/generated/classes/GCJiggleBoneUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCJiggleBoneUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCJiggleBoneUpdateNode>("CJiggleBoneUpdateNode")
        .addProperty("OpFixedData", &GCJiggleBoneUpdateNode::GetOpFixedData, &GCJiggleBoneUpdateNode::SetOpFixedData)
        .endClass();
}