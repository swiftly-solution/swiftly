#include "../../../core/scripting/generated/classes/GC_OP_ColorInterpolate.h"
#include "../core.h"

void SetupLuaClassGC_OP_ColorInterpolate(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ColorInterpolate>("C_OP_ColorInterpolate")
        .addProperty("ColorFade", &GC_OP_ColorInterpolate::GetColorFade, &GC_OP_ColorInterpolate::SetColorFade)
        .addProperty("FadeStartTime", &GC_OP_ColorInterpolate::GetFadeStartTime, &GC_OP_ColorInterpolate::SetFadeStartTime)
        .addProperty("FadeEndTime", &GC_OP_ColorInterpolate::GetFadeEndTime, &GC_OP_ColorInterpolate::SetFadeEndTime)
        .addProperty("FieldOutput", &GC_OP_ColorInterpolate::GetFieldOutput, &GC_OP_ColorInterpolate::SetFieldOutput)
        .addProperty("EaseInOut", &GC_OP_ColorInterpolate::GetEaseInOut, &GC_OP_ColorInterpolate::SetEaseInOut)
        .endClass();
}