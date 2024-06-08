#include "../../../core/scripting/generated/classes/GC_OP_InstantaneousEmitter.h"
#include "../core.h"

void SetupLuaClassGC_OP_InstantaneousEmitter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_InstantaneousEmitter>("C_OP_InstantaneousEmitter")
        .addProperty("ParticlesToEmit", &GC_OP_InstantaneousEmitter::GetParticlesToEmit, &GC_OP_InstantaneousEmitter::SetParticlesToEmit)
        .addProperty("StartTime", &GC_OP_InstantaneousEmitter::GetStartTime, &GC_OP_InstantaneousEmitter::SetStartTime)
        .addProperty("InitFromKilledParentParticles", &GC_OP_InstantaneousEmitter::GetInitFromKilledParentParticles, &GC_OP_InstantaneousEmitter::SetInitFromKilledParentParticles)
        .addProperty("EventType", &GC_OP_InstantaneousEmitter::GetEventType, &GC_OP_InstantaneousEmitter::SetEventType)
        .addProperty("ParentParticleScale", &GC_OP_InstantaneousEmitter::GetParentParticleScale, &GC_OP_InstantaneousEmitter::SetParentParticleScale)
        .addProperty("MaxEmittedPerFrame", &GC_OP_InstantaneousEmitter::GetMaxEmittedPerFrame, &GC_OP_InstantaneousEmitter::SetMaxEmittedPerFrame)
        .addProperty("SnapshotControlPoint", &GC_OP_InstantaneousEmitter::GetSnapshotControlPoint, &GC_OP_InstantaneousEmitter::SetSnapshotControlPoint)
        .endClass();
}