#include "../../../core/scripting/generated/classes/GCNmControlParameterBoolNode.h"
#include "../core.h"

void SetupLuaClassGCNmControlParameterBoolNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmControlParameterBoolNode>("CNmControlParameterBoolNode")

        .endClass();
}