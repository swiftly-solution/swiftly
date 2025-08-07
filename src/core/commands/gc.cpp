#include "commands.h"

#include <embedder/src/Embedder.h>
#include <plugins/manager.h>

static std::map<ContextKinds, std::string> runtimeNames = {
    { ContextKinds::Lua, "Lua" },
    { ContextKinds::Dotnet, ".NET" },
};

void SwiftlyGarbageCollectorManagerHelp(CPlayerSlot slot)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Resource Monitor Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: sw gc <command>\n");
    PrintToClientOrConsole(slot, "Commands", " info - See informations related to the plugin's garbage collection.\n");
}

void SwiftlyGarbageCollectorInfo(CPlayerSlot slot)
{
    PLUGIN_PRINTF("Garbage Collector", "Plugin Garbage Collector Viewer\n");
    TextTable gcTable('-', '|', '+');

    gcTable.add(" ID ");
    gcTable.add(" Values ");
    gcTable.add(" Numbers ");
    gcTable.add(" Booleans ");
    gcTable.add(" Functions ");
    gcTable.add(" Classes ");
    gcTable.add(" Strings ");
    gcTable.add(" Lists ");
    gcTable.endOfRow();

    auto pluginsList = g_pluginManager.GetPluginsList();
    for (auto& plugin : pluginsList)
    {
        if (plugin->GetPluginState() != PluginState_t::Started) continue;

        auto context = plugin->GetContext();
        auto& mappedValues = context->GetMappedValue();

        uint64_t numbersCount = 0;
        uint64_t numbersSize = 0;

        uint64_t booleansCount = 0;
        uint64_t booleansSize = 0;

        uint64_t functionsCount = 0;
        uint64_t functionsSize = 0;

        uint64_t classesCount = 0;
        uint64_t classesSize = 0;

        uint64_t stringsCount = 0;
        uint64_t stringsSize = 0;

        uint64_t listsCount = 0;
        uint64_t listsSize = 0;

        for (auto it = mappedValues.begin(); it != mappedValues.end(); ++it)
        {
            auto val = *it;
            if (val->isNumber()) {
                numbersCount++;
                numbersSize += sizeof(int64_t);
            }
            else if (val->isBool()) {
                booleansCount++;
                booleansSize++;
            }
            else if (val->isFunction()) {
                functionsCount++;
                functionsSize += 36; // dotnet highest value for function size, lua doesn't have one
            }
            else if (val->isInstance<ClassData*>()) {
                classesCount++;
                classesSize += sizeof(ClassData);
            }
            else if (val->isString()) {
                stringsCount++;
                stringsSize += val->cast<std::string>().size();
            }
            else if (val->isTable()) {
                listsCount++;
                listsSize += (plugin->GetKind() == ContextKinds::Dotnet ? sizeof(ArrayData) : 64);
            }
        }

        gcTable.add(" " + plugin->GetName() + " ");
        gcTable.add(string_format(" %d ", mappedValues.size()));
        gcTable.add(string_format(" %d (~%dB) ", numbersCount, numbersSize));
        gcTable.add(string_format(" %d (~%dB) ", booleansCount, booleansSize));
        gcTable.add(string_format(" %d (~%dB) ", functionsCount, functionsSize));
        gcTable.add(string_format(" %d (~%dB) ", classesCount, classesSize));
        gcTable.add(string_format(" %d (~%dB) ", stringsCount, stringsSize));
        gcTable.add(string_format(" %d (~%dB) ", listsCount, listsSize));
        gcTable.endOfRow();
    }

    PrintTextTable("Garbage Collector", gcTable);
}

void SwiftlyGCManager(CPlayerSlot slot, const char* subcmd, const char* subcmd2)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        SwiftlyGarbageCollectorManagerHelp(slot);
        return;
    }

    if (sbcmd == "info")
        SwiftlyGarbageCollectorInfo(slot);
    else
        SwiftlyGarbageCollectorManagerHelp(slot);
}