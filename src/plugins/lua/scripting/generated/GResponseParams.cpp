#include "../../../core/scripting/generated/classes/GResponseParams.h"
#include "../core.h"

void SetupLuaClassGResponseParams(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GResponseParams>("ResponseParams")
        .addProperty("Odds", &GResponseParams::GetOdds, &GResponseParams::SetOdds)
        .addProperty("Flags", &GResponseParams::GetFlags, &GResponseParams::SetFlags)
        .addProperty("Followup", &GResponseParams::GetFollowup, &GResponseParams::SetFollowup)
        .endClass();
}