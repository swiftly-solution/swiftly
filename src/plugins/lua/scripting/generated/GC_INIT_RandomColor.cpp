#include "../../../core/scripting/generated/classes/GC_INIT_RandomColor.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomColor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomColor>("C_INIT_RandomColor")
        .addProperty("ColorMin", &GC_INIT_RandomColor::GetColorMin, &GC_INIT_RandomColor::SetColorMin)
        .addProperty("ColorMax", &GC_INIT_RandomColor::GetColorMax, &GC_INIT_RandomColor::SetColorMax)
        .addProperty("TintMin", &GC_INIT_RandomColor::GetTintMin, &GC_INIT_RandomColor::SetTintMin)
        .addProperty("TintMax", &GC_INIT_RandomColor::GetTintMax, &GC_INIT_RandomColor::SetTintMax)
        .addProperty("TintPerc", &GC_INIT_RandomColor::GetTintPerc, &GC_INIT_RandomColor::SetTintPerc)
        .addProperty("UpdateThreshold", &GC_INIT_RandomColor::GetUpdateThreshold, &GC_INIT_RandomColor::SetUpdateThreshold)
        .addProperty("TintCP", &GC_INIT_RandomColor::GetTintCP, &GC_INIT_RandomColor::SetTintCP)
        .addProperty("FieldOutput", &GC_INIT_RandomColor::GetFieldOutput, &GC_INIT_RandomColor::SetFieldOutput)
        .addProperty("TintBlendMode", &GC_INIT_RandomColor::GetTintBlendMode, &GC_INIT_RandomColor::SetTintBlendMode)
        .addProperty("LightAmplification", &GC_INIT_RandomColor::GetLightAmplification, &GC_INIT_RandomColor::SetLightAmplification)
        .endClass();
}