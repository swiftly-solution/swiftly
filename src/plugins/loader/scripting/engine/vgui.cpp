#include "../../core.h"

LoadScriptingComponent(
    vgui,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginVGUI>("VGUI")
            .addFunction("ShowText", &PluginVGUI::ShowText)
            .addFunction("RemoveText", &PluginVGUI::RemoveText)
            .addFunction("SetTextMessage", &PluginVGUI::SetTextMessage)
            .addFunction("SetTextPosition", &PluginVGUI::SetTextPosition)
            .endClass()
            .addConstant("vgui", new PluginVGUI(FetchPluginName(state)));
    }
)