#include "../../../core/scripting/generated/classes/GResponseContext_t.h"
#include "../core.h"

void SetupLuaClassGResponseContext_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GResponseContext_t>("ResponseContext_t")
        .addProperty("Name", &GResponseContext_t::GetName, &GResponseContext_t::SetName)
        .addProperty("Value", &GResponseContext_t::GetValue, &GResponseContext_t::SetValue)
        .endClass();
}