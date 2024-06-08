#include "../../../core/scripting/generated/classes/GCItemAssaultSuit.h"
#include "../core.h"

void SetupLuaClassGCItemAssaultSuit(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemAssaultSuit>("CItemAssaultSuit")

        .endClass();
}