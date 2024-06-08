#include "../../../core/scripting/generated/classes/GAggregateMeshInfo_t.h"
#include "../core.h"

void SetupLuaClassGAggregateMeshInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAggregateMeshInfo_t>("AggregateMeshInfo_t")
        .addProperty("VisClusterMemberOffset", &GAggregateMeshInfo_t::GetVisClusterMemberOffset, &GAggregateMeshInfo_t::SetVisClusterMemberOffset)
        .addProperty("VisClusterMemberCount", &GAggregateMeshInfo_t::GetVisClusterMemberCount, &GAggregateMeshInfo_t::SetVisClusterMemberCount)
        .addProperty("HasTransform", &GAggregateMeshInfo_t::GetHasTransform, &GAggregateMeshInfo_t::SetHasTransform)
        .addProperty("DrawCallIndex", &GAggregateMeshInfo_t::GetDrawCallIndex, &GAggregateMeshInfo_t::SetDrawCallIndex)
        .addProperty("LODSetupIndex", &GAggregateMeshInfo_t::GetLODSetupIndex, &GAggregateMeshInfo_t::SetLODSetupIndex)
        .addProperty("LODGroupMask", &GAggregateMeshInfo_t::GetLODGroupMask, &GAggregateMeshInfo_t::SetLODGroupMask)
        .addProperty("TintColor", &GAggregateMeshInfo_t::GetTintColor, &GAggregateMeshInfo_t::SetTintColor)
        .addProperty("ObjectFlags", &GAggregateMeshInfo_t::GetObjectFlags, &GAggregateMeshInfo_t::SetObjectFlags)
        .addProperty("LightProbeVolumePrecomputedHandshake", &GAggregateMeshInfo_t::GetLightProbeVolumePrecomputedHandshake, &GAggregateMeshInfo_t::SetLightProbeVolumePrecomputedHandshake)
        .endClass();
}