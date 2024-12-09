#include "Extension.h"
#include "../entrypoint.h"
#include "../plugins/PluginManager.h"
#include <swiftly-ext/core.h>

typedef void* (*GetExtensionCls)();

Extension::Extension(std::string name)
{
    m_name = name;
}

Extension::~Extension()
{
}

std::string Extension::GetName()
{
    return m_name;
}

bool Extension::LoadExtension(bool late)
{
#ifdef _WIN32
    m_hModule = dlmount((std::string("addons/swiftly/extensions/win64/") + m_name + ".dll").c_str());
#else
    m_hModule = dlopen((std::string("addons/swiftly/extensions/linuxsteamrt64/") + m_name + ".so").c_str(), RTLD_NOW);

    if (!m_hModule) {
        PRINTF("Failed to load extension: %s\n", dlerror());
        return false;
    }
#endif

    void* fnGetClass = reinterpret_cast<void*>(dlsym(m_hModule, "GetExtensionClass"));
    if (!fnGetClass) {
        PRINT("Failed to load extension: GetExtensionClass is not present.\n");
        return false;
    }

    m_api = (SwiftlyExt*)(reinterpret_cast<GetExtensionCls>(fnGetClass)());

    std::string err;
    bool res = m_api->Load(err, g_SHPtr, g_SMAPI, late);
    loaded = res;
    if (!res) {
        PRINT("An error has occured while trying to load the extension.\n");
        PRINTF("Extension: %s.\n", m_name.c_str());
        PRINTF("Error: %s\n", err.c_str());
        dlclose(m_hModule);
        m_hModule = nullptr;
        m_api = nullptr;
        return false;
    }
    return true;
}

bool Extension::UnloadExtension()
{
    for(auto plugin : g_pluginManager->GetPluginsList())
        if(plugin->GetPluginState() == PluginState_t::Started) {
            if(plugin->GetKind() == PluginKind_t::Lua) {
                std::string error = "";
                if (!this->GetAPI()->OnPluginUnload(plugin->GetName(), (void*)((LuaPlugin*)plugin)->GetState(), plugin->GetKind(), error)) {
                    PRINTF("An error has occured while trying to unload the extension from plugin '%s'.\n", plugin->GetName().c_str());
                    PRINTF("Extension: %s.\n", m_name.c_str());
                    PRINTF("Error: %s.\n", error.c_str());
                    return false;
                }
            }
        }

    std::string err;
    bool res = m_api->Unload(err);
    if (!res) {
        PRINT("An error has occured while trying to unload the extension.\n");
        PRINTF("Extension: %s.\n", m_name.c_str());
        PRINTF("Error: %s\n", err.c_str());
        loaded = true;
        return false;
    }

    dlclose(m_hModule);
    m_hModule = nullptr;
    m_api = nullptr;
    loaded = false;
    return true;
}

SwiftlyExt* Extension::GetAPI()
{
    return m_api;
}

bool Extension::IsLoaded()
{
    return loaded;
}