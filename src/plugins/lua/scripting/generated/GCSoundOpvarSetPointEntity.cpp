#include "../../../core/scripting/generated/classes/GCSoundOpvarSetPointEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundOpvarSetPointEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetPointEntity>("CSoundOpvarSetPointEntity")
        .addProperty("OnEnter", &GCSoundOpvarSetPointEntity::GetOnEnter, &GCSoundOpvarSetPointEntity::SetOnEnter)
        .addProperty("OnExit", &GCSoundOpvarSetPointEntity::GetOnExit, &GCSoundOpvarSetPointEntity::SetOnExit)
        .addProperty("AutoDisable", &GCSoundOpvarSetPointEntity::GetAutoDisable, &GCSoundOpvarSetPointEntity::SetAutoDisable)
        .addProperty("DistanceMin", &GCSoundOpvarSetPointEntity::GetDistanceMin, &GCSoundOpvarSetPointEntity::SetDistanceMin)
        .addProperty("DistanceMax", &GCSoundOpvarSetPointEntity::GetDistanceMax, &GCSoundOpvarSetPointEntity::SetDistanceMax)
        .addProperty("DistanceMapMin", &GCSoundOpvarSetPointEntity::GetDistanceMapMin, &GCSoundOpvarSetPointEntity::SetDistanceMapMin)
        .addProperty("DistanceMapMax", &GCSoundOpvarSetPointEntity::GetDistanceMapMax, &GCSoundOpvarSetPointEntity::SetDistanceMapMax)
        .addProperty("OcclusionRadius", &GCSoundOpvarSetPointEntity::GetOcclusionRadius, &GCSoundOpvarSetPointEntity::SetOcclusionRadius)
        .addProperty("OcclusionMin", &GCSoundOpvarSetPointEntity::GetOcclusionMin, &GCSoundOpvarSetPointEntity::SetOcclusionMin)
        .addProperty("OcclusionMax", &GCSoundOpvarSetPointEntity::GetOcclusionMax, &GCSoundOpvarSetPointEntity::SetOcclusionMax)
        .addProperty("ValSetOnDisable", &GCSoundOpvarSetPointEntity::GetValSetOnDisable, &GCSoundOpvarSetPointEntity::SetValSetOnDisable)
        .addProperty("SetValueOnDisable", &GCSoundOpvarSetPointEntity::GetSetValueOnDisable, &GCSoundOpvarSetPointEntity::SetSetValueOnDisable)
        .addProperty("SimulationMode", &GCSoundOpvarSetPointEntity::GetSimulationMode, &GCSoundOpvarSetPointEntity::SetSimulationMode)
        .addProperty("VisibilitySamples", &GCSoundOpvarSetPointEntity::GetVisibilitySamples, &GCSoundOpvarSetPointEntity::SetVisibilitySamples)
        .addProperty("DynamicProxyPoint", &GCSoundOpvarSetPointEntity::GetDynamicProxyPoint, &GCSoundOpvarSetPointEntity::SetDynamicProxyPoint)
        .addProperty("DynamicMaximumOcclusion", &GCSoundOpvarSetPointEntity::GetDynamicMaximumOcclusion, &GCSoundOpvarSetPointEntity::SetDynamicMaximumOcclusion)
        .addProperty("DynamicEntity", &GCSoundOpvarSetPointEntity::GetDynamicEntity, &GCSoundOpvarSetPointEntity::SetDynamicEntity)
        .addProperty("DynamicEntityName", &GCSoundOpvarSetPointEntity::GetDynamicEntityName, &GCSoundOpvarSetPointEntity::SetDynamicEntityName)
        .addProperty("PathingDistanceNormFactor", &GCSoundOpvarSetPointEntity::GetPathingDistanceNormFactor, &GCSoundOpvarSetPointEntity::SetPathingDistanceNormFactor)
        .addProperty("PathingSourcePos", &GCSoundOpvarSetPointEntity::GetPathingSourcePos, &GCSoundOpvarSetPointEntity::SetPathingSourcePos)
        .addProperty("PathingListenerPos", &GCSoundOpvarSetPointEntity::GetPathingListenerPos, &GCSoundOpvarSetPointEntity::SetPathingListenerPos)
        .addProperty("PathingDirection", &GCSoundOpvarSetPointEntity::GetPathingDirection, &GCSoundOpvarSetPointEntity::SetPathingDirection)
        .addProperty("PathingSourceIndex", &GCSoundOpvarSetPointEntity::GetPathingSourceIndex, &GCSoundOpvarSetPointEntity::SetPathingSourceIndex)
        .endClass();
}