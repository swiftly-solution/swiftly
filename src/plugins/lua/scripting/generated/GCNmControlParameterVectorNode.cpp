#include "../../../core/scripting/generated/classes/GCNmControlParameterVectorNode.h"
#include "../core.h"

void SetupLuaClassGCNmControlParameterVectorNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmControlParameterVectorNode>("CNmControlParameterVectorNode")

        .endClass();
}