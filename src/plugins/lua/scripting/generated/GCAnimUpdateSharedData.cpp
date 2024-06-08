#include "../../../core/scripting/generated/classes/GCAnimUpdateSharedData.h"
#include "../core.h"

void SetupLuaClassGCAnimUpdateSharedData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimUpdateSharedData>("CAnimUpdateSharedData")
        .addProperty("Settings", &GCAnimUpdateSharedData::GetSettings, &GCAnimUpdateSharedData::SetSettings)
        .addProperty("RootNodePath", &GCAnimUpdateSharedData::GetRootNodePath, &GCAnimUpdateSharedData::SetRootNodePath)
        .endClass();
}