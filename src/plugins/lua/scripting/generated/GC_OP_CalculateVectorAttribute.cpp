#include "../../../core/scripting/generated/classes/GC_OP_CalculateVectorAttribute.h"
#include "../core.h"

void SetupLuaClassGC_OP_CalculateVectorAttribute(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_CalculateVectorAttribute>("C_OP_CalculateVectorAttribute")
        .addProperty("StartValue", &GC_OP_CalculateVectorAttribute::GetStartValue, &GC_OP_CalculateVectorAttribute::SetStartValue)
        .addProperty("FieldInput1", &GC_OP_CalculateVectorAttribute::GetFieldInput1, &GC_OP_CalculateVectorAttribute::SetFieldInput1)
        .addProperty("InputScale1", &GC_OP_CalculateVectorAttribute::GetInputScale1, &GC_OP_CalculateVectorAttribute::SetInputScale1)
        .addProperty("FieldInput2", &GC_OP_CalculateVectorAttribute::GetFieldInput2, &GC_OP_CalculateVectorAttribute::SetFieldInput2)
        .addProperty("InputScale2", &GC_OP_CalculateVectorAttribute::GetInputScale2, &GC_OP_CalculateVectorAttribute::SetInputScale2)
        .addProperty("ControlPointInput1", &GC_OP_CalculateVectorAttribute::GetControlPointInput1, &GC_OP_CalculateVectorAttribute::SetControlPointInput1)
        .addProperty("ControlPointScale1", &GC_OP_CalculateVectorAttribute::GetControlPointScale1, &GC_OP_CalculateVectorAttribute::SetControlPointScale1)
        .addProperty("ControlPointInput2", &GC_OP_CalculateVectorAttribute::GetControlPointInput2, &GC_OP_CalculateVectorAttribute::SetControlPointInput2)
        .addProperty("ControlPointScale2", &GC_OP_CalculateVectorAttribute::GetControlPointScale2, &GC_OP_CalculateVectorAttribute::SetControlPointScale2)
        .addProperty("FieldOutput", &GC_OP_CalculateVectorAttribute::GetFieldOutput, &GC_OP_CalculateVectorAttribute::SetFieldOutput)
        .addProperty("FinalOutputScale", &GC_OP_CalculateVectorAttribute::GetFinalOutputScale, &GC_OP_CalculateVectorAttribute::SetFinalOutputScale)
        .endClass();
}