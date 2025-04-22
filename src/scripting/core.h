#ifndef _scripting_core_h
#define _scripting_core_h

#include <core/entrypoint.h>
#include <plugins/manager.h>
#include <embedder/src/Embedder.h>

#include <functional>
#include "stack.h"

std::string FetchPluginName(EContext* ctx);
#define FetchPluginByState(state) g_pluginManager.FetchPlugin(FetchPluginName(state))
#define LoadScriptingComponent(component_name, component_func) ClassLoader sc_##component_name(component_func);

void SetupScriptingEnvironment(PluginObject plugin, EContext* ctx);

class ClassLoader;
extern std::vector<ClassLoader*> loaderClasses;

class ClassLoader
{
private:
    std::function<void(PluginObject, EContext*)> m_loadFunction;
public:
    ClassLoader(std::function<void(PluginObject, EContext*)> loadFunction) : m_loadFunction(loadFunction) {
        loaderClasses.push_back(this);
    }

    void ExecuteLoad(PluginObject plugin, EContext* state)
    {
        m_loadFunction(plugin, state);
    }
};

EValue MakeSDKClassInstance(std::string className, void* ptr, EContext* context);

#endif