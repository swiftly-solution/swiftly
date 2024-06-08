#include "../../../core/scripting/generated/classes/GCBtNode.h"
#include "../core.h"

void SetupLuaClassGCBtNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtNode>("CBtNode")

        .endClass();
}