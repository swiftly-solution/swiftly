#include "../../../core/scripting/generated/classes/GC_OP_RemapScalarOnceTimed.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapScalarOnceTimed(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapScalarOnceTimed>("C_OP_RemapScalarOnceTimed")
        .addProperty("Proportional", &GC_OP_RemapScalarOnceTimed::GetProportional, &GC_OP_RemapScalarOnceTimed::SetProportional)
        .addProperty("FieldInput", &GC_OP_RemapScalarOnceTimed::GetFieldInput, &GC_OP_RemapScalarOnceTimed::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_RemapScalarOnceTimed::GetFieldOutput, &GC_OP_RemapScalarOnceTimed::SetFieldOutput)
        .addProperty("InputMin", &GC_OP_RemapScalarOnceTimed::GetInputMin, &GC_OP_RemapScalarOnceTimed::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapScalarOnceTimed::GetInputMax, &GC_OP_RemapScalarOnceTimed::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapScalarOnceTimed::GetOutputMin, &GC_OP_RemapScalarOnceTimed::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapScalarOnceTimed::GetOutputMax, &GC_OP_RemapScalarOnceTimed::SetOutputMax)
        .addProperty("RemapTime", &GC_OP_RemapScalarOnceTimed::GetRemapTime, &GC_OP_RemapScalarOnceTimed::SetRemapTime)
        .endClass();
}