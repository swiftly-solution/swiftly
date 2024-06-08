#include "../../../core/scripting/generated/classes/GResourceId_t.h"
#include "../core.h"

void SetupLuaClassGResourceId_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GResourceId_t>("ResourceId_t")
        .addProperty("Value", &GResourceId_t::GetValue, &GResourceId_t::SetValue)
        .endClass();
}