#include "../../../core/scripting/generated/classes/GCNmTargetValueNode.h"
#include "../core.h"

void SetupLuaClassGCNmTargetValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmTargetValueNode>("CNmTargetValueNode")

        .endClass();
}