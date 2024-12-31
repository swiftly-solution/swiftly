#include "../core.h"

LoadLuaScriptingComponent(
    convars,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginConvars>("ConVars")
            .addConstructor<void (*)(std::string)>()
            .addFunction("CreateFake", &PluginConvars::CreateFake)
            .addFunction("DeleteFake", &PluginConvars::DeleteFake)
            .addFunction("Get", &PluginConvars::GetConvarValue)
            .addFunction("GetType", &PluginConvars::GetConvarType)
            .addFunction("Set", &PluginConvars::SetConvar)
            .addFunction("Exists", &PluginConvars::Exists)
            .addFunction("ExistsFake", &PluginConvars::ExistsFake)
            .addFunction("AddFlags", &PluginConvars::AddFlags)
            .addFunction("RemoveFlags", &PluginConvars::RemoveFlags)
            .addFunction("GetFlags", &PluginConvars::GetFlags)
            .addFunction("HasFlags", &PluginConvars::HasFlags)
            .endClass();

        luaL_dostring(state, "convar = ConVars(GetCurrentPluginName())");
    }
)