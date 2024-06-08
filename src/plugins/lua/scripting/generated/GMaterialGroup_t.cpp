#include "../../../core/scripting/generated/classes/GMaterialGroup_t.h"
#include "../core.h"

void SetupLuaClassGMaterialGroup_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialGroup_t>("MaterialGroup_t")
        .addProperty("Name", &GMaterialGroup_t::GetName, &GMaterialGroup_t::SetName)
        .endClass();
}