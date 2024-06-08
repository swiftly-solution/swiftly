#include "../../../core/scripting/generated/classes/GCItemHeavyAssaultSuit.h"
#include "../core.h"

void SetupLuaClassGCItemHeavyAssaultSuit(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemHeavyAssaultSuit>("CItemHeavyAssaultSuit")

        .endClass();
}