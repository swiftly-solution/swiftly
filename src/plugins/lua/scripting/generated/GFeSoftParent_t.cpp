#include "../../../core/scripting/generated/classes/GFeSoftParent_t.h"
#include "../core.h"

void SetupLuaClassGFeSoftParent_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSoftParent_t>("FeSoftParent_t")
        .addProperty("Parent", &GFeSoftParent_t::GetParent, &GFeSoftParent_t::SetParent)
        .addProperty("Alpha", &GFeSoftParent_t::GetAlpha, &GFeSoftParent_t::SetAlpha)
        .endClass();
}