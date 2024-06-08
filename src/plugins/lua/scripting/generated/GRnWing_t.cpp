#include "../../../core/scripting/generated/classes/GRnWing_t.h"
#include "../core.h"

void SetupLuaClassGRnWing_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnWing_t>("RnWing_t")
        .addProperty("Index", &GRnWing_t::GetIndex, &GRnWing_t::SetIndex)
        .endClass();
}