#include "../../core.h"

LoadScriptingComponent(
    chandle,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginCHandle>("CHandle")
            .addConstructor<std::string>()
            .addFunction("GetPtr", &PluginCHandle::GetPtr)
            .addFunction("SetPtr", &PluginCHandle::SetPtr)
            .addFunction("GetHandlePtr", &PluginCHandle::GetHandlePtr)
            .endClass();
    }
)