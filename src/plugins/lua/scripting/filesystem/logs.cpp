#include "../core.h"

LoadLuaScriptingComponent(
    logger,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginLogger>("Logger")
            .addConstructor<void (*)(std::string)>()
            .addFunction("Write", &PluginLogger::Write)
            .endClass();

        luaL_dostring(state, "logger = Logger(GetCurrentPluginName())");
    }
)