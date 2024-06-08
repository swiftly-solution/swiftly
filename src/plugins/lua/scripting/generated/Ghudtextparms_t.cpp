#include "../../../core/scripting/generated/classes/Ghudtextparms_t.h"
#include "../core.h"

void SetupLuaClassGhudtextparms_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Ghudtextparms_t>("hudtextparms_t")
        .addProperty("Color1", &Ghudtextparms_t::GetColor1, &Ghudtextparms_t::SetColor1)
        .addProperty("Color2", &Ghudtextparms_t::GetColor2, &Ghudtextparms_t::SetColor2)
        .addProperty("Effect", &Ghudtextparms_t::GetEffect, &Ghudtextparms_t::SetEffect)
        .addProperty("Channel", &Ghudtextparms_t::GetChannel, &Ghudtextparms_t::SetChannel)
        .addProperty("X", &Ghudtextparms_t::GetX, &Ghudtextparms_t::SetX)
        .addProperty("Y", &Ghudtextparms_t::GetY, &Ghudtextparms_t::SetY)
        .endClass();
}