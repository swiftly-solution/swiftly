#include "../../../core/scripting/generated/classes/GC_INIT_RandomAlphaWindowThreshold.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomAlphaWindowThreshold(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomAlphaWindowThreshold>("C_INIT_RandomAlphaWindowThreshold")
        .addProperty("Min", &GC_INIT_RandomAlphaWindowThreshold::GetMin, &GC_INIT_RandomAlphaWindowThreshold::SetMin)
        .addProperty("Max", &GC_INIT_RandomAlphaWindowThreshold::GetMax, &GC_INIT_RandomAlphaWindowThreshold::SetMax)
        .addProperty("Exponent", &GC_INIT_RandomAlphaWindowThreshold::GetExponent, &GC_INIT_RandomAlphaWindowThreshold::SetExponent)
        .endClass();
}