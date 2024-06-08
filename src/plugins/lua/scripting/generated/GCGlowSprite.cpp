#include "../../../core/scripting/generated/classes/GCGlowSprite.h"
#include "../core.h"

void SetupLuaClassGCGlowSprite(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGlowSprite>("CGlowSprite")
        .addProperty("Color", &GCGlowSprite::GetColor, &GCGlowSprite::SetColor)
        .addProperty("HorzSize", &GCGlowSprite::GetHorzSize, &GCGlowSprite::SetHorzSize)
        .addProperty("VertSize", &GCGlowSprite::GetVertSize, &GCGlowSprite::SetVertSize)
        .endClass();
}