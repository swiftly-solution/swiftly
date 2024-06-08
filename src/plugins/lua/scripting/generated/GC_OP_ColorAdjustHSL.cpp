#include "../../../core/scripting/generated/classes/GC_OP_ColorAdjustHSL.h"
#include "../core.h"

void SetupLuaClassGC_OP_ColorAdjustHSL(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ColorAdjustHSL>("C_OP_ColorAdjustHSL")
        .addProperty("HueAdjust", &GC_OP_ColorAdjustHSL::GetHueAdjust, &GC_OP_ColorAdjustHSL::SetHueAdjust)
        .addProperty("SaturationAdjust", &GC_OP_ColorAdjustHSL::GetSaturationAdjust, &GC_OP_ColorAdjustHSL::SetSaturationAdjust)
        .addProperty("LightnessAdjust", &GC_OP_ColorAdjustHSL::GetLightnessAdjust, &GC_OP_ColorAdjustHSL::SetLightnessAdjust)
        .endClass();
}