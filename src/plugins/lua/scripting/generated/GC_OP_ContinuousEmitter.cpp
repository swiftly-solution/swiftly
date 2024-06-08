#include "../../../core/scripting/generated/classes/GC_OP_ContinuousEmitter.h"
#include "../core.h"

void SetupLuaClassGC_OP_ContinuousEmitter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ContinuousEmitter>("C_OP_ContinuousEmitter")
        .addProperty("EmissionDuration", &GC_OP_ContinuousEmitter::GetEmissionDuration, &GC_OP_ContinuousEmitter::SetEmissionDuration)
        .addProperty("StartTime", &GC_OP_ContinuousEmitter::GetStartTime, &GC_OP_ContinuousEmitter::SetStartTime)
        .addProperty("EmitRate", &GC_OP_ContinuousEmitter::GetEmitRate, &GC_OP_ContinuousEmitter::SetEmitRate)
        .addProperty("EmissionScale", &GC_OP_ContinuousEmitter::GetEmissionScale, &GC_OP_ContinuousEmitter::SetEmissionScale)
        .addProperty("ScalePerParentParticle", &GC_OP_ContinuousEmitter::GetScalePerParentParticle, &GC_OP_ContinuousEmitter::SetScalePerParentParticle)
        .addProperty("InitFromKilledParentParticles", &GC_OP_ContinuousEmitter::GetInitFromKilledParentParticles, &GC_OP_ContinuousEmitter::SetInitFromKilledParentParticles)
        .addProperty("EventType", &GC_OP_ContinuousEmitter::GetEventType, &GC_OP_ContinuousEmitter::SetEventType)
        .addProperty("SnapshotControlPoint", &GC_OP_ContinuousEmitter::GetSnapshotControlPoint, &GC_OP_ContinuousEmitter::SetSnapshotControlPoint)
        .addProperty("LimitPerUpdate", &GC_OP_ContinuousEmitter::GetLimitPerUpdate, &GC_OP_ContinuousEmitter::SetLimitPerUpdate)
        .addProperty("ForceEmitOnFirstUpdate", &GC_OP_ContinuousEmitter::GetForceEmitOnFirstUpdate, &GC_OP_ContinuousEmitter::SetForceEmitOnFirstUpdate)
        .addProperty("ForceEmitOnLastUpdate", &GC_OP_ContinuousEmitter::GetForceEmitOnLastUpdate, &GC_OP_ContinuousEmitter::SetForceEmitOnLastUpdate)
        .endClass();
}