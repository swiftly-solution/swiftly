#include "../../../core/scripting/generated/classes/GCNmSyncTrack__EventMarker_t.h"
#include "../core.h"

void SetupLuaClassGCNmSyncTrack__EventMarker_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmSyncTrack__EventMarker_t>("CNmSyncTrack__EventMarker_t")
        .addProperty("StartTime", &GCNmSyncTrack__EventMarker_t::GetStartTime, &GCNmSyncTrack__EventMarker_t::SetStartTime)
        .endClass();
}