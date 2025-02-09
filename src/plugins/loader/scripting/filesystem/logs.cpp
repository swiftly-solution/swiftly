#include "../../core.h"

LoadScriptingComponent(
    logger,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginLogger>("Logger")
            .addFunction("Write", &PluginLogger::Write)
            .endClass()
            .addConstant("logger", new PluginLogger(FetchPluginName(state)));
    }
)