#include "../../../core/scripting/generated/classes/GC_INIT_OffsetVectorToVector.h"
#include "../core.h"

void SetupLuaClassGC_INIT_OffsetVectorToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_OffsetVectorToVector>("C_INIT_OffsetVectorToVector")
        .addProperty("FieldInput", &GC_INIT_OffsetVectorToVector::GetFieldInput, &GC_INIT_OffsetVectorToVector::SetFieldInput)
        .addProperty("FieldOutput", &GC_INIT_OffsetVectorToVector::GetFieldOutput, &GC_INIT_OffsetVectorToVector::SetFieldOutput)
        .addProperty("OutputMin", &GC_INIT_OffsetVectorToVector::GetOutputMin, &GC_INIT_OffsetVectorToVector::SetOutputMin)
        .addProperty("OutputMax", &GC_INIT_OffsetVectorToVector::GetOutputMax, &GC_INIT_OffsetVectorToVector::SetOutputMax)
        .addProperty("RandomnessParameters", &GC_INIT_OffsetVectorToVector::GetRandomnessParameters, &GC_INIT_OffsetVectorToVector::SetRandomnessParameters)
        .endClass();
}