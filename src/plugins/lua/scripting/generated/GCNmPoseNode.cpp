#include "../../../core/scripting/generated/classes/GCNmPoseNode.h"
#include "../core.h"

void SetupLuaClassGCNmPoseNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmPoseNode>("CNmPoseNode")

        .endClass();
}