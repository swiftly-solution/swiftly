#include "../../../core/scripting/generated/classes/GC_INIT_InitialSequenceFromModel.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitialSequenceFromModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitialSequenceFromModel>("C_INIT_InitialSequenceFromModel")
        .addProperty("ControlPointNumber", &GC_INIT_InitialSequenceFromModel::GetControlPointNumber, &GC_INIT_InitialSequenceFromModel::SetControlPointNumber)
        .addProperty("FieldOutput", &GC_INIT_InitialSequenceFromModel::GetFieldOutput, &GC_INIT_InitialSequenceFromModel::SetFieldOutput)
        .addProperty("FieldOutputAnim", &GC_INIT_InitialSequenceFromModel::GetFieldOutputAnim, &GC_INIT_InitialSequenceFromModel::SetFieldOutputAnim)
        .addProperty("InputMin", &GC_INIT_InitialSequenceFromModel::GetInputMin, &GC_INIT_InitialSequenceFromModel::SetInputMin)
        .addProperty("InputMax", &GC_INIT_InitialSequenceFromModel::GetInputMax, &GC_INIT_InitialSequenceFromModel::SetInputMax)
        .addProperty("OutputMin", &GC_INIT_InitialSequenceFromModel::GetOutputMin, &GC_INIT_InitialSequenceFromModel::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_InitialSequenceFromModel::GetOutputMax, &GC_INIT_InitialSequenceFromModel::SetOutputMax)
        .addProperty("SetMethod", &GC_INIT_InitialSequenceFromModel::GetSetMethod, &GC_INIT_InitialSequenceFromModel::SetSetMethod)
        .endClass();
}