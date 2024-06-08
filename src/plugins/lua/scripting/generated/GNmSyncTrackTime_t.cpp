#include "../../../core/scripting/generated/classes/GNmSyncTrackTime_t.h"
#include "../core.h"

void SetupLuaClassGNmSyncTrackTime_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNmSyncTrackTime_t>("NmSyncTrackTime_t")
        .addProperty("EventIdx", &GNmSyncTrackTime_t::GetEventIdx, &GNmSyncTrackTime_t::SetEventIdx)
        .addProperty("PercentageThrough", &GNmSyncTrackTime_t::GetPercentageThrough, &GNmSyncTrackTime_t::SetPercentageThrough)
        .endClass();
}