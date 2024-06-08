#include "../../../core/scripting/generated/classes/GCAnimGraphNetworkSettings.h"
#include "../core.h"

void SetupLuaClassGCAnimGraphNetworkSettings(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphNetworkSettings>("CAnimGraphNetworkSettings")
        .addProperty("NetworkingEnabled", &GCAnimGraphNetworkSettings::GetNetworkingEnabled, &GCAnimGraphNetworkSettings::SetNetworkingEnabled)
        .endClass();
}