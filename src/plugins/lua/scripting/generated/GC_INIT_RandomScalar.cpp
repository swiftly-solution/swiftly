#include "../../../core/scripting/generated/classes/GC_INIT_RandomScalar.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomScalar>("C_INIT_RandomScalar")
        .addProperty("Min", &GC_INIT_RandomScalar::GetMin, &GC_INIT_RandomScalar::SetMin)
        .addProperty("Max", &GC_INIT_RandomScalar::GetMax, &GC_INIT_RandomScalar::SetMax)
        .addProperty("Exponent", &GC_INIT_RandomScalar::GetExponent, &GC_INIT_RandomScalar::SetExponent)
        .addProperty("FieldOutput", &GC_INIT_RandomScalar::GetFieldOutput, &GC_INIT_RandomScalar::SetFieldOutput)
        .endClass();
}