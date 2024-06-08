#include "../../../core/scripting/generated/classes/GBlendItem_t.h"
#include "../core.h"

void SetupLuaClassGBlendItem_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GBlendItem_t>("BlendItem_t")
        .addProperty("Tags", &GBlendItem_t::GetTags, &GBlendItem_t::SetTags)
        .addProperty("Child", &GBlendItem_t::GetChild, &GBlendItem_t::SetChild)
        .addProperty("Pos", &GBlendItem_t::GetPos, &GBlendItem_t::SetPos)
        .addProperty("Duration", &GBlendItem_t::GetDuration, &GBlendItem_t::SetDuration)
        .addProperty("UseCustomDuration", &GBlendItem_t::GetUseCustomDuration, &GBlendItem_t::SetUseCustomDuration)
        .endClass();
}