#include "../../../core/scripting/generated/classes/GC_OP_ColorInterpolateRandom.h"
#include "../core.h"

void SetupLuaClassGC_OP_ColorInterpolateRandom(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ColorInterpolateRandom>("C_OP_ColorInterpolateRandom")
        .addProperty("ColorFadeMin", &GC_OP_ColorInterpolateRandom::GetColorFadeMin, &GC_OP_ColorInterpolateRandom::SetColorFadeMin)
        .addProperty("ColorFadeMax", &GC_OP_ColorInterpolateRandom::GetColorFadeMax, &GC_OP_ColorInterpolateRandom::SetColorFadeMax)
        .addProperty("FadeStartTime", &GC_OP_ColorInterpolateRandom::GetFadeStartTime, &GC_OP_ColorInterpolateRandom::SetFadeStartTime)
        .addProperty("FadeEndTime", &GC_OP_ColorInterpolateRandom::GetFadeEndTime, &GC_OP_ColorInterpolateRandom::SetFadeEndTime)
        .addProperty("FieldOutput", &GC_OP_ColorInterpolateRandom::GetFieldOutput, &GC_OP_ColorInterpolateRandom::SetFieldOutput)
        .addProperty("EaseInOut", &GC_OP_ColorInterpolateRandom::GetEaseInOut, &GC_OP_ColorInterpolateRandom::SetEaseInOut)
        .endClass();
}