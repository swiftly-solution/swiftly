#include "../../../core/scripting/generated/classes/GCWeaponM249.h"
#include "../core.h"

void SetupLuaClassGCWeaponM249(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponM249>("CWeaponM249")

        .endClass();
}