#include "../../../core/scripting/generated/classes/GCWeaponBaseItem.h"
#include "../core.h"

void SetupLuaClassGCWeaponBaseItem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponBaseItem>("CWeaponBaseItem")
        .addProperty("SequenceCompleteTimer", &GCWeaponBaseItem::GetSequenceCompleteTimer, &GCWeaponBaseItem::SetSequenceCompleteTimer)
        .addProperty("Redraw", &GCWeaponBaseItem::GetRedraw, &GCWeaponBaseItem::SetRedraw)
        .endClass();
}