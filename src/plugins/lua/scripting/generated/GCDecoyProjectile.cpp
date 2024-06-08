#include "../../../core/scripting/generated/classes/GCDecoyProjectile.h"
#include "../core.h"

void SetupLuaClassGCDecoyProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDecoyProjectile>("CDecoyProjectile")
        .addProperty("DecoyShotTick", &GCDecoyProjectile::GetDecoyShotTick, &GCDecoyProjectile::SetDecoyShotTick)
        .addProperty("ShotsRemaining", &GCDecoyProjectile::GetShotsRemaining, &GCDecoyProjectile::SetShotsRemaining)
        .addProperty("DecoyWeaponDefIndex", &GCDecoyProjectile::GetDecoyWeaponDefIndex, &GCDecoyProjectile::SetDecoyWeaponDefIndex)
        .endClass();
}