#include "../../../core/scripting/generated/classes/GCNmControlParameterTargetNode.h"
#include "../core.h"

void SetupLuaClassGCNmControlParameterTargetNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmControlParameterTargetNode>("CNmControlParameterTargetNode")

        .endClass();
}