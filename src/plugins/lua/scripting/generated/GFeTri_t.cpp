#include "../../../core/scripting/generated/classes/GFeTri_t.h"
#include "../core.h"

void SetupLuaClassGFeTri_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeTri_t>("FeTri_t")
        .addProperty("Node", &GFeTri_t::GetNode, &GFeTri_t::SetNode)
        .addProperty("W1", &GFeTri_t::GetW1, &GFeTri_t::SetW1)
        .addProperty("W2", &GFeTri_t::GetW2, &GFeTri_t::SetW2)
        .addProperty("1x", &GFeTri_t::Get1x, &GFeTri_t::Set1x)
        .addProperty("2", &GFeTri_t::Get2, &GFeTri_t::Set2)
        .endClass();
}