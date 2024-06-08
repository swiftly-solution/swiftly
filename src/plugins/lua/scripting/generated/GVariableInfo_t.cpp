#include "../../../core/scripting/generated/classes/GVariableInfo_t.h"
#include "../core.h"

void SetupLuaClassGVariableInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVariableInfo_t>("VariableInfo_t")
        .addProperty("Name", &GVariableInfo_t::GetName, &GVariableInfo_t::SetName)
        .addProperty("NameToken", &GVariableInfo_t::GetNameToken, &GVariableInfo_t::SetNameToken)
        .addProperty("Index", &GVariableInfo_t::GetIndex, &GVariableInfo_t::SetIndex)
        .addProperty("NumComponents", &GVariableInfo_t::GetNumComponents, &GVariableInfo_t::SetNumComponents)
        .addProperty("VarType", &GVariableInfo_t::GetVarType, &GVariableInfo_t::SetVarType)
        .addProperty("Access", &GVariableInfo_t::GetAccess, &GVariableInfo_t::SetAccess)
        .endClass();
}