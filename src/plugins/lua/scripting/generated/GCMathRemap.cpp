#include "../../../core/scripting/generated/classes/GCMathRemap.h"
#include "../core.h"

void SetupLuaClassGCMathRemap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMathRemap>("CMathRemap")
        .addProperty("InMin", &GCMathRemap::GetInMin, &GCMathRemap::SetInMin)
        .addProperty("InMax", &GCMathRemap::GetInMax, &GCMathRemap::SetInMax)
        .addProperty("Out1", &GCMathRemap::GetOut1, &GCMathRemap::SetOut1)
        .addProperty("Out2", &GCMathRemap::GetOut2, &GCMathRemap::SetOut2)
        .addProperty("OldInValue", &GCMathRemap::GetOldInValue, &GCMathRemap::SetOldInValue)
        .addProperty("Enabled", &GCMathRemap::GetEnabled, &GCMathRemap::SetEnabled)
        .addProperty("OnRoseAboveMin", &GCMathRemap::GetOnRoseAboveMin, &GCMathRemap::SetOnRoseAboveMin)
        .addProperty("OnRoseAboveMax", &GCMathRemap::GetOnRoseAboveMax, &GCMathRemap::SetOnRoseAboveMax)
        .addProperty("OnFellBelowMin", &GCMathRemap::GetOnFellBelowMin, &GCMathRemap::SetOnFellBelowMin)
        .addProperty("OnFellBelowMax", &GCMathRemap::GetOnFellBelowMax, &GCMathRemap::SetOnFellBelowMax)
        .endClass();
}