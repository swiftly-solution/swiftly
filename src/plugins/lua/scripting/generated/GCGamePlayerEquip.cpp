#include "../../../core/scripting/generated/classes/GCGamePlayerEquip.h"
#include "../core.h"

void SetupLuaClassGCGamePlayerEquip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGamePlayerEquip>("CGamePlayerEquip")

        .endClass();
}