#include "../../../core/scripting/generated/classes/GMaterialParamString_t.h"
#include "../core.h"

void SetupLuaClassGMaterialParamString_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamString_t>("MaterialParamString_t")
        .addProperty("Value", &GMaterialParamString_t::GetValue, &GMaterialParamString_t::SetValue)
        .endClass();
}