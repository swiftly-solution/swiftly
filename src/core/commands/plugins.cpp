#include "commands.h"

#include <plugins/manager.h>

void ShowSwiftlyPluginManagerHelp(CPlayerSlot slot)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Plugin Management Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: sw plugins <command> [plugin_name]\n");
    PrintToClientOrConsole(slot, "Commands", " info     - Shows informations about a plugin\n");
    PrintToClientOrConsole(slot, "Commands", " list     - Shows loaded plugins\n");
    PrintToClientOrConsole(slot, "Commands", " load     - Loads a plugin\n");
    PrintToClientOrConsole(slot, "Commands", " reload   - Reloads a plugin if it was loaded\n");
    PrintToClientOrConsole(slot, "Commands", " unload   - Unloads a plugin if it was loaded\n");
    PrintToClientOrConsole(slot, "Commands", " refresh  - Refreshes the plugin list.\n");
}

void SwiftlyPluginManagerList(CPlayerSlot slot)
{
    uint32 loadedPlugins = 0;
    auto plugins = g_pluginManager.GetPluginsList();
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        auto plugin = plugins[i];
        if (plugin == nullptr)
            continue;
        if (plugin->GetPluginState() == PluginState_t::Stopped)
            continue;

        ++loadedPlugins;
    }

    if (loadedPlugins == 0)
        return PrintToClientOrConsole(slot, "Plugins List", "There are no plugins loaded.\n");

    PrintToClientOrConsole(slot, "Plugins List", "Showing below %02d plugins loaded:\n", loadedPlugins);
    uint32 showingIdx = 0;
    std::vector<std::string> errors;
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        auto plugin = plugins[i];
        if (plugin == nullptr)
            continue;
        if (plugin->GetLoadError().size() > 0)
            errors.push_back(string_format("Plugin '%s': %s", plugin->GetName().c_str(), plugin->GetLoadError().c_str()));
        if (plugin->GetPluginState() == PluginState_t::Stopped)
            continue;

        ++showingIdx;

        auto website = plugin->GetWebsite();

        PrintToClientOrConsole(slot, "Plugins List", "%02d. \"%s\" (%s) by %s%s\n",
            showingIdx,
            plugin->GetPlName().c_str(),
            plugin->GetVersion().c_str(),
            plugin->GetAuthor().c_str(),
            website == "" ? "" : string_format(" ( %s )", website.c_str()).c_str());
    }
    if (errors.size() && slot.Get() == -1)
    {
        PrintToClientOrConsole(slot, "Plugins List", "Plugin load errors:\n");
        for (const std::string err : errors)
            PrintToClientOrConsole(slot, "Plugins List", "%s\n", err.c_str());

        errors.clear();
    }
}

void SwiftlyPluginManagerInfo(CPlayerSlot slot, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins info <plugin_name>\n");

    if (!g_pluginManager.PluginExists(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Info", "Invalid plugin name.\n");

    auto plugin = g_pluginManager.FetchPlugin(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Stopped)
        return PrintToClientOrConsole(slot, "Plugin Info", "Plugin is not loaded.\n");

    std::string website = plugin->GetWebsite();

    PrintToClientOrConsole(slot, "Plugin Info", "Plugin File Name: %s\n", plugin->GetName().c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "Name: %s\n", plugin->GetPlName().c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "Author: %s\n", plugin->GetAuthor().c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "Version: %s\n", plugin->GetVersion().c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "URL: %s\n", website == "" ? "Not Present" : website.c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "Memory Usage: %.4fMB\n", double(plugin->GetMemoryUsage()) / 1024.0f / 1024.0f);
}

void SwiftlyPluginManagerUnload(CPlayerSlot slot, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins unload <plugin_name>\n");

    if (!g_pluginManager.PluginExists(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Unload", "Invalid plugin name.\n");

    auto plugin = g_pluginManager.FetchPlugin(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Stopped)
        return PrintToClientOrConsole(slot, "Plugin Unload", "Plugin is not loaded.\n");

    g_pluginManager.StopPlugin(plugin_name, true);
    PrintToClientOrConsole(slot, "Plugin Unload", "Plugin '%s' has been unloaded.\n", plugin_name.c_str());
}

void SwiftlyPluginManagerLoad(CPlayerSlot slot, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins load <plugin_name>\n");

    if (!g_pluginManager.PluginExists(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Load", "Invalid plugin name.\n");

    auto plugin = g_pluginManager.FetchPlugin(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Started)
        return PrintToClientOrConsole(slot, "Plugin Load", "Plugin is already loaded.\n");

    g_pluginManager.LoadPlugin(plugin_name);
    g_pluginManager.StartPlugin(plugin_name);
    PrintToClientOrConsole(slot, "Plugin Load", "Plugin '%s' has been loaded.\n", plugin_name.c_str());
}

void SwiftlyPluginManagerReload(CPlayerSlot slot, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins reload <plugin_name>\n");

    if (!g_pluginManager.PluginExists(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Reload", "Invalid plugin name.\n");

    auto plugin = g_pluginManager.FetchPlugin(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Stopped)
        return PrintToClientOrConsole(slot, "Plugin Reload", "Plugin is not loaded.\n");

    g_pluginManager.StopPlugin(plugin_name, true);
    g_pluginManager.LoadPlugin(plugin_name);
    g_pluginManager.StartPlugin(plugin_name);
    PrintToClientOrConsole(slot, "Plugin Reload", "Plugin '%s' has been reloaded.\n", plugin_name.c_str());
}

void SwiftlyPluginManagerRefresh(CPlayerSlot slot)
{
    auto oldPluginsAmount = g_pluginManager.GetPluginsList().size();
    g_pluginManager.LoadPlugins("");
    auto newPluginsAmount = g_pluginManager.GetPluginsList().size();
    PrintToClientOrConsole(slot, "Plugin Refresh", "Plugins have been succesfully refreshed. (%d -> %d plugins)\n", oldPluginsAmount, newPluginsAmount);
}

void SwiftlyPluginManager(CPlayerSlot slot, const char* subcmd, const char* plugin_name)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        ShowSwiftlyPluginManagerHelp(slot);
        return;
    }

    if (sbcmd == "list")
        SwiftlyPluginManagerList(slot);
    else if (sbcmd == "info")
        SwiftlyPluginManagerInfo(slot, plugin_name);
    else if (sbcmd == "unload")
        SwiftlyPluginManagerUnload(slot, plugin_name);
    else if (sbcmd == "load")
        SwiftlyPluginManagerLoad(slot, plugin_name);
    else if (sbcmd == "reload")
        SwiftlyPluginManagerReload(slot, plugin_name);
    else if (sbcmd == "refresh")
        SwiftlyPluginManagerRefresh(slot);
    else
        ShowSwiftlyPluginManagerHelp(slot);
}