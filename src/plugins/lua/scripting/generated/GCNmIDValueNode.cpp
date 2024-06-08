#include "../../../core/scripting/generated/classes/GCNmIDValueNode.h"
#include "../core.h"

void SetupLuaClassGCNmIDValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmIDValueNode>("CNmIDValueNode")

        .endClass();
}