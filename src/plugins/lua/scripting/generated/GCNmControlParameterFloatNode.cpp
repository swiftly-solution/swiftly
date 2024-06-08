#include "../../../core/scripting/generated/classes/GCNmControlParameterFloatNode.h"
#include "../core.h"

void SetupLuaClassGCNmControlParameterFloatNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmControlParameterFloatNode>("CNmControlParameterFloatNode")

        .endClass();
}