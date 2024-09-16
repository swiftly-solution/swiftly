#include "../core.h"

LoadLuaScriptingComponent(
    menus,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginMenus>("Menus")
            .addConstructor<void (*)(std::string)>()
            .addFunction("Register", &PluginMenus::Register)
            .addFunction("RegisterTemporary", &PluginMenus::RegisterTemporary)
            .addFunction("Unregister", &PluginMenus::Unregister)
            .endClass();

        luaL_dostring(state, "menus = Menus(GetCurrentPluginName())");
    }
)