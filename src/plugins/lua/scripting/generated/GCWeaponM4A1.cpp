#include "../../../core/scripting/generated/classes/GCWeaponM4A1.h"
#include "../core.h"

void SetupLuaClassGCWeaponM4A1(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponM4A1>("CWeaponM4A1")

        .endClass();
}