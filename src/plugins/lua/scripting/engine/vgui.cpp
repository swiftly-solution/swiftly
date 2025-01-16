#include "../core.h"

LoadLuaScriptingComponent(
    vgui,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginVGUI>("VGUI")
            .addConstructor<void (*)(std::string)>()
            .addFunction("ShowText", &PluginVGUI::ShowText)
            .addFunction("RemoveText", &PluginVGUI::RemoveText)
            .addFunction("SetTextMessage", &PluginVGUI::SetTextMessage)
            .addFunction("SetTextPosition", &PluginVGUI::SetTextPosition)
            .addFunction("ShowPanel", &PluginVGUI::ShowPanel)
            .addFunction("RemovePanel", &PluginVGUI::RemovePanel)
            .addFunction("SetPanelMessage", &PluginVGUI::SetPanelMessage)
            .addFunction("SetPanelPosition", &PluginVGUI::SetPanelPosition)
            .endClass();

        luaL_dostring(state, "vgui = VGUI(GetCurrentPluginName())");
    }
)