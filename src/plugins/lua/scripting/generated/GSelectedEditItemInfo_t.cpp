#include "../../../core/scripting/generated/classes/GSelectedEditItemInfo_t.h"
#include "../core.h"

void SetupLuaClassGSelectedEditItemInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSelectedEditItemInfo_t>("SelectedEditItemInfo_t")
        .addProperty("EditItems", &GSelectedEditItemInfo_t::GetEditItems, &GSelectedEditItemInfo_t::SetEditItems)
        .endClass();
}