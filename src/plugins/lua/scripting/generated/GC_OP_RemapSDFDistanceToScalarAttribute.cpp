#include "../../../core/scripting/generated/classes/GC_OP_RemapSDFDistanceToScalarAttribute.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapSDFDistanceToScalarAttribute(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapSDFDistanceToScalarAttribute>("C_OP_RemapSDFDistanceToScalarAttribute")
        .addProperty("FieldOutput", &GC_OP_RemapSDFDistanceToScalarAttribute::GetFieldOutput, &GC_OP_RemapSDFDistanceToScalarAttribute::SetFieldOutput)
        .addProperty("VectorFieldInput", &GC_OP_RemapSDFDistanceToScalarAttribute::GetVectorFieldInput, &GC_OP_RemapSDFDistanceToScalarAttribute::SetVectorFieldInput)
        .addProperty("MinDistance", &GC_OP_RemapSDFDistanceToScalarAttribute::GetMinDistance, &GC_OP_RemapSDFDistanceToScalarAttribute::SetMinDistance)
        .addProperty("MaxDistance", &GC_OP_RemapSDFDistanceToScalarAttribute::GetMaxDistance, &GC_OP_RemapSDFDistanceToScalarAttribute::SetMaxDistance)
        .addProperty("ValueBelowMin", &GC_OP_RemapSDFDistanceToScalarAttribute::GetValueBelowMin, &GC_OP_RemapSDFDistanceToScalarAttribute::SetValueBelowMin)
        .addProperty("ValueAtMin", &GC_OP_RemapSDFDistanceToScalarAttribute::GetValueAtMin, &GC_OP_RemapSDFDistanceToScalarAttribute::SetValueAtMin)
        .addProperty("ValueAtMax", &GC_OP_RemapSDFDistanceToScalarAttribute::GetValueAtMax, &GC_OP_RemapSDFDistanceToScalarAttribute::SetValueAtMax)
        .addProperty("ValueAboveMax", &GC_OP_RemapSDFDistanceToScalarAttribute::GetValueAboveMax, &GC_OP_RemapSDFDistanceToScalarAttribute::SetValueAboveMax)
        .endClass();
}