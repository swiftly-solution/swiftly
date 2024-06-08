#include "../../../core/scripting/generated/classes/GC_OP_DriveCPFromGlobalSoundFloat.h"
#include "../core.h"

void SetupLuaClassGC_OP_DriveCPFromGlobalSoundFloat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DriveCPFromGlobalSoundFloat>("C_OP_DriveCPFromGlobalSoundFloat")
        .addProperty("OutputControlPoint", &GC_OP_DriveCPFromGlobalSoundFloat::GetOutputControlPoint, &GC_OP_DriveCPFromGlobalSoundFloat::SetOutputControlPoint)
        .addProperty("OutputField", &GC_OP_DriveCPFromGlobalSoundFloat::GetOutputField, &GC_OP_DriveCPFromGlobalSoundFloat::SetOutputField)
        .addProperty("InputMin", &GC_OP_DriveCPFromGlobalSoundFloat::GetInputMin, &GC_OP_DriveCPFromGlobalSoundFloat::SetInputMin)
        .addProperty("InputMax", &GC_OP_DriveCPFromGlobalSoundFloat::GetInputMax, &GC_OP_DriveCPFromGlobalSoundFloat::SetInputMax)
        .addProperty("OutputMin", &GC_OP_DriveCPFromGlobalSoundFloat::GetOutputMin, &GC_OP_DriveCPFromGlobalSoundFloat::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_DriveCPFromGlobalSoundFloat::GetOutputMax, &GC_OP_DriveCPFromGlobalSoundFloat::SetOutputMax)
        .addProperty("StackName", &GC_OP_DriveCPFromGlobalSoundFloat::GetStackName, &GC_OP_DriveCPFromGlobalSoundFloat::SetStackName)
        .addProperty("OperatorName", &GC_OP_DriveCPFromGlobalSoundFloat::GetOperatorName, &GC_OP_DriveCPFromGlobalSoundFloat::SetOperatorName)
        .addProperty("FieldName", &GC_OP_DriveCPFromGlobalSoundFloat::GetFieldName, &GC_OP_DriveCPFromGlobalSoundFloat::SetFieldName)
        .endClass();
}