#include "../../../core/scripting/generated/classes/GC_OP_MaintainEmitter.h"
#include "../core.h"

void SetupLuaClassGC_OP_MaintainEmitter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MaintainEmitter>("C_OP_MaintainEmitter")
        .addProperty("ParticlesToMaintain", &GC_OP_MaintainEmitter::GetParticlesToMaintain, &GC_OP_MaintainEmitter::SetParticlesToMaintain)
        .addProperty("StartTime", &GC_OP_MaintainEmitter::GetStartTime, &GC_OP_MaintainEmitter::SetStartTime)
        .addProperty("EmissionDuration", &GC_OP_MaintainEmitter::GetEmissionDuration, &GC_OP_MaintainEmitter::SetEmissionDuration)
        .addProperty("EmissionRate", &GC_OP_MaintainEmitter::GetEmissionRate, &GC_OP_MaintainEmitter::SetEmissionRate)
        .addProperty("SnapshotControlPoint", &GC_OP_MaintainEmitter::GetSnapshotControlPoint, &GC_OP_MaintainEmitter::SetSnapshotControlPoint)
        .addProperty("EmitInstantaneously", &GC_OP_MaintainEmitter::GetEmitInstantaneously, &GC_OP_MaintainEmitter::SetEmitInstantaneously)
        .addProperty("FinalEmitOnStop", &GC_OP_MaintainEmitter::GetFinalEmitOnStop, &GC_OP_MaintainEmitter::SetFinalEmitOnStop)
        .addProperty("Scale", &GC_OP_MaintainEmitter::GetScale, &GC_OP_MaintainEmitter::SetScale)
        .endClass();
}