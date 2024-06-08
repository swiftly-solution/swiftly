#include "../../../core/scripting/generated/classes/GCChoreoUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCChoreoUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCChoreoUpdateNode>("CChoreoUpdateNode")

        .endClass();
}