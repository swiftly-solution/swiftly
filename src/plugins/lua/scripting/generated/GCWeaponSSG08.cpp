#include "../../../core/scripting/generated/classes/GCWeaponSSG08.h"
#include "../core.h"

void SetupLuaClassGCWeaponSSG08(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponSSG08>("CWeaponSSG08")

        .endClass();
}