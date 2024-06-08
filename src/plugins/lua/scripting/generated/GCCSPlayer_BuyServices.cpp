#include "../../../core/scripting/generated/classes/GCCSPlayer_BuyServices.h"
#include "../core.h"

void SetupLuaClassGCCSPlayer_BuyServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayer_BuyServices>("CCSPlayer_BuyServices")
        .addProperty("SellbackPurchaseEntries", &GCCSPlayer_BuyServices::GetSellbackPurchaseEntries, &GCCSPlayer_BuyServices::SetSellbackPurchaseEntries)
        .endClass();
}