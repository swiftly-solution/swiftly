#ifndef _components_plugins_inc_plugin_h
#define _components_plugins_inc_plugin_h

#include "../../../common.h"
#include "../../../files/Files.h"
#include <luacpp/luacpp.h>
#include <map>
#include <vector>
#include <metamod_oslink.h>
#include <filesystem>
#include <algorithm>
#include <type_traits>

#ifndef _WIN32
#include <dlfcn.h>
#endif

class LuaFuncWrapper : public luacpp::LuaRefObject
{
public:
    LuaFuncWrapper(lua_State *l, int index) : LuaRefObject(l, index) {}
    LuaFuncWrapper(luacpp::LuaObject &&lobj) : LuaRefObject(std::move(lobj)) {}
    LuaFuncWrapper(const luacpp::LuaObject &lobj) : LuaRefObject(lobj) {}

    LuaFuncWrapper(LuaFuncWrapper &&) = default;
    LuaFuncWrapper(const LuaFuncWrapper &) = default;

    LuaFuncWrapper &operator=(LuaFuncWrapper &&) = default;
    LuaFuncWrapper &operator=(const LuaFuncWrapper &) = default;

    void ExecuteNoReturn(std::string original_func_name, int argc)
    {
        std::string err;

        const int top = lua_gettop(m_l) - argc - 1;

        bool ok = (lua_pcall(m_l, argc, LUA_MULTRET, 0) == LUA_OK);
        if (!ok)
        {
            err = lua_tostring(m_l, -1);
            lua_pop(m_l, 1);
            PRINTF("Runtime", "An error has occured while calling '%s'.\nError: %s\n", original_func_name.c_str(), err.c_str());
            return;
        }
    }

    template <typename T>
    T ExecuteWithReturn(std::string original_func_name, int argc)
    {
        std::string err;

        const int top = lua_gettop(m_l) - argc - 1;

        bool ok = (lua_pcall(m_l, argc, LUA_MULTRET, 0) == LUA_OK);
        if (!ok)
        {
            err = lua_tostring(m_l, -1);
            lua_pop(m_l, 1);
            PRINTF("Runtime", "An error has occured while calling '%s'.\nError: %s\n", original_func_name.c_str(), err.c_str());
            return nullptr;
        }

        const int nresults = lua_gettop(m_l) - top;
        luacpp::LuaObject returnObject(m_l, -nresults);

        if constexpr (std::is_same_v<T, const char *>)
            return returnObject.ToString();
        else if constexpr (std::is_same_v<T, std::string>)
            return std::string(returnObject.ToString());
        else if constexpr (std::is_same_v<T, int> || std::is_same_v<T, unsigned int> ||
                           std::is_same_v<T, short> || std::is_same_v<T, unsigned short> ||
                           std::is_same_v<T, long> || std::is_same_v<T, unsigned long> ||
                           std::is_same_v<T, long long> || std::is_same_v<T, unsigned long long>)
            return (T)returnObject.ToInteger();
        else if constexpr (std::is_same_v<T, bool>)
            return returnObject.ToBool();
        else if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>)
            return (T)returnObject.ToNumber();
        else
            return nullptr;
    }

    void PrepForExec()
    {
        PushSelf();
    }

    lua_State *GetML()
    {
        return this->m_l;
    }
};

const std::vector<std::string> funcsToLoad = {
    "RegisterPlayer",
    "UnregisterPlayer",
    "OnProgramLoad",
    "OnPluginStart",
    "OnPluginStop",
    "OnClientConnect",
    "OnClientDisconnect",
    "OnPlayerSpawn",
    "OnGameTick",
    "OnPlayerChat",
    "OnRoundStart",
    "OnRoundPrestart",
    "OnRoundEnd",
    "BombBeginPlant",
    "BombAbortPlant",
    "BombPlanted",
    "BombBeginDefuse",
    "BombAbortDefuse",
    "BombDefused",
    "BombExploded",
    "BombDropped",
    "BombPickup",
    "OnMapLoad",
    "OnMapUnload",
    "OnClientGameMessage",
    "OnPlayerDeath",
    "OnPlayerHurt",
    "ShouldHearVoice",
};

class Plugin
{
private:
    std::string m_path;
    std::map<std::string, void *> cppFunctions;
    std::map<std::string, luacpp::LuaObject> luaFunctions;
    HINSTANCE m_hModule;
    std::string m_pluginName;
    bool isPluginLoaded = false;
    PluginType_t pluginType;
    luacpp::LuaState *luaState;
    lua_State *rawLuaState;

