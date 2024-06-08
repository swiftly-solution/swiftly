#include "../../../core/scripting/generated/classes/GNmSyncTrackTimeRange_t.h"
#include "../core.h"

void SetupLuaClassGNmSyncTrackTimeRange_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNmSyncTrackTimeRange_t>("NmSyncTrackTimeRange_t")
        .addProperty("StartTime", &GNmSyncTrackTimeRange_t::GetStartTime, &GNmSyncTrackTimeRange_t::SetStartTime)
        .addProperty("EndTime", &GNmSyncTrackTimeRange_t::GetEndTime, &GNmSyncTrackTimeRange_t::SetEndTime)
        .endClass();
}