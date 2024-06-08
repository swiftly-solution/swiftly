#include "../../../core/scripting/generated/classes/GCWeaponMP9.h"
#include "../core.h"

void SetupLuaClassGCWeaponMP9(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponMP9>("CWeaponMP9")

        .endClass();
}