#include "../../../core/scripting/generated/classes/GCompMatMutatorCondition_t.h"
#include "../core.h"

void SetupLuaClassGCompMatMutatorCondition_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompMatMutatorCondition_t>("CompMatMutatorCondition_t")
        .addProperty("MutatorCondition", &GCompMatMutatorCondition_t::GetMutatorCondition, &GCompMatMutatorCondition_t::SetMutatorCondition)
        .addProperty("StrMutatorConditionContainerName", &GCompMatMutatorCondition_t::GetStrMutatorConditionContainerName, &GCompMatMutatorCondition_t::SetStrMutatorConditionContainerName)
        .addProperty("StrMutatorConditionContainerVarName", &GCompMatMutatorCondition_t::GetStrMutatorConditionContainerVarName, &GCompMatMutatorCondition_t::SetStrMutatorConditionContainerVarName)
        .addProperty("StrMutatorConditionContainerVarValue", &GCompMatMutatorCondition_t::GetStrMutatorConditionContainerVarValue, &GCompMatMutatorCondition_t::SetStrMutatorConditionContainerVarValue)
        .addProperty("PassWhenTrue", &GCompMatMutatorCondition_t::GetPassWhenTrue, &GCompMatMutatorCondition_t::SetPassWhenTrue)
        .endClass();
}