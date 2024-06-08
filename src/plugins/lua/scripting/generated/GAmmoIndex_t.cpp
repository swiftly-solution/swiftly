#include "../../../core/scripting/generated/classes/GAmmoIndex_t.h"
#include "../core.h"

void SetupLuaClassGAmmoIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAmmoIndex_t>("AmmoIndex_t")
        .addProperty("Value", &GAmmoIndex_t::GetValue, &GAmmoIndex_t::SetValue)
        .endClass();
}