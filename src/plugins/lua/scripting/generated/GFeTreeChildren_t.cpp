#include "../../../core/scripting/generated/classes/GFeTreeChildren_t.h"
#include "../core.h"

void SetupLuaClassGFeTreeChildren_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeTreeChildren_t>("FeTreeChildren_t")
        .addProperty("Child", &GFeTreeChildren_t::GetChild, &GFeTreeChildren_t::SetChild)
        .endClass();
}