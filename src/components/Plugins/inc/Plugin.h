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
#include <any>
#include <vector>
#include <string>

class Plugin;
void SetupLuaEnvironment(Plugin *plugin);

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
    "OnPlayerBlind",
    "OnPlayerFullUpdate",
    "OnItemPickup",
    "OnEnterBuyzone",
    "OnExitBuyzone",
    "OnRoundPostStart",
    "OnEnterBombzone",
    "OnPlayerTeam",
    "OnExitBombzone",
    "OnClientFullConnected",
    "OnPlayerFallDamage",
    "OnPlayerJump",
    "OnPlayerHurt",
    "ShouldHearVoice",
    "OnWeaponSpawned",
    "OnClientKeyStateChange",
};

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
        const int top = lua_gettop(m_l) - argc - 1;

        bool ok = (lua_pcall(m_l, argc, LUA_MULTRET, 0) == LUA_OK);
        if (!ok)
        {
            const char *err = lua_tostring(m_l, -1);
            lua_pop(m_l, 1);
            PRINTF("Runtime", "An error has occured while calling '%s'.\nError: %s\n", original_func_name.c_str(), err);
            return;
        }
    }

    template <typename T>
    T ExecuteWithReturn(std::string original_func_name, int argc)
    {
        const int top = lua_gettop(m_l) - argc - 1;

        bool ok = (lua_pcall(m_l, argc, LUA_MULTRET, 0) == LUA_OK);
        if (!ok)
        {
            const char *err = lua_tostring(m_l, -1);
            lua_pop(m_l, 1);
            PRINTF("Runtime", "An error has occured while calling '%s'.\nError: %s\n", original_func_name.c_str(), err);
            return (T) false;
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
        else if constexpr (std::is_same_v<T, luacpp::LuaObject>)
            return (T)returnObject;
        else
            return (T) false;
    }

    luacpp::LuaObject ExecuteWithReturnRaw(std::string original_func_name, int argc)
    {
        std::string err;

        const int top = lua_gettop(m_l) - argc - 1;

        bool ok = (lua_pcall(m_l, argc, LUA_MULTRET, 0) == LUA_OK);
        if (!ok)
        {
            err = lua_tostring(m_l, -1);
            lua_pop(m_l, 1);
            PRINTF("Runtime", "An error has occured while calling '%s'.\nError: %s\n", original_func_name.c_str(), err.c_str());
            return luacpp::LuaObject(m_l);
        }

        const int nresults = lua_gettop(m_l) - top;
        return luacpp::LuaObject(m_l, -nresults);
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

class Plugin
{
private:
    std::string m_pluginName;
    bool isPluginLoaded = false;
    PluginType_t pluginType;

    virtual void RegisterFunction(std::string function) = 0;
    virtual bool InternalLoadPlugin() = 0;

public:
    std::string err;
    std::string m_path;

    Plugin(std::string path, std::string name, PluginType_t pluginType) : m_path(path)
    {
        this->m_pluginName = name;
        this->pluginType = pluginType;
    }
    ~Plugin()
    {
        this->m_path.clear();
    }

    void LoadPlugin()
    {
        this->err.clear();

        if (!this->InternalLoadPlugin())
            return;

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

    virtual void *FetchCPPFunction(std::string function) = 0;
    virtual luacpp::LuaObject FetchLuaFunction(std::string function) = 0;

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

    virtual bool FunctionExists(std::string function) = 0;

    virtual luacpp::LuaState *GetLuaState() = 0;
    virtual lua_State *GetLuaRawState() = 0;
    virtual std::any ExecuteExport(std::string export_name, std::vector<std::any> data) = 0;
    virtual void RegisterExport(std::string export_name, void *functionPtr) = 0;
    virtual void UnregisterExport(std::string export_name) = 0;

    virtual void DestroyPluginEnvironment() = 0;
};

std::map<std::string, Plugin *> FetchPluginsMap();
void AddPluginInMap(Plugin *plugin);
bool ExistsPluginInMap(std::string plugin_name);
Plugin *FetchPluginFromMap(std::string plugin_name);

extern std::vector<Plugin *> plugins;

#endif
