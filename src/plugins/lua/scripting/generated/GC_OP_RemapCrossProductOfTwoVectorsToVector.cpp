#include "../../../core/scripting/generated/classes/GC_OP_RemapCrossProductOfTwoVectorsToVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapCrossProductOfTwoVectorsToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapCrossProductOfTwoVectorsToVector>("C_OP_RemapCrossProductOfTwoVectorsToVector")
        .addProperty("InputVec1", &GC_OP_RemapCrossProductOfTwoVectorsToVector::GetInputVec1, &GC_OP_RemapCrossProductOfTwoVectorsToVector::SetInputVec1)
        .addProperty("InputVec2", &GC_OP_RemapCrossProductOfTwoVectorsToVector::GetInputVec2, &GC_OP_RemapCrossProductOfTwoVectorsToVector::SetInputVec2)
        .addProperty("FieldOutput", &GC_OP_RemapCrossProductOfTwoVectorsToVector::GetFieldOutput, &GC_OP_RemapCrossProductOfTwoVectorsToVector::SetFieldOutput)
        .addProperty("Normalize", &GC_OP_RemapCrossProductOfTwoVectorsToVector::GetNormalize, &GC_OP_RemapCrossProductOfTwoVectorsToVector::SetNormalize)
        .endClass();
}