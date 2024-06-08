#include "../../../core/scripting/generated/classes/GCPushable.h"
#include "../core.h"

void SetupLuaClassGCPushable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPushable>("CPushable")

        .endClass();
}