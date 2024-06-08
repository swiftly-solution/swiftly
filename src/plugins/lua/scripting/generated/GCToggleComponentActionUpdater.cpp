#include "../../../core/scripting/generated/classes/GCToggleComponentActionUpdater.h"
#include "../core.h"

void SetupLuaClassGCToggleComponentActionUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCToggleComponentActionUpdater>("CToggleComponentActionUpdater")
        .addProperty("ComponentID", &GCToggleComponentActionUpdater::GetComponentID, &GCToggleComponentActionUpdater::SetComponentID)
        .addProperty("SetEnabled", &GCToggleComponentActionUpdater::GetSetEnabled, &GCToggleComponentActionUpdater::SetSetEnabled)
        .endClass();
}