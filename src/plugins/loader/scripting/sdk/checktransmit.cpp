#include "../../core.h"

LoadScriptingComponent(
    checktransmit,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginCCheckTransmitInfo>("CCheckTransmitInfo", state)
            .addConstructor<EValue>()
            .addFunction("GetPlayers", &PluginCCheckTransmitInfo::GetPlayers)
            .addFunction("GetEntities", &PluginCCheckTransmitInfo::GetEntities)
            .addFunction("SetEntities", &PluginCCheckTransmitInfo::SetEntities)
        .endClass();
    }
)