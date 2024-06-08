#include "../../../core/scripting/generated/classes/GFunctionInfo_t.h"
#include "../core.h"

void SetupLuaClassGFunctionInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFunctionInfo_t>("FunctionInfo_t")
        .addProperty("Name", &GFunctionInfo_t::GetName, &GFunctionInfo_t::SetName)
        .addProperty("NameToken", &GFunctionInfo_t::GetNameToken, &GFunctionInfo_t::SetNameToken)
        .addProperty("ParamCount", &GFunctionInfo_t::GetParamCount, &GFunctionInfo_t::SetParamCount)
        .addProperty("Index", &GFunctionInfo_t::GetIndex, &GFunctionInfo_t::SetIndex)
        .addProperty("IsPure", &GFunctionInfo_t::GetIsPure, &GFunctionInfo_t::SetIsPure)
        .endClass();
}