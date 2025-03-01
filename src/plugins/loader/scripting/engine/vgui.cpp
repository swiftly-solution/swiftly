#include "../../core.h"

LoadScriptingComponent(
    vgui,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginVGUI>("VGUI", state)
            .addConstructor<std::string>()
            .addFunction("ShowText", &PluginVGUI::ShowText)
            .addFunction("RemoveText", &PluginVGUI::RemoveText)
            .addFunction("SetTextMessage", &PluginVGUI::SetTextMessage)
            .addFunction("SetTextPosition", &PluginVGUI::SetTextPosition)
        .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("vgui = VGUI(GetCurrentPluginName())");
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.vgui = VGUI(GetCurrentPluginName())");
    }
)