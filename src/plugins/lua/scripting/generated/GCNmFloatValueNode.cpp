#include "../../../core/scripting/generated/classes/GCNmFloatValueNode.h"
#include "../core.h"

void SetupLuaClassGCNmFloatValueNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmFloatValueNode>("CNmFloatValueNode")

        .endClass();
}