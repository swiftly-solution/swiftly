#include "../../../core/scripting/generated/classes/GC_INIT_AddVectorToVector.h"
#include "../core.h"

void SetupLuaClassGC_INIT_AddVectorToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_AddVectorToVector>("C_INIT_AddVectorToVector")
        .addProperty("Scale", &GC_INIT_AddVectorToVector::GetScale, &GC_INIT_AddVectorToVector::SetScale)
        .addProperty("FieldOutput", &GC_INIT_AddVectorToVector::GetFieldOutput, &GC_INIT_AddVectorToVector::SetFieldOutput)
        .addProperty("FieldInput", &GC_INIT_AddVectorToVector::GetFieldInput, &GC_INIT_AddVectorToVector::SetFieldInput)
        .addProperty("OffsetMin", &GC_INIT_AddVectorToVector::GetOffsetMin, &GC_INIT_AddVectorToVector::SetOffsetMin)
        .addProperty("OffsetMax", &GC_INIT_AddVectorToVector::GetOffsetMax, &GC_INIT_AddVectorToVector::SetOffsetMax)
        .addProperty("RandomnessParameters", &GC_INIT_AddVectorToVector::GetRandomnessParameters, &GC_INIT_AddVectorToVector::SetRandomnessParameters)
        .endClass();
}