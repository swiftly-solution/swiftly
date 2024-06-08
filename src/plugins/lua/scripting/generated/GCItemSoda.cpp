#include "../../../core/scripting/generated/classes/GCItemSoda.h"
#include "../core.h"

void SetupLuaClassGCItemSoda(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemSoda>("CItemSoda")

        .endClass();
}