#include "../../../core/scripting/generated/classes/GMaterialParam_t.h"
#include "../core.h"

void SetupLuaClassGMaterialParam_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParam_t>("MaterialParam_t")
        .addProperty("Name", &GMaterialParam_t::GetName, &GMaterialParam_t::SetName)
        .endClass();
}