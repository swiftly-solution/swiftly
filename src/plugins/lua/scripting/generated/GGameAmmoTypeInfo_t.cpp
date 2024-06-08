#include "../../../core/scripting/generated/classes/GGameAmmoTypeInfo_t.h"
#include "../core.h"

void SetupLuaClassGGameAmmoTypeInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GGameAmmoTypeInfo_t>("GameAmmoTypeInfo_t")
        .addProperty("BuySize", &GGameAmmoTypeInfo_t::GetBuySize, &GGameAmmoTypeInfo_t::SetBuySize)
        .addProperty("Cost", &GGameAmmoTypeInfo_t::GetCost, &GGameAmmoTypeInfo_t::SetCost)
        .endClass();
}