#include "../../../core/scripting/generated/classes/GScriptInfo_t.h"
#include "../core.h"

void SetupLuaClassGScriptInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GScriptInfo_t>("ScriptInfo_t")
        .addProperty("Code", &GScriptInfo_t::GetCode, &GScriptInfo_t::SetCode)
        .addProperty("ParamsModified", &GScriptInfo_t::GetParamsModified, &GScriptInfo_t::SetParamsModified)
        .addProperty("ProxyReadParams", &GScriptInfo_t::GetProxyReadParams, &GScriptInfo_t::SetProxyReadParams)
        .addProperty("ProxyWriteParams", &GScriptInfo_t::GetProxyWriteParams, &GScriptInfo_t::SetProxyWriteParams)
        .addProperty("ScriptType", &GScriptInfo_t::GetScriptType, &GScriptInfo_t::SetScriptType)
        .endClass();
}