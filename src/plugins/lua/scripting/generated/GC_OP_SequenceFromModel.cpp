#include "../../../core/scripting/generated/classes/GC_OP_SequenceFromModel.h"
#include "../core.h"

void SetupLuaClassGC_OP_SequenceFromModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SequenceFromModel>("C_OP_SequenceFromModel")
        .addProperty("ControlPointNumber", &GC_OP_SequenceFromModel::GetControlPointNumber, &GC_OP_SequenceFromModel::SetControlPointNumber)
        .addProperty("FieldOutput", &GC_OP_SequenceFromModel::GetFieldOutput, &GC_OP_SequenceFromModel::SetFieldOutput)
        .addProperty("FieldOutputAnim", &GC_OP_SequenceFromModel::GetFieldOutputAnim, &GC_OP_SequenceFromModel::SetFieldOutputAnim)
        .addProperty("InputMin", &GC_OP_SequenceFromModel::GetInputMin, &GC_OP_SequenceFromModel::SetInputMin)
        .addProperty("InputMax", &GC_OP_SequenceFromModel::GetInputMax, &GC_OP_SequenceFromModel::SetInputMax)
        .addProperty("OutputMin", &GC_OP_SequenceFromModel::GetOutputMin, &GC_OP_SequenceFromModel::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_SequenceFromModel::GetOutputMax, &GC_OP_SequenceFromModel::SetOutputMax)
        .addProperty("SetMethod", &GC_OP_SequenceFromModel::GetSetMethod, &GC_OP_SequenceFromModel::SetSetMethod)
        .endClass();
}