#include "../../../core/scripting/generated/classes/GCReplicationParameters.h"
#include "../core.h"

void SetupLuaClassGCReplicationParameters(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCReplicationParameters>("CReplicationParameters")
        .addProperty("ReplicationMode", &GCReplicationParameters::GetReplicationMode, &GCReplicationParameters::SetReplicationMode)
        .addProperty("ScaleChildParticleRadii", &GCReplicationParameters::GetScaleChildParticleRadii, &GCReplicationParameters::SetScaleChildParticleRadii)
        .addProperty("MinRandomRadiusScale", &GCReplicationParameters::GetMinRandomRadiusScale, &GCReplicationParameters::SetMinRandomRadiusScale)
        .addProperty("MaxRandomRadiusScale", &GCReplicationParameters::GetMaxRandomRadiusScale, &GCReplicationParameters::SetMaxRandomRadiusScale)
        .addProperty("ModellingScale", &GCReplicationParameters::GetModellingScale, &GCReplicationParameters::SetModellingScale)
        .endClass();
}