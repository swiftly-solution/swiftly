#include "../../../core/scripting/generated/classes/GCStanceScaleUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCStanceScaleUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStanceScaleUpdateNode>("CStanceScaleUpdateNode")
        .addProperty("Param", &GCStanceScaleUpdateNode::GetParam, &GCStanceScaleUpdateNode::SetParam)
        .endClass();
}