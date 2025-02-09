#include "../../core.h"

LoadScriptingComponent(
    checktransmit,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginCCheckTransmitInfo>("CCheckTransmitInfo")
            .addConstructor<EValue>()
            .addFunction("GetPlayers", &PluginCCheckTransmitInfo::GetPlayers)
            .addFunction("GetEntities", &PluginCCheckTransmitInfo::GetEntities)
            .addFunction("SetEntities", &PluginCCheckTransmitInfo::SetEntities)
            .endClass();
    }
)