#include "../../../core/scripting/generated/classes/GCHostageRescueZoneShim.h"
#include "../core.h"

void SetupLuaClassGCHostageRescueZoneShim(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostageRescueZoneShim>("CHostageRescueZoneShim")

        .endClass();
}