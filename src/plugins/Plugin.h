#ifndef _plugins_plugin_h
#define _plugins_plugin_h

#include <string>
#include <vector>
#include "../types/PluginKind.h"
#include "../types/PluginState.h"

class Plugin
{
private:
    std::string name;
    PluginKind_t kind;
    PluginState_t state = PluginState_t::Stopped;
    std::string loadError = "";

public:
    Plugin(std::string m_name, PluginKind_t m_kind);
    ~Plugin();

    std::string GetName();
    PluginKind_t GetKind();

    PluginState_t GetPluginState();
    void SetPluginState(PluginState_t state);

    std::string GetLoadError();
    void SetLoadError(std::string error);

    virtual bool LoadScriptingEnvironment() = 0;
    virtual void DestroyScriptingEnvironment() = 0;
    virtual bool ExecuteStart() = 0;
    virtual void ExecuteStop() = 0;

    virtual void ExecuteCommand(void *functionPtr, std::string name, int slot, std::vector<std::string> args, bool silent) = 0;
};

#endif