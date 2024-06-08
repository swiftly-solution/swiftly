#include "../../../core/scripting/generated/classes/GCNmBoolValueNode.h"
#include "../core.h"

void SetupLuaClassGCNmBoolValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmBoolValueNode>("CNmBoolValueNode")

        .endClass();
}