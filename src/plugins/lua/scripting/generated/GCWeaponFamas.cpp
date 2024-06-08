#include "../../../core/scripting/generated/classes/GCWeaponFamas.h"
#include "../core.h"

void SetupLuaClassGCWeaponFamas(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponFamas>("CWeaponFamas")

        .endClass();
}