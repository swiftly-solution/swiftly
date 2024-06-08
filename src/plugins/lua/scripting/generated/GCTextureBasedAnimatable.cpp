#include "../../../core/scripting/generated/classes/GCTextureBasedAnimatable.h"
#include "../core.h"

void SetupLuaClassGCTextureBasedAnimatable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTextureBasedAnimatable>("CTextureBasedAnimatable")
        .addProperty("Loop", &GCTextureBasedAnimatable::GetLoop, &GCTextureBasedAnimatable::SetLoop)
        .addProperty("FPS", &GCTextureBasedAnimatable::GetFPS, &GCTextureBasedAnimatable::SetFPS)
        .addProperty("AnimationBoundsMin", &GCTextureBasedAnimatable::GetAnimationBoundsMin, &GCTextureBasedAnimatable::SetAnimationBoundsMin)
        .addProperty("AnimationBoundsMax", &GCTextureBasedAnimatable::GetAnimationBoundsMax, &GCTextureBasedAnimatable::SetAnimationBoundsMax)
        .addProperty("StartTime", &GCTextureBasedAnimatable::GetStartTime, &GCTextureBasedAnimatable::SetStartTime)
        .addProperty("StartFrame", &GCTextureBasedAnimatable::GetStartFrame, &GCTextureBasedAnimatable::SetStartFrame)
        .endClass();
}