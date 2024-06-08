#include "../../../core/scripting/generated/classes/GVecInputMaterialVariable_t.h"
#include "../core.h"

void SetupLuaClassGVecInputMaterialVariable_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVecInputMaterialVariable_t>("VecInputMaterialVariable_t")
        .addProperty("StrVariable", &GVecInputMaterialVariable_t::GetStrVariable, &GVecInputMaterialVariable_t::SetStrVariable)
        .endClass();
}