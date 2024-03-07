#include "../../../../common.h"
#include "../../../../menus/Menus.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

SMM_API void scripting_Menus_Register(const char *plugin_name, const char *id, const char *title, const char *color, const char *items)
{
    if (id == nullptr || title == nullptr || color == nullptr || items == nullptr || plugin_name == nullptr)
        return;

    std::vector<std::pair<std::string, std::string>> options;

    rapidjson::Document document;
    document.Parse(items);
    if (document.HasParseError())
        return;

    for (uint32 i = 0; i < document.Size(); i++)
        if (document[i].Size() == 2)
            options.push_back({document[i][0].GetString(), document[i][1].GetString()});

    if (options.size() == 0)
        return;

    g_menus->RegisterMenu(plugin_name, id, title, color, options);
}

SMM_API void scripting_Menus_Unregister(const char *plugin_name, const char *id)
{
    if (id == nullptr || plugin_name == nullptr)
        return;

    g_menus->UnregisterMenu(plugin_name, id);
}