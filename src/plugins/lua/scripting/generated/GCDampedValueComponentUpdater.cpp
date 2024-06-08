#include "../../../core/scripting/generated/classes/GCDampedValueComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCDampedValueComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDampedValueComponentUpdater>("CDampedValueComponentUpdater")
        .addProperty("Items", &GCDampedValueComponentUpdater::GetItems, &GCDampedValueComponentUpdater::SetItems)
        .endClass();
}