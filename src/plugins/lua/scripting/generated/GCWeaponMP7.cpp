#include "../../../core/scripting/generated/classes/GCWeaponMP7.h"
#include "../core.h"

void SetupLuaClassGCWeaponMP7(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponMP7>("CWeaponMP7")

        .endClass();
}