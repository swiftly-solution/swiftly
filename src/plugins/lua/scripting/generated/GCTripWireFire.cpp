#include "../../../core/scripting/generated/classes/GCTripWireFire.h"
#include "../core.h"

void SetupLuaClassGCTripWireFire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTripWireFire>("CTripWireFire")

        .endClass();
}