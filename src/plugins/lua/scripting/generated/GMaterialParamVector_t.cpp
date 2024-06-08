#include "../../../core/scripting/generated/classes/GMaterialParamVector_t.h"
#include "../core.h"

void SetupLuaClassGMaterialParamVector_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamVector_t>("MaterialParamVector_t")
        .addProperty("Value", &GMaterialParamVector_t::GetValue, &GMaterialParamVector_t::SetValue)
        .endClass();
}