#include "../../../core/scripting/generated/classes/GCSprite.h"
#include "../core.h"

void SetupLuaClassGCSprite(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSprite>("CSprite")
        .addProperty("AttachedToEntity", &GCSprite::GetAttachedToEntity, &GCSprite::SetAttachedToEntity)
        .addProperty("SpriteFramerate", &GCSprite::GetSpriteFramerate, &GCSprite::SetSpriteFramerate)
        .addProperty("Frame", &GCSprite::GetFrame, &GCSprite::SetFrame)
        .addProperty("Brightness", &GCSprite::GetBrightness, &GCSprite::SetBrightness)
        .addProperty("BrightnessDuration", &GCSprite::GetBrightnessDuration, &GCSprite::SetBrightnessDuration)
        .addProperty("SpriteScale", &GCSprite::GetSpriteScale, &GCSprite::SetSpriteScale)
        .addProperty("ScaleDuration", &GCSprite::GetScaleDuration, &GCSprite::SetScaleDuration)
        .addProperty("WorldSpaceScale", &GCSprite::GetWorldSpaceScale, &GCSprite::SetWorldSpaceScale)
        .addProperty("GlowProxySize", &GCSprite::GetGlowProxySize, &GCSprite::SetGlowProxySize)
        .addProperty("HDRColorScale", &GCSprite::GetHDRColorScale, &GCSprite::SetHDRColorScale)
        .addProperty("MaxFrame", &GCSprite::GetMaxFrame, &GCSprite::SetMaxFrame)
        .addProperty("StartScale", &GCSprite::GetStartScale, &GCSprite::SetStartScale)
        .addProperty("DestScale", &GCSprite::GetDestScale, &GCSprite::SetDestScale)
        .addProperty("StartBrightness", &GCSprite::GetStartBrightness, &GCSprite::SetStartBrightness)
        .addProperty("DestBrightness", &GCSprite::GetDestBrightness, &GCSprite::SetDestBrightness)
        .addProperty("SpriteWidth", &GCSprite::GetSpriteWidth, &GCSprite::SetSpriteWidth)
        .addProperty("SpriteHeight", &GCSprite::GetSpriteHeight, &GCSprite::SetSpriteHeight)
        .endClass();
}