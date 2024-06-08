#include "../../../core/scripting/generated/classes/GNmPercent_t.h"
#include "../core.h"

void SetupLuaClassGNmPercent_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNmPercent_t>("NmPercent_t")
        .addProperty("Value", &GNmPercent_t::GetValue, &GNmPercent_t::SetValue)
        .endClass();
}