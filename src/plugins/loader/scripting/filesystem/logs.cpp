#include "../../core.h"

LoadScriptingComponent(
    logger,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginLogger>("Logger", state)
            .addConstructor<std::string>()
            .addFunction("Write", &PluginLogger::Write)
        .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("logger = Logger(GetCurrentPluginName())");
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.logger = Logger(GetCurrentPluginName())");
    }
)