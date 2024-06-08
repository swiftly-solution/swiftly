#include "../../../core/scripting/generated/classes/GCWeaponFiveSeven.h"
#include "../core.h"

void SetupLuaClassGCWeaponFiveSeven(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponFiveSeven>("CWeaponFiveSeven")

        .endClass();
}