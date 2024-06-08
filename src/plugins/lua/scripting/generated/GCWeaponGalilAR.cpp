#include "../../../core/scripting/generated/classes/GCWeaponGalilAR.h"
#include "../core.h"

void SetupLuaClassGCWeaponGalilAR(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponGalilAR>("CWeaponGalilAR")

        .endClass();
}