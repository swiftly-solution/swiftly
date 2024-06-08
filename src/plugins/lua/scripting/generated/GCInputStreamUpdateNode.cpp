#include "../../../core/scripting/generated/classes/GCInputStreamUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCInputStreamUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInputStreamUpdateNode>("CInputStreamUpdateNode")

        .endClass();
}