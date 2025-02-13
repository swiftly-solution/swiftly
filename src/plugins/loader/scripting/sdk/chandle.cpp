#include "../../core.h"

LoadScriptingComponent(
    chandle,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginCHandle>("CHandle", state)
            .addConstructor<std::string>()
            .addFunction("GetPtr", &PluginCHandle::GetPtr)
            .addFunction("SetPtr", &PluginCHandle::SetPtr)
            .addFunction("GetHandlePtr", &PluginCHandle::GetHandlePtr)
        .endClass();
    }
)