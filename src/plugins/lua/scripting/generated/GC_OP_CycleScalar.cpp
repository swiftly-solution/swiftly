#include "../../../core/scripting/generated/classes/GC_OP_CycleScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_CycleScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_CycleScalar>("C_OP_CycleScalar")
        .addProperty("DestField", &GC_OP_CycleScalar::GetDestField, &GC_OP_CycleScalar::SetDestField)
        .addProperty("StartValue", &GC_OP_CycleScalar::GetStartValue, &GC_OP_CycleScalar::SetStartValue)
        .addProperty("EndValue", &GC_OP_CycleScalar::GetEndValue, &GC_OP_CycleScalar::SetEndValue)
        .addProperty("CycleTime", &GC_OP_CycleScalar::GetCycleTime, &GC_OP_CycleScalar::SetCycleTime)
        .addProperty("DoNotRepeatCycle", &GC_OP_CycleScalar::GetDoNotRepeatCycle, &GC_OP_CycleScalar::SetDoNotRepeatCycle)
        .addProperty("SynchronizeParticles", &GC_OP_CycleScalar::GetSynchronizeParticles, &GC_OP_CycleScalar::SetSynchronizeParticles)
        .addProperty("CPScale", &GC_OP_CycleScalar::GetCPScale, &GC_OP_CycleScalar::SetCPScale)
        .addProperty("CPFieldMin", &GC_OP_CycleScalar::GetCPFieldMin, &GC_OP_CycleScalar::SetCPFieldMin)
        .addProperty("CPFieldMax", &GC_OP_CycleScalar::GetCPFieldMax, &GC_OP_CycleScalar::SetCPFieldMax)
        .addProperty("SetMethod", &GC_OP_CycleScalar::GetSetMethod, &GC_OP_CycleScalar::SetSetMethod)
        .endClass();
}