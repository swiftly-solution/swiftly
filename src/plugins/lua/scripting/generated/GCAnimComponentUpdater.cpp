#include "../../../core/scripting/generated/classes/GCAnimComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCAnimComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimComponentUpdater>("CAnimComponentUpdater")
        .addProperty("Name", &GCAnimComponentUpdater::GetName, &GCAnimComponentUpdater::SetName)
        .addProperty("Id", &GCAnimComponentUpdater::GetId, &GCAnimComponentUpdater::SetId)
        .addProperty("NetworkMode", &GCAnimComponentUpdater::GetNetworkMode, &GCAnimComponentUpdater::SetNetworkMode)
        .addProperty("StartEnabled", &GCAnimComponentUpdater::GetStartEnabled, &GCAnimComponentUpdater::SetStartEnabled)
        .endClass();
}