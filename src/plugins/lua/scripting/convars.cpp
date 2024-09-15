#include "core.h"

void SetupLuaConvars(LuaPlugin* plugin, lua_State* state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginConvars>("ConVars")
        .addConstructor<void (*)(std::string)>()
        .addFunction("CreateFake", &PluginConvars::CreateFakeLua)
        .addFunction("DeleteFake", &PluginConvars::DeleteFake)
        .addFunction("Get", &PluginConvars::GetConvarValueLua)
        .addFunction("GetType", &PluginConvars::GetConvarType)
        .addFunction("Set", &PluginConvars::SetConvar)
        .addFunction("Exists", &PluginConvars::Exists)
        .addFunction("ExistsFake", &PluginConvars::ExistsFake)
        .endClass();

    luaL_dostring(state, "convar = ConVars(GetCurrentPluginName())");
}