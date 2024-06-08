#include "../../../core/scripting/generated/classes/GCNmGraphDefinition__ChildGraphSlot_t.h"
#include "../core.h"

void SetupLuaClassGCNmGraphDefinition__ChildGraphSlot_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmGraphDefinition__ChildGraphSlot_t>("CNmGraphDefinition__ChildGraphSlot_t")
        .addProperty("NodeIdx", &GCNmGraphDefinition__ChildGraphSlot_t::GetNodeIdx, &GCNmGraphDefinition__ChildGraphSlot_t::SetNodeIdx)
        .addProperty("DataSlotIdx", &GCNmGraphDefinition__ChildGraphSlot_t::GetDataSlotIdx, &GCNmGraphDefinition__ChildGraphSlot_t::SetDataSlotIdx)
        .endClass();
}