#include "../../../common.h"
#include "../../inc/Scripting.h"
#include <vector>
#include <string>

std::vector<std::string> print_colors = {
    "{DEFAULT}",
    "{WHITE}",
    "{DARKRED}",
    "{LIGHTPURPLE}",
    "{GREEN}",
    "{OLIVE}",
    "{LIME}",
    "{RED}",
    "{GRAY}",
    "{GREY}",
    "{LIGHTYELLOW}",
    "{YELLOW}",
    "{SILVER}",
    "{BLUEGREY}",
    "{LIGHTBLUE}",
    "{BLUE}",
    "{DARKBLUE}",
    "{PURPLE}",
    "{MAGENTA}",
    "{LIGHTRED}",
    "{GOLD}",
    "{ORANGE}",
};

SMM_API void scripting_Print(const char *str)
{
    if (!g_SMAPI)
        return;

    std::string message(str);
    if (message.size() != 0)
    {
        for (size_t i = 0; i < print_colors.size(); i++)
        {
            message = replace(message, print_colors.at(i), "");
            message = replace(message, str_tolower(print_colors.at(i)), "");
        }
        g_SMAPI->ConPrint(message.c_str());
    }
}

SMM_API PluginState scripting_GetPluginState(const char *plugin_name)
{
    if (plugin_name == nullptr)
        return PluginState::STOPPED;

    Plugin *plugin = FetchPluginFromMap(plugin_name);
    if (plugin == nullptr)
        return PluginState::STOPPED;

    if (plugin->IsPluginLoaded())
        return PluginState::STARTED;
    else
        return PluginState::STOPPED;
}