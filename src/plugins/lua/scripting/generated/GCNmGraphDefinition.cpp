#include "../../../core/scripting/generated/classes/GCNmGraphDefinition.h"
#include "../core.h"

void SetupLuaClassGCNmGraphDefinition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmGraphDefinition>("CNmGraphDefinition")
        .addProperty("PersistentNodeIndices", &GCNmGraphDefinition::GetPersistentNodeIndices, &GCNmGraphDefinition::SetPersistentNodeIndices)
        .addProperty("RootNodeIdx", &GCNmGraphDefinition::GetRootNodeIdx, &GCNmGraphDefinition::SetRootNodeIdx)
        .addProperty("VirtualParameterNodeIndices", &GCNmGraphDefinition::GetVirtualParameterNodeIndices, &GCNmGraphDefinition::SetVirtualParameterNodeIndices)
        .addProperty("ChildGraphSlots", &GCNmGraphDefinition::GetChildGraphSlots, &GCNmGraphDefinition::SetChildGraphSlots)
        .addProperty("ExternalGraphSlots", &GCNmGraphDefinition::GetExternalGraphSlots, &GCNmGraphDefinition::SetExternalGraphSlots)
        .endClass();
}