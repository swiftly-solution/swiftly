#include "../../../core/scripting/generated/classes/GCNmBoneMaskValueNode.h"
#include "../core.h"

void SetupLuaClassGCNmBoneMaskValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmBoneMaskValueNode>("CNmBoneMaskValueNode")

        .endClass();
}