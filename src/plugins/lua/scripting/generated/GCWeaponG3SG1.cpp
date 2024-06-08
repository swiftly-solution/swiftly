#include "../../../core/scripting/generated/classes/GCWeaponG3SG1.h"
#include "../core.h"

void SetupLuaClassGCWeaponG3SG1(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponG3SG1>("CWeaponG3SG1")

        .endClass();
}