#include "commands.h"

#include <extensions/manager.h>

void SwiftlyExtensionManagerHelp(CPlayerSlot slot)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Configuration Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly exts <command>\n");
    PrintToClientOrConsole(slot, "Commands", " list     - Shows all the extensions loaded.\n");
}

void SwiftlyExtensionList(CPlayerSlot slot)
{
    uint32 loadedExtensions = 0;
    auto extensions = extManager.GetExtensionsList();
    for (uint32 i = 0; i < extensions.size(); i++)
    {
        Extension* ext = extensions[i];
        if (ext == nullptr)
            continue;
        if (!ext->IsLoaded())
            continue;

        ++loadedExtensions;
    }

    if (loadedExtensions == 0)
        return PrintToClientOrConsole(slot, "Extensions List", "There are no extensions loaded.\n");

    PrintToClientOrConsole(slot, "Extensions List", "Showing below %02d extensions loaded:\n", loadedExtensions);
    uint32 showingIdx = 0;
    std::vector<std::string> errors;
    for (uint32 i = 0; i < extensions.size(); i++)
    {
        Extension* ext = extensions[i];
        if (ext == nullptr)
            continue;
        if (ext->HasError())
            errors.push_back(string_format("Extension '%s': %s", ext->GetName().c_str(), ext->GetError().c_str()));
        if (!ext->IsLoaded())
            continue;

        ++showingIdx;

        std::string website = ext->GetAPI()->GetWebsite();

        PrintToClientOrConsole(slot, "Extensions List", "%02d. \"%s\" (%s) by %s%s\n",
            showingIdx,
            ext->GetAPI()->GetName(),
            ext->GetAPI()->GetVersion(),
            ext->GetAPI()->GetAuthor(),
            website == "" ? "" : string_format(" ( %s )", website.c_str()).c_str());
    }
    if (errors.size() && slot.Get() == -1)
    {
        PrintToClientOrConsole(slot, "Extensions List", "Extension load errors:\n");
        for (const std::string err : errors)
            PrintToClientOrConsole(slot, "Extensions List", "%s\n", err.c_str());

        errors.clear();
    }
}

void SwiftlyExtensionManager(CPlayerSlot slot, const char* subcmd)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        SwiftlyExtensionManagerHelp(slot);
        return;
    }

    if (sbcmd == "list")
        SwiftlyExtensionList(slot);
    else
        SwiftlyExtensionManagerHelp(slot);
}