#include "../../../core/scripting/generated/classes/GMaterialParamFloat_t.h"
#include "../core.h"

void SetupLuaClassGMaterialParamFloat_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamFloat_t>("MaterialParamFloat_t")
        .addProperty("Value", &GMaterialParamFloat_t::GetValue, &GMaterialParamFloat_t::SetValue)
        .endClass();
}