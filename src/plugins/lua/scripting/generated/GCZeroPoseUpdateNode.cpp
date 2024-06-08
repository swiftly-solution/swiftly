#include "../../../core/scripting/generated/classes/GCZeroPoseUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCZeroPoseUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCZeroPoseUpdateNode>("CZeroPoseUpdateNode")

        .endClass();
}