#include "ExtensionManager.h"
#include "../filesystem/files/Files.h"

extern bool AllPluginsStarted;

void ExtensionManager::LoadExtensions()
{
    std::string baseDir = std::string("addons/swiftly/extensions/") + WIN_LINUX("win64", "linuxsteamrt64");
    if (!Files::ExistsPath(baseDir))
        Files::CreateDirectory(baseDir);

    std::vector<std::string> extensions = Files::FetchFileNames(baseDir);
    for (std::string extension : extensions)
    {
        if (extension.find("disabled") != std::string::npos)
            continue;

        extension = replace(extension, baseDir, "");
        std::string extension_name = replace(replace(extension, WIN_LINUX("\\", "/"), ""), WIN_LINUX(".dll", ".so"), "");

        LoadExtension(extension_name);
    }

    all_loaded = true;
    for (Extension* extension : exts)
        if (extension->IsLoaded())
            extension->GetAPI()->AllExtensionsLoaded();
}

void ExtensionManager::UnloadExtensions()
{
    std::vector<std::string> extensionNames;
    for (Extension* extension : exts)
        extensionNames.push_back(extension->GetName());

    for (std::string extension_name : extensionNames)
        UnloadExtension(extension_name);

    all_loaded = false;
}

bool ExtensionManager::ExtensionExists(std::string ext_name)
{
    return (extsMap.find(ext_name) != extsMap.end());
}

void ExtensionManager::LoadExtension(std::string ext_name)
{
    if (ExtensionExists(ext_name)) return;

    Extension* ext = new Extension(ext_name);
    if (!ext->LoadExtension(all_loaded)) {
        delete ext;
        return;
    }

    exts.push_back(ext);
    extsMap[ext_name] = ext;

    if (all_loaded)
        ext->GetAPI()->AllExtensionsLoaded();
    if(AllPluginsStarted)
        ext->GetAPI()->AllPluginsLoaded();
}

void ExtensionManager::UnloadExtension(std::string ext_name)
{
    if (!ExtensionExists(ext_name)) return;

    Extension* ext = extsMap[ext_name];
    if (!ext) return;

    if (!ext->UnloadExtension()) return;

    auto it = std::find(exts.begin(), exts.end(), ext);
    if (it != exts.end())
        exts.erase(it);

    delete ext;
    extsMap.erase(ext_name);
}

Extension* ExtensionManager::FetchExtension(std::string ext_name)
{
    if (!ExtensionExists(ext_name)) return nullptr;

    return extsMap[ext_name];
}

std::vector<Extension*> ExtensionManager::GetExtensionsList()
{
    return this->exts;
}