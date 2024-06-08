#include "../../../core/scripting/generated/classes/GFeSimdTri_t.h"
#include "../core.h"

void SetupLuaClassGFeSimdTri_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdTri_t>("FeSimdTri_t")
        .addProperty("W1", &GFeSimdTri_t::GetW1, &GFeSimdTri_t::SetW1)
        .addProperty("W2", &GFeSimdTri_t::GetW2, &GFeSimdTri_t::SetW2)
        .addProperty("1x", &GFeSimdTri_t::Get1x, &GFeSimdTri_t::Set1x)
        .endClass();
}