#include "../../../core/scripting/generated/classes/GCNmValueNode.h"
#include "../core.h"

void SetupLuaClassGCNmValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmValueNode>("CNmValueNode")

        .endClass();
}