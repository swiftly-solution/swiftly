#ifndef _core_extensions_manager_h
#define _core_extensions_manager_h

#include "extension.h"
#include <vector>

class ExtensionManager
{
private:
    std::vector<Extension*> exts;
    std::map<std::string, Extension*> extsMap;

    bool all_loaded = false;
public:
    void LoadExtensions();
    void UnloadExtensions();

    bool ExtensionExists(std::string ext_name);

    void LoadExtension(std::string ext_name);
    void UnloadExtension(std::string ext_name);

    Extension* FetchExtension(std::string ext_name);

    std::vector<Extension*> GetExtensionsList();
};

extern ExtensionManager extManager;

#endif