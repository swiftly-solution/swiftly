#include "../../../core/scripting/generated/classes/GCNmVectorValueNode.h"
#include "../core.h"

void SetupLuaClassGCNmVectorValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmVectorValueNode>("CNmVectorValueNode")

        .endClass();
}