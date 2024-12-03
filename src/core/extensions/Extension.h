#ifndef _core_extensions_ext_h
#define _core_extensions_ext_h

#include <string>
#include <swiftly-ext/extension.h>
#include <metamod_oslink.h>

#ifndef _WIN32
#include <dlfcn.h>
#endif

class Extension
{
private:
    std::string m_name;
    HINSTANCE m_hModule;
    SwiftlyExt* m_api;
public:
    Extension(std::string name);
    ~Extension();

    std::string GetName();

    bool LoadExtension(bool late);
    bool UnloadExtension();
};

#endif