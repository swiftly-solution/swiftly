#include "../../../core/scripting/generated/classes/GMaterialParamInt_t.h"
#include "../core.h"

void SetupLuaClassGMaterialParamInt_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamInt_t>("MaterialParamInt_t")
        .addProperty("Value", &GMaterialParamInt_t::GetValue, &GMaterialParamInt_t::SetValue)
        .endClass();
}