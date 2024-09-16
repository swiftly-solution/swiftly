#include "../core.h"

LoadLuaScriptingComponent(
    chandle,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginCHandle>("CHandle")
            .addConstructor<void(*)(std::string)>()
            .addFunction("GetPtr", &PluginCHandle::GetPtr)
            .addFunction("SetPtr", &PluginCHandle::SetPtr)
            .addFunction("GetHandlePtr", &PluginCHandle::GetHandlePtr)
            .endClass();
    }
)