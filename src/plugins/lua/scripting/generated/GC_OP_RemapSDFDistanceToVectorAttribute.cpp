#include "../../../core/scripting/generated/classes/GC_OP_RemapSDFDistanceToVectorAttribute.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapSDFDistanceToVectorAttribute(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapSDFDistanceToVectorAttribute>("C_OP_RemapSDFDistanceToVectorAttribute")
        .addProperty("VectorFieldOutput", &GC_OP_RemapSDFDistanceToVectorAttribute::GetVectorFieldOutput, &GC_OP_RemapSDFDistanceToVectorAttribute::SetVectorFieldOutput)
        .addProperty("VectorFieldInput", &GC_OP_RemapSDFDistanceToVectorAttribute::GetVectorFieldInput, &GC_OP_RemapSDFDistanceToVectorAttribute::SetVectorFieldInput)
        .addProperty("MinDistance", &GC_OP_RemapSDFDistanceToVectorAttribute::GetMinDistance, &GC_OP_RemapSDFDistanceToVectorAttribute::SetMinDistance)
        .addProperty("MaxDistance", &GC_OP_RemapSDFDistanceToVectorAttribute::GetMaxDistance, &GC_OP_RemapSDFDistanceToVectorAttribute::SetMaxDistance)
        .addProperty("ValueBelowMin", &GC_OP_RemapSDFDistanceToVectorAttribute::GetValueBelowMin, &GC_OP_RemapSDFDistanceToVectorAttribute::SetValueBelowMin)
        .addProperty("ValueAtMin", &GC_OP_RemapSDFDistanceToVectorAttribute::GetValueAtMin, &GC_OP_RemapSDFDistanceToVectorAttribute::SetValueAtMin)
        .addProperty("ValueAtMax", &GC_OP_RemapSDFDistanceToVectorAttribute::GetValueAtMax, &GC_OP_RemapSDFDistanceToVectorAttribute::SetValueAtMax)
        .addProperty("ValueAboveMax", &GC_OP_RemapSDFDistanceToVectorAttribute::GetValueAboveMax, &GC_OP_RemapSDFDistanceToVectorAttribute::SetValueAboveMax)
        .endClass();
}