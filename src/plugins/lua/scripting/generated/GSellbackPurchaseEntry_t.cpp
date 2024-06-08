#include "../../../core/scripting/generated/classes/GSellbackPurchaseEntry_t.h"
#include "../core.h"

void SetupLuaClassGSellbackPurchaseEntry_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSellbackPurchaseEntry_t>("SellbackPurchaseEntry_t")
        .addProperty("DefIdx", &GSellbackPurchaseEntry_t::GetDefIdx, &GSellbackPurchaseEntry_t::SetDefIdx)
        .addProperty("Cost", &GSellbackPurchaseEntry_t::GetCost, &GSellbackPurchaseEntry_t::SetCost)
        .addProperty("PrevArmor", &GSellbackPurchaseEntry_t::GetPrevArmor, &GSellbackPurchaseEntry_t::SetPrevArmor)
        .addProperty("PrevHelmet", &GSellbackPurchaseEntry_t::GetPrevHelmet, &GSellbackPurchaseEntry_t::SetPrevHelmet)
        .addProperty("Item", &GSellbackPurchaseEntry_t::GetItem, &GSellbackPurchaseEntry_t::SetItem)
        .endClass();
}