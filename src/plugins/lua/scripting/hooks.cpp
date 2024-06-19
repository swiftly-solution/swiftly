#include "core.h"

void SetupLuaHooks(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<PluginHooks>("Hooks")
        .addConstructor<void (*)(std::string)>()

        .addFunction("Add", &PluginHooks::AddHook)

        .endClass();

    luaL_dostring(state, "hooks = Hooks(GetCurrentPluginName())");
}