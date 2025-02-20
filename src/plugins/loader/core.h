#pragma once

#include "../Plugin.h"
#include "../core/scripting.h"
#include "../../entrypoint.h"
#include "../../types/EventResult.h"

std::string FetchPluginName(EContext* state);
#define FetchPluginByState(state) g_pluginManager->FetchPlugin(FetchPluginName(state))
#define LoadScriptingComponent(component_name, component_func) ClassLoader sc_##component_name(component_func);

class ClassLoader;
extern std::vector<ClassLoader*> loaderClasses;

class ClassLoader
{
private:
    std::function<void(Plugin*, EContext*)> m_loadFunction;
public:
    ClassLoader(std::function<void(Plugin*, EContext*)> loadFunction): m_loadFunction(loadFunction) {
        loaderClasses.push_back(this);
    }

    void ExecuteLoad(Plugin* plugin, EContext* state)
    {
        m_loadFunction(plugin, state);
    }
};