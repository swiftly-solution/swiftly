#include "../../../core/scripting/generated/classes/GC_OP_NoiseEmitter.h"
#include "../core.h"

void SetupLuaClassGC_OP_NoiseEmitter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_NoiseEmitter>("C_OP_NoiseEmitter")
        .addProperty("EmissionDuration", &GC_OP_NoiseEmitter::GetEmissionDuration, &GC_OP_NoiseEmitter::SetEmissionDuration)
        .addProperty("StartTime", &GC_OP_NoiseEmitter::GetStartTime, &GC_OP_NoiseEmitter::SetStartTime)
        .addProperty("EmissionScale", &GC_OP_NoiseEmitter::GetEmissionScale, &GC_OP_NoiseEmitter::SetEmissionScale)
        .addProperty("ScaleControlPoint", &GC_OP_NoiseEmitter::GetScaleControlPoint, &GC_OP_NoiseEmitter::SetScaleControlPoint)
        .addProperty("ScaleControlPointField", &GC_OP_NoiseEmitter::GetScaleControlPointField, &GC_OP_NoiseEmitter::SetScaleControlPointField)
        .addProperty("WorldNoisePoint", &GC_OP_NoiseEmitter::GetWorldNoisePoint, &GC_OP_NoiseEmitter::SetWorldNoisePoint)
        .addProperty("AbsVal", &GC_OP_NoiseEmitter::GetAbsVal, &GC_OP_NoiseEmitter::SetAbsVal)
        .addProperty("AbsValInv", &GC_OP_NoiseEmitter::GetAbsValInv, &GC_OP_NoiseEmitter::SetAbsValInv)
        .addProperty("Offset", &GC_OP_NoiseEmitter::GetOffset, &GC_OP_NoiseEmitter::SetOffset)
        .addProperty("OutputMin", &GC_OP_NoiseEmitter::GetOutputMin, &GC_OP_NoiseEmitter::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_NoiseEmitter::GetOutputMax, &GC_OP_NoiseEmitter::SetOutputMax)
        .addProperty("NoiseScale", &GC_OP_NoiseEmitter::GetNoiseScale, &GC_OP_NoiseEmitter::SetNoiseScale)
        .addProperty("WorldNoiseScale", &GC_OP_NoiseEmitter::GetWorldNoiseScale, &GC_OP_NoiseEmitter::SetWorldNoiseScale)
        .addProperty("OffsetLoc", &GC_OP_NoiseEmitter::GetOffsetLoc, &GC_OP_NoiseEmitter::SetOffsetLoc)
        .addProperty("WorldTimeScale", &GC_OP_NoiseEmitter::GetWorldTimeScale, &GC_OP_NoiseEmitter::SetWorldTimeScale)
        .endClass();
}