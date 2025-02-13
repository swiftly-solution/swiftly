#include "../../core.h"

LoadScriptingComponent(
    menus,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginMenus>("Menus", state)
            .addConstructor<std::string>()
            .addFunction("Register", &PluginMenus::Register)
            .addFunction("RegisterTemporary", &PluginMenus::RegisterTemporary)
            .addFunction("Unregister", &PluginMenus::Unregister)
        .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("menus = Menus(GetCurrentPluginName())");  
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.menus = Menus(GetCurrentPluginName())");
    }
)