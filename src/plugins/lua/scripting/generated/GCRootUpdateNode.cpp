#include "../../../core/scripting/generated/classes/GCRootUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCRootUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRootUpdateNode>("CRootUpdateNode")

        .endClass();
}