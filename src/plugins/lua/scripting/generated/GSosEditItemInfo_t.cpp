#include "../../../core/scripting/generated/classes/GSosEditItemInfo_t.h"
#include "../core.h"

void SetupLuaClassGSosEditItemInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSosEditItemInfo_t>("SosEditItemInfo_t")
        .addProperty("ItemType", &GSosEditItemInfo_t::GetItemType, &GSosEditItemInfo_t::SetItemType)
        .addProperty("ItemName", &GSosEditItemInfo_t::GetItemName, &GSosEditItemInfo_t::SetItemName)
        .addProperty("ItemTypeName", &GSosEditItemInfo_t::GetItemTypeName, &GSosEditItemInfo_t::SetItemTypeName)
        .addProperty("ItemKVString", &GSosEditItemInfo_t::GetItemKVString, &GSosEditItemInfo_t::SetItemKVString)
        .addProperty("ItemPos", &GSosEditItemInfo_t::GetItemPos, &GSosEditItemInfo_t::SetItemPos)
        .endClass();
}