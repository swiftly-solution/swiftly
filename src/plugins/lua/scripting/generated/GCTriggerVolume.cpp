#include "../../../core/scripting/generated/classes/GCTriggerVolume.h"
#include "../core.h"

void SetupLuaClassGCTriggerVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerVolume>("CTriggerVolume")
        .addProperty("FilterName", &GCTriggerVolume::GetFilterName, &GCTriggerVolume::SetFilterName)
        .addProperty("Filter", &GCTriggerVolume::GetFilter, &GCTriggerVolume::SetFilter)
        .endClass();
}