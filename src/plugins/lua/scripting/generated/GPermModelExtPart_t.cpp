#include "../../../core/scripting/generated/classes/GPermModelExtPart_t.h"
#include "../core.h"

void SetupLuaClassGPermModelExtPart_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPermModelExtPart_t>("PermModelExtPart_t")
        .addProperty("Name", &GPermModelExtPart_t::GetName, &GPermModelExtPart_t::SetName)
        .addProperty("Parent", &GPermModelExtPart_t::GetParent, &GPermModelExtPart_t::SetParent)
        .endClass();
}