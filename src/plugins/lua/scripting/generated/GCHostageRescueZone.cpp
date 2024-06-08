#include "../../../core/scripting/generated/classes/GCHostageRescueZone.h"
#include "../core.h"

void SetupLuaClassGCHostageRescueZone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostageRescueZone>("CHostageRescueZone")

        .endClass();
}