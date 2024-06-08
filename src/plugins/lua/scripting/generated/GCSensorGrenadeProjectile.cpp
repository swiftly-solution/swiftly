#include "../../../core/scripting/generated/classes/GCSensorGrenadeProjectile.h"
#include "../core.h"

void SetupLuaClassGCSensorGrenadeProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSensorGrenadeProjectile>("CSensorGrenadeProjectile")
        .addProperty("DisplayGrenade", &GCSensorGrenadeProjectile::GetDisplayGrenade, &GCSensorGrenadeProjectile::SetDisplayGrenade)
        .endClass();
}