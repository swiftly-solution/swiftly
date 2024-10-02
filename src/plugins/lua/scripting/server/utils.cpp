#include "../core.h"
#include <functional>

void RegisterTimeout(int64_t delay, std::function<void()> cb);

void scripting_AddTimeout(int64_t delay, luabridge::LuaRef callback)
{
    if(!callback.isFunction()) return;
    luabridge::LuaRef* cb = new luabridge::LuaRef(callback);

    RegisterTimeout(delay, [cb]() -> void {
        if(!cb->isFunction()) {
            delete cb;
            return;
        }

        try {
            cb->operator()();
        }
        catch (luabridge::LuaException& e)
        {
            PRINTF("An error has occured while trying to execute the timeout callback: %s\n", e.what());
        }
        delete cb;
    });
}

LoadLuaScriptingComponent(
    utils,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .addFunction("AddTimeout", scripting_AddTimeout)
            .addFunction("GetPluginPath", scripting_GetPluginPath)
            .addFunction("GetTime", GetTime)
            .addFunction("IsWindows", scripting_IsWindows)
            .addFunction("IsLinux", scripting_IsLinux)
            .addFunction("GetOS", scripting_GetOS)
            .addFunction("StateUpdate", scripting_StateUpdate)
            .addFunction("GetUserMessage", scripting_GetUserMessage)
            .addFunction("GetPluginState", scripting_GetPluginState)
            .addFunction("GetCCSGameRules", scripting_GetCCSGameRules)
            .addFunction("CreateTextTable", scripting_CreateTextTable);
    }
)