#include "../../../core/scripting/generated/classes/GCTripWireFireProjectile.h"
#include "../core.h"

void SetupLuaClassGCTripWireFireProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTripWireFireProjectile>("CTripWireFireProjectile")

        .endClass();
}