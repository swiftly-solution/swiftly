#include "../../core.h"

std::string FetchTranslation(std::string key, std::optional<int> playerid)
{
    return scripting_FetchTranslation(key, playerid.value_or(-1));
}

LoadScriptingComponent(
    translation,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .addFunction("FetchTranslation", FetchTranslation);
    }
)