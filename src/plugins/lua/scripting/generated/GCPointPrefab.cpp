#include "../../../core/scripting/generated/classes/GCPointPrefab.h"
#include "../core.h"

void SetupLuaClassGCPointPrefab(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointPrefab>("CPointPrefab")
        .addProperty("TargetMapName", &GCPointPrefab::GetTargetMapName, &GCPointPrefab::SetTargetMapName)
        .addProperty("ForceWorldGroupID", &GCPointPrefab::GetForceWorldGroupID, &GCPointPrefab::SetForceWorldGroupID)
        .addProperty("AssociatedRelayTargetName", &GCPointPrefab::GetAssociatedRelayTargetName, &GCPointPrefab::SetAssociatedRelayTargetName)
        .addProperty("FixupNames", &GCPointPrefab::GetFixupNames, &GCPointPrefab::SetFixupNames)
        .addProperty("LoadDynamic", &GCPointPrefab::GetLoadDynamic, &GCPointPrefab::SetLoadDynamic)
        .addProperty("AssociatedRelayEntity", &GCPointPrefab::GetAssociatedRelayEntity, &GCPointPrefab::SetAssociatedRelayEntity)
        .endClass();
}