#include "../../../core/scripting/generated/classes/GCWeaponShield.h"
#include "../core.h"

void SetupLuaClassGCWeaponShield(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponShield>("CWeaponShield")
        .addProperty("BulletDamageAbsorbed", &GCWeaponShield::GetBulletDamageAbsorbed, &GCWeaponShield::SetBulletDamageAbsorbed)
        .addProperty("DisplayHealth", &GCWeaponShield::GetDisplayHealth, &GCWeaponShield::SetDisplayHealth)
        .endClass();
}