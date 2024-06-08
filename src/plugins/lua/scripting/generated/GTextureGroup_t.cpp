#include "../../../core/scripting/generated/classes/GTextureGroup_t.h"
#include "../core.h"

void SetupLuaClassGTextureGroup_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTextureGroup_t>("TextureGroup_t")
        .addProperty("Enabled", &GTextureGroup_t::GetEnabled, &GTextureGroup_t::SetEnabled)
        .addProperty("ReplaceTextureWithGradient", &GTextureGroup_t::GetReplaceTextureWithGradient, &GTextureGroup_t::SetReplaceTextureWithGradient)
        .addProperty("TextureType", &GTextureGroup_t::GetTextureType, &GTextureGroup_t::SetTextureType)
        .addProperty("TextureChannels", &GTextureGroup_t::GetTextureChannels, &GTextureGroup_t::SetTextureChannels)
        .addProperty("TextureBlendMode", &GTextureGroup_t::GetTextureBlendMode, &GTextureGroup_t::SetTextureBlendMode)
        .addProperty("TextureBlend", &GTextureGroup_t::GetTextureBlend, &GTextureGroup_t::SetTextureBlend)
        .addProperty("TextureControls", &GTextureGroup_t::GetTextureControls, &GTextureGroup_t::SetTextureControls)
        .endClass();
}