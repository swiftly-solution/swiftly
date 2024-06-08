#include "../../../core/scripting/generated/classes/GCNmSyncTrack.h"
#include "../core.h"

void SetupLuaClassGCNmSyncTrack(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmSyncTrack>("CNmSyncTrack")
        .addProperty("StartEventOffset", &GCNmSyncTrack::GetStartEventOffset, &GCNmSyncTrack::SetStartEventOffset)
        .endClass();
}