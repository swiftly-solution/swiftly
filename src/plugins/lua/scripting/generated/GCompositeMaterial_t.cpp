#include "../../../core/scripting/generated/classes/GCompositeMaterial_t.h"
#include "../core.h"

void SetupLuaClassGCompositeMaterial_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterial_t>("CompositeMaterial_t")
        .addProperty("GeneratedTextures", &GCompositeMaterial_t::GetGeneratedTextures, &GCompositeMaterial_t::SetGeneratedTextures)
        .endClass();
}