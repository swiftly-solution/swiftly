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
            .addFunction("SetMessage", &PluginVGUI::SetMessage)
            .addFunction("SetPosition", &PluginVGUI::SetPosition)
            .endClass();

        luaL_dostring(state, "vgui = VGUI(GetCurrentPluginName())");
    }
)