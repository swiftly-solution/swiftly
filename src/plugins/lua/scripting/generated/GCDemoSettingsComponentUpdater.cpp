#include "../../../core/scripting/generated/classes/GCDemoSettingsComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCDemoSettingsComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDemoSettingsComponentUpdater>("CDemoSettingsComponentUpdater")
        .addProperty("Settings", &GCDemoSettingsComponentUpdater::GetSettings, &GCDemoSettingsComponentUpdater::SetSettings)
        .endClass();
}