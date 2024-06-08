#include "../../../core/scripting/generated/classes/GCEconItemView.h"
#include "../core.h"

void SetupLuaClassGCEconItemView(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEconItemView>("CEconItemView")
        .addProperty("ItemDefinitionIndex", &GCEconItemView::GetItemDefinitionIndex, &GCEconItemView::SetItemDefinitionIndex)
        .addProperty("EntityQuality", &GCEconItemView::GetEntityQuality, &GCEconItemView::SetEntityQuality)
        .addProperty("EntityLevel", &GCEconItemView::GetEntityLevel, &GCEconItemView::SetEntityLevel)
        .addProperty("ItemID", &GCEconItemView::GetItemID, &GCEconItemView::SetItemID)
        .addProperty("ItemIDHigh", &GCEconItemView::GetItemIDHigh, &GCEconItemView::SetItemIDHigh)
        .addProperty("ItemIDLow", &GCEconItemView::GetItemIDLow, &GCEconItemView::SetItemIDLow)
        .addProperty("AccountID", &GCEconItemView::GetAccountID, &GCEconItemView::SetAccountID)
        .addProperty("InventoryPosition", &GCEconItemView::GetInventoryPosition, &GCEconItemView::SetInventoryPosition)
        .addProperty("Initialized", &GCEconItemView::GetInitialized, &GCEconItemView::SetInitialized)
        .addProperty("AttributeList", &GCEconItemView::GetAttributeList, &GCEconItemView::SetAttributeList)
        .addProperty("NetworkedDynamicAttributes", &GCEconItemView::GetNetworkedDynamicAttributes, &GCEconItemView::SetNetworkedDynamicAttributes)
        .addProperty("CustomName", &GCEconItemView::GetCustomName, &GCEconItemView::SetCustomName)
        .addProperty("CustomNameOverride", &GCEconItemView::GetCustomNameOverride, &GCEconItemView::SetCustomNameOverride)
        .endClass();
}