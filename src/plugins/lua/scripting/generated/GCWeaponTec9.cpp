#include "../../../core/scripting/generated/classes/GCWeaponTec9.h"
#include "../core.h"

void SetupLuaClassGCWeaponTec9(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponTec9>("CWeaponTec9")

        .endClass();
}