    void RegisterFunction(std::string function)
    {

        if (this->GetPluginType() == PluginType_t::PLUGIN_CPP)
        {
            if (this->cppFunctions.find(function) != this->cppFunctions.end())
                return;
            void *func = reinterpret_cast<void *>(dlsym(this->m_hModule, function.c_str()));
            if (func == nullptr)
                return;

            this->cppFunctions.insert(std::make_pair(function, func));
        }
        else if (this->GetPluginType() == PluginType_t::PLUGIN_LUA)
        {
            if (this->luaState)
            {
                luacpp::LuaObject obj = this->luaState->Get(function.c_str());

                if (obj.GetType() == LUA_TFUNCTION)
                    this->luaFunctions.insert(std::make_pair(function, obj));
            }
        }
    }

public:
    Plugin(std::string path, std::string name, PluginType_t pluginType) : m_path(path)
    {
        this->m_pluginName = name;
        this->pluginType = pluginType;
    }
    ~Plugin()
    {
        this->m_path.clear();
        dlclose(this->m_hModule);
    }

    void LoadPlugin()
    {
        if (this->GetPluginType() == PluginType_t::PLUGIN_CPP)
        {
#ifdef _WIN32
            this->m_hModule = dlmount(this->m_path.c_str());
#else
            this->m_hModule = dlopen(string_format("%s/%s", std::filesystem::current_path().string().c_str(), this->m_path.c_str()).c_str(), RTLD_NOW);

            if (!this->m_hModule)
            {
                PRINTF("LoadPlugin", "Failed to load module: %s\n", std::string(dlerror()).c_str());
                return;
            }
#endif
        }
        else if (this->GetPluginType() == PluginType_t::PLUGIN_LUA)
        {
            this->rawLuaState = luaL_newstate();
            this->luaState = new luacpp::LuaState(this->rawLuaState, true);

            std::vector<std::string> files = Files::FetchFileNames(this->m_path);
            for (std::string file : files)
            {
                std::string errstr;
                if (!this->luaState->DoFile(file.c_str(), &errstr, nullptr))
                    PRINTF("LoadPlugin", "Failed to load plugin file '%s'\nError: %s\n", file.c_str(), errstr.c_str());
            }
        }

        for (std::string func : funcsToLoad)
            this->RegisterFunction("Internal_" + func);

        this->RegisterFunction("GetPluginAuthor");
        this->RegisterFunction("GetPluginVersion");
        this->RegisterFunction("GetPluginName");
        this->RegisterFunction("GetPluginWebsite");
    }

    void StartPlugin();
    void StopPlugin();
    inline void SetPluginLoaded(bool loaded) { this->isPluginLoaded = loaded; };
    inline bool IsPluginLoaded() { return this->isPluginLoaded; }
    std::string GetName() { return this->m_pluginName; }
    PluginType_t GetPluginType() { return this->pluginType; }
    void SetPluginType(PluginType_t plType) { this->pluginType = plType; }

    void *FetchCPPFunction(std::string function)
    {
        if (this->cppFunctions.find(function) == this->cppFunctions.end())
            return nullptr;

        return this->cppFunctions.at(function);
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

        if (this->GetPluginType() == PluginType_t::PLUGIN_CPP)
        {
            void *ptr = this->FetchCPPFunction(function);
            if (ptr)
                reinterpret_cast<T>(ptr)(args...);
        }
        else if (this->GetPluginType() == PluginType_t::PLUGIN_LUA)
        {
            luacpp::LuaObject func = this->FetchLuaFunction(function);

            LuaFuncWrapper wrapper(func);
            wrapper.PrepForExec();
            luacpp::PushValues(wrapper.GetML(), std::forward<Args>(args)...);
            wrapper.ExecuteNoReturn(original_func, sizeof...(Args));
        }
    }

    template <typename Ret, typename T, typename... Args>
    Ret ExecuteFunctionWithReturn(std::string function, Args &&...args)
    {
        std::string original_func = function;
        if (!this->FunctionExists(function))
            return (Ret) false;

        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        if (this->GetPluginType() == PluginType_t::PLUGIN_CPP)
        {
            void *ptr = this->FetchCPPFunction(function);
            return (Ret) reinterpret_cast<T>(ptr)(args...);
        }
        else if (this->GetPluginType() == PluginType_t::PLUGIN_LUA)
        {
            luacpp::LuaObject func = this->FetchLuaFunction(function);

            LuaFuncWrapper wrapper(func);
            wrapper.PrepForExec();
            luacpp::PushValues(wrapper.GetML(), std::forward<Args>(args)...);
            return wrapper.ExecuteWithReturn<Ret>(original_func, sizeof...(Args));
        }
        else
            return (Ret) false;
    }

    bool FunctionExists(std::string function)
    {
        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        if (this->GetPluginType() == PluginType_t::PLUGIN_CPP)
            return (this->cppFunctions.find(function) != this->cppFunctions.end());
        if (this->GetPluginType() == PluginType_t::PLUGIN_LUA)
            return (this->luaFunctions.find(function) != this->luaFunctions.end());
        else
            return false;
    }

    luacpp::LuaState *GetLuaState() { return this->luaState; }
    lua_State *GetLuaRawState() { return this->rawLuaState; }
};

std::map<std::string, Plugin *> FetchPluginsMap();
void AddPluginInMap(Plugin *plugin);
bool ExistsPluginInMap(std::string plugin_name);
Plugin *FetchPluginFromMap(std::string plugin_name);

extern std::vector<Plugin *> plugins;

#endif