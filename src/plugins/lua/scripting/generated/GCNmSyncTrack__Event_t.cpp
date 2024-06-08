#include "../../../core/scripting/generated/classes/GCNmSyncTrack__Event_t.h"
#include "../core.h"

void SetupLuaClassGCNmSyncTrack__Event_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmSyncTrack__Event_t>("CNmSyncTrack__Event_t")
        .addProperty("StartTime", &GCNmSyncTrack__Event_t::GetStartTime, &GCNmSyncTrack__Event_t::SetStartTime)
        .addProperty("Duration", &GCNmSyncTrack__Event_t::GetDuration, &GCNmSyncTrack__Event_t::SetDuration)
        .endClass();
}