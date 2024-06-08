#include "../../../core/scripting/generated/classes/GCNmControlParameterIDNode.h"
#include "../core.h"

void SetupLuaClassGCNmControlParameterIDNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmControlParameterIDNode>("CNmControlParameterIDNode")

        .endClass();
}