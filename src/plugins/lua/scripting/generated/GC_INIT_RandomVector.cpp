#include "../../../core/scripting/generated/classes/GC_INIT_RandomVector.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomVector>("C_INIT_RandomVector")
        .addProperty("Min", &GC_INIT_RandomVector::GetMin, &GC_INIT_RandomVector::SetMin)
        .addProperty("Max", &GC_INIT_RandomVector::GetMax, &GC_INIT_RandomVector::SetMax)
        .addProperty("FieldOutput", &GC_INIT_RandomVector::GetFieldOutput, &GC_INIT_RandomVector::SetFieldOutput)
        .addProperty("RandomnessParameters", &GC_INIT_RandomVector::GetRandomnessParameters, &GC_INIT_RandomVector::SetRandomnessParameters)
        .endClass();
}