#include "../../../core/scripting/generated/classes/GC_OP_RenderLightBeam.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderLightBeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderLightBeam>("C_OP_RenderLightBeam")
        .addProperty("ColorBlendType", &GC_OP_RenderLightBeam::GetColorBlendType, &GC_OP_RenderLightBeam::SetColorBlendType)
        .addProperty("BrightnessLumensPerMeter", &GC_OP_RenderLightBeam::GetBrightnessLumensPerMeter, &GC_OP_RenderLightBeam::SetBrightnessLumensPerMeter)
        .addProperty("CastShadows", &GC_OP_RenderLightBeam::GetCastShadows, &GC_OP_RenderLightBeam::SetCastShadows)
        .addProperty("Skirt", &GC_OP_RenderLightBeam::GetSkirt, &GC_OP_RenderLightBeam::SetSkirt)
        .addProperty("Range", &GC_OP_RenderLightBeam::GetRange, &GC_OP_RenderLightBeam::SetRange)
        .addProperty("Thickness", &GC_OP_RenderLightBeam::GetThickness, &GC_OP_RenderLightBeam::SetThickness)
        .endClass();
}