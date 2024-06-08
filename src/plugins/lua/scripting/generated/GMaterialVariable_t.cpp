#include "../../../core/scripting/generated/classes/GMaterialVariable_t.h"
#include "../core.h"

void SetupLuaClassGMaterialVariable_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialVariable_t>("MaterialVariable_t")
        .addProperty("StrVariable", &GMaterialVariable_t::GetStrVariable, &GMaterialVariable_t::SetStrVariable)
        .addProperty("VariableField", &GMaterialVariable_t::GetVariableField, &GMaterialVariable_t::SetVariableField)
        .addProperty("Scale", &GMaterialVariable_t::GetScale, &GMaterialVariable_t::SetScale)
        .endClass();
}