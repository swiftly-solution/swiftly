#include "../../../core/scripting/generated/classes/GC_OP_RenderLights.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderLights(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderLights>("C_OP_RenderLights")
        .addProperty("AnimationRate", &GC_OP_RenderLights::GetAnimationRate, &GC_OP_RenderLights::SetAnimationRate)
        .addProperty("AnimationType", &GC_OP_RenderLights::GetAnimationType, &GC_OP_RenderLights::SetAnimationType)
        .addProperty("AnimateInFPS", &GC_OP_RenderLights::GetAnimateInFPS, &GC_OP_RenderLights::SetAnimateInFPS)
        .addProperty("MinSize", &GC_OP_RenderLights::GetMinSize, &GC_OP_RenderLights::SetMinSize)
        .addProperty("MaxSize", &GC_OP_RenderLights::GetMaxSize, &GC_OP_RenderLights::SetMaxSize)
        .addProperty("StartFadeSize", &GC_OP_RenderLights::GetStartFadeSize, &GC_OP_RenderLights::SetStartFadeSize)
        .addProperty("EndFadeSize", &GC_OP_RenderLights::GetEndFadeSize, &GC_OP_RenderLights::SetEndFadeSize)
        .endClass();
}