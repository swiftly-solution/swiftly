#include "../../core.h"

LoadScriptingComponent(
    menus,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginMenus>("Menus")
            .addFunction("Register", &PluginMenus::Register)
            .addFunction("RegisterTemporary", &PluginMenus::RegisterTemporary)
            .addFunction("Unregister", &PluginMenus::Unregister)
            .endClass()
            .addConstant("menus", new PluginMenus(FetchPluginName(state)));
    }
)