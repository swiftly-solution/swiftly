#include "../../../core/scripting/generated/classes/GRnTriangle_t.h"
#include "../core.h"

void SetupLuaClassGRnTriangle_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnTriangle_t>("RnTriangle_t")
        .addProperty("Index", &GRnTriangle_t::GetIndex, &GRnTriangle_t::SetIndex)
        .endClass();
}