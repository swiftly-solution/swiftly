#include "../../../core/scripting/generated/classes/GC_OP_ChladniWave.h"
#include "../core.h"

void SetupLuaClassGC_OP_ChladniWave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ChladniWave>("C_OP_ChladniWave")
        .addProperty("FieldOutput", &GC_OP_ChladniWave::GetFieldOutput, &GC_OP_ChladniWave::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_ChladniWave::GetInputMin, &GC_OP_ChladniWave::SetInputMin)
        .addProperty("InputMax", &GC_OP_ChladniWave::GetInputMax, &GC_OP_ChladniWave::SetInputMax)
        .addProperty("OutputMin", &GC_OP_ChladniWave::GetOutputMin, &GC_OP_ChladniWave::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_ChladniWave::GetOutputMax, &GC_OP_ChladniWave::SetOutputMax)
        .addProperty("WaveLength", &GC_OP_ChladniWave::GetWaveLength, &GC_OP_ChladniWave::SetWaveLength)
        .addProperty("Harmonics", &GC_OP_ChladniWave::GetHarmonics, &GC_OP_ChladniWave::SetHarmonics)
        .addProperty("SetMethod", &GC_OP_ChladniWave::GetSetMethod, &GC_OP_ChladniWave::SetSetMethod)
        .addProperty("LocalSpaceControlPoint", &GC_OP_ChladniWave::GetLocalSpaceControlPoint, &GC_OP_ChladniWave::SetLocalSpaceControlPoint)
        .addProperty("3D", &GC_OP_ChladniWave::Get3D, &GC_OP_ChladniWave::Set3D)
        .endClass();
}