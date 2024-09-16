#include "../core.h"

LoadLuaScriptingComponent(
    hooks,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginHooks>("Hooks")
            .addConstructor<void (*)(std::string)>()
            .addFunction("Add", &PluginHooks::AddHook)
            .addFunction("AddEntityOutputHook", &PluginHooks::AddEntityOutputHook)
            .addFunction("Call", &PluginHooks::CallHook)
            .endClass();

        luaL_dostring(state, "hooks = Hooks(GetCurrentPluginName())");
    }
)