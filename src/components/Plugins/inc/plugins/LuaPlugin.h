#ifndef _lua_plugin_h
#define _lua_plugin_h

#include <luacpp/luacpp.h>

#include "../Plugin.h"

extern std::map<std::string, std::map<std::string, std::vector<luacpp::LuaObject>>> lua_game_events;

extern "C"
{
    LUALIB_API int luaopen_rapidjson(lua_State *L);
}

static const luaL_Reg lualibs[] = {
    {"_G", luaopen_base},
    {LUA_TABLIBNAME, luaopen_table},
    {LUA_STRLIBNAME, luaopen_string},
    {LUA_MATHLIBNAME, luaopen_math},
    {LUA_DBLIBNAME, luaopen_debug},
    {LUA_COLIBNAME, luaopen_coroutine},
    {LUA_UTF8LIBNAME, luaopen_utf8},
    {LUA_IOLIBNAME, luaopen_io},
    {LUA_OSLIBNAME, luaopen_os},
    {"json", luaopen_rapidjson},
    {NULL, NULL},
};

class LuaPlugin : public Plugin
{
private:
    luacpp::LuaState *luaState;
    lua_State *rawLuaState;
    std::map<std::string, luacpp::LuaObject> luaFunctions;

    void RegisterFunction(std::string function)
    {
        if (this->luaState)
        {
            luacpp::LuaObject obj = this->luaState->Get(function.c_str());

            if (obj.GetType() == LUA_TFUNCTION)
                this->luaFunctions.insert(std::make_pair(function, obj));
        }
    }

    bool InternalLoadPlugin()
    {
        this->rawLuaState = luaL_newstate();
        const luaL_Reg *lib = lualibs;
        for (; lib->func; lib++)
        {
            luaL_requiref(this->rawLuaState, lib->name, lib->func, 1);
            lua_pop(this->rawLuaState, 1);
        }

        this->luaState = new luacpp::LuaState(this->rawLuaState, false);

        std::vector<std::string> files = Files::FetchFileNames(this->m_path);
        SetupLuaEnvironment(this);
        for (std::string file : files)
        {
            std::string errstr;
            if (!this->luaState->DoFile(file.c_str(), &errstr, nullptr))
            {
                PRINTF("LoadPlugin", "Failed to load plugin file '%s'\nError: %s\n", file.c_str(), errstr.c_str());
                this->StopPlugin();
                return false;
            }
        }

        this->luaState->DoString("events:on(\"OnPlayerSpawn\", function(playerID) GetPlayer(playerID):SetFirstSpawn(true) end)");
        return true;
    }

public:
    LuaPlugin(std::string path, std::string name, PluginType_t pluginType) : Plugin(path, name, pluginType) {}

    bool FunctionExists(std::string function)
    {
        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        return (this->luaFunctions.find(function) != this->luaFunctions.end());
    }

    luacpp::LuaObject FetchLuaFunction(std::string function)
    {
        return this->luaFunctions.at(function);
    }

    template <typename T, typename... Args>
    void ExecuteFunction(std::string function, Args &&...args)
    {
        std::string original_func = function;
        if (!this->FunctionExists(function))
            return;

        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        luacpp::LuaObject func = this->FetchLuaFunction(function);

        LuaFuncWrapper wrapper(func);
        wrapper.PrepForExec();
        luacpp::PushValues(wrapper.GetML(), std::forward<Args>(args)...);
        wrapper.ExecuteNoReturn(original_func, sizeof...(Args));
    }

    template <typename Ret, typename T, typename... Args>
    Ret ExecuteFunctionWithReturn(std::string function, Args &&...args)
    {
        std::string original_func = function;
        if (!this->FunctionExists(function))
            return (Ret) false;

        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        luacpp::LuaObject func = this->FetchLuaFunction(function);

        LuaFuncWrapper wrapper(func);
        wrapper.PrepForExec();
        luacpp::PushValues(wrapper.GetML(), std::forward<Args>(args)...);
        return wrapper.ExecuteWithReturn<Ret>(original_func, sizeof...(Args));
    }

    luacpp::LuaState *GetLuaState() { return this->luaState; }
    lua_State *GetLuaRawState() { return this->rawLuaState; }

    void *FetchCPPFunction(std::string function) { return nullptr; }

    void DestroyPluginEnvironment()
    {
        this->luaFunctions.clear();
        if (lua_game_events.find(this->GetName()) != lua_game_events.end())
            lua_game_events.erase(this->GetName());
    }
};

#endif