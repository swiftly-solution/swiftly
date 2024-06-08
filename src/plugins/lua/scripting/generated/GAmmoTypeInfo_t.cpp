#include "../../../core/scripting/generated/classes/GAmmoTypeInfo_t.h"
#include "../core.h"

void SetupLuaClassGAmmoTypeInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAmmoTypeInfo_t>("AmmoTypeInfo_t")
        .addProperty("MaxCarry", &GAmmoTypeInfo_t::GetMaxCarry, &GAmmoTypeInfo_t::SetMaxCarry)
        .addProperty("SplashSize", &GAmmoTypeInfo_t::GetSplashSize, &GAmmoTypeInfo_t::SetSplashSize)
        .addProperty("Flags", &GAmmoTypeInfo_t::GetFlags, &GAmmoTypeInfo_t::SetFlags)
        .addProperty("Mass", &GAmmoTypeInfo_t::GetMass, &GAmmoTypeInfo_t::SetMass)
        .addProperty("Speed", &GAmmoTypeInfo_t::GetSpeed, &GAmmoTypeInfo_t::SetSpeed)
        .endClass();
}