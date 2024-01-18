#ifndef _cpp_plugin_h
#define _cpp_plugin_h

#include "../Plugin.h"

#ifndef _WIN32
#include <dlfcn.h>
#endif

class CPPPlugin : public Plugin
{
private:
    std::map<std::string, void *> cppFunctions;
    HINSTANCE m_hModule;

    void RegisterFunction(std::string function)
    {
        if (this->cppFunctions.find(function) != this->cppFunctions.end())
            return;
        void *func = reinterpret_cast<void *>(dlsym(this->m_hModule, function.c_str()));
        if (func == nullptr)
            return;

        this->cppFunctions.insert(std::make_pair(function, func));
    }

    bool InternalLoadPlugin()
    {
#ifdef _WIN32
        this->m_hModule = dlmount(this->m_path.c_str());
#else
        this->m_hModule = dlopen(string_format("%s/%s", std::filesystem::current_path().string().c_str(), this->m_path.c_str()).c_str(), RTLD_NOW);

        if (!this->m_hModule)
        {
            PRINTF("LoadPlugin", "Failed to load module: %s\n", std::string(dlerror()).c_str());
            this->err = std::string(dlerror()).c_str();
            return false;
        }
#endif

        return true;
    }

public:
    CPPPlugin(std::string path, std::string name, PluginType_t pluginType) : Plugin(path, name, pluginType) {}

    bool FunctionExists(std::string function)
    {
        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        return (this->cppFunctions.find(function) != this->cppFunctions.end());
    }

    void *FetchCPPFunction(std::string function)
    {
        if (this->cppFunctions.find(function) == this->cppFunctions.end())
            return nullptr;

        return this->cppFunctions.at(function);
    }

    template <typename T, typename... Args>
    void ExecuteFunction(std::string function, Args &&...args)
    {
        std::string original_func = function;
        if (!this->FunctionExists(function))
            return;

        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        void *ptr = this->FetchCPPFunction(function);
        if (ptr)
            reinterpret_cast<T>(ptr)(args...);
    }

    template <typename Ret, typename T, typename... Args>
    Ret ExecuteFunctionWithReturn(std::string function, Args &&...args)
    {
        std::string original_func = function;
        if (!this->FunctionExists(function))
            return (Ret) false;

        if (std::find(funcsToLoad.begin(), funcsToLoad.end(), function) != funcsToLoad.end())
            function = "Internal_" + function;

        void *ptr = this->FetchCPPFunction(function);
        return (Ret) reinterpret_cast<T>(ptr)(args...);
    }

    luacpp::LuaObject FetchLuaFunction(std::string function)
    {
        return luacpp::LuaObject(nullptr);
    }

    luacpp::LuaState *GetLuaState() { return nullptr; }
    lua_State *GetLuaRawState() { return nullptr; }

    void DestroyPluginEnvironment()
    {
        dlclose(this->m_hModule);
        this->cppFunctions.clear();
    }
};

#endif