#include "../../../core/scripting/generated/classes/GCBuyZone.h"
#include "../core.h"

void SetupLuaClassGCBuyZone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBuyZone>("CBuyZone")
        .addProperty("LegacyTeamNum", &GCBuyZone::GetLegacyTeamNum, &GCBuyZone::SetLegacyTeamNum)
        .endClass();
}