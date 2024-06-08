#include "../../../core/scripting/generated/classes/GCWeaponP250.h"
#include "../core.h"

void SetupLuaClassGCWeaponP250(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponP250>("CWeaponP250")

        .endClass();
}