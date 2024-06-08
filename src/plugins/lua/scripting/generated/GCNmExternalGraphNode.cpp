#include "../../../core/scripting/generated/classes/GCNmExternalGraphNode.h"
#include "../core.h"

void SetupLuaClassGCNmExternalGraphNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmExternalGraphNode>("CNmExternalGraphNode")

        .endClass();
}