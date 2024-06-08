#include "../../../core/scripting/generated/classes/GC_INIT_RandomAlpha.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomAlpha(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomAlpha>("C_INIT_RandomAlpha")
        .addProperty("FieldOutput", &GC_INIT_RandomAlpha::GetFieldOutput, &GC_INIT_RandomAlpha::SetFieldOutput)
        .addProperty("AlphaMin", &GC_INIT_RandomAlpha::GetAlphaMin, &GC_INIT_RandomAlpha::SetAlphaMin)
        .addProperty("AlphaMax", &GC_INIT_RandomAlpha::GetAlphaMax, &GC_INIT_RandomAlpha::SetAlphaMax)
        .addProperty("AlphaRandExponent", &GC_INIT_RandomAlpha::GetAlphaRandExponent, &GC_INIT_RandomAlpha::SetAlphaRandExponent)
        .endClass();
}