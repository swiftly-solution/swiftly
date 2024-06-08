#include "../../../core/scripting/generated/classes/GCHEGrenadeProjectile.h"
#include "../core.h"

void SetupLuaClassGCHEGrenadeProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHEGrenadeProjectile>("CHEGrenadeProjectile")

        .endClass();
}