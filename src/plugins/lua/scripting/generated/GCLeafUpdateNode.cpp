#include "../../../core/scripting/generated/classes/GCLeafUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCLeafUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLeafUpdateNode>("CLeafUpdateNode")

        .endClass();
}