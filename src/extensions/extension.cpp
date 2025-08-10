#include "extension.h"

#include <core/entrypoint.h>
#include <filesystem/files/files.h>
#include <plugins/manager.h>
#include <swiftly-ext/pluginkind.h>

typedef void* (*GetExtensionCls)();

typedef int(CORECLR_DELEGATE_CALLTYPE* load_file_fn)(void* context, const char* filePath, int len);
typedef void(CORECLR_DELEGATE_CALLTYPE* remove_file_fn)(void* context);
typedef void(CORECLR_DELEGATE_CALLTYPE* interpret_as_string_fn)(void* object, int type, const char* out, int len);
typedef void* (CORECLR_DELEGATE_CALLTYPE* allocate_pointer_fn)(int size, int count);
typedef uint64_t(CORECLR_DELEGATE_CALLTYPE* get_plugin_memory_fn)(void* context);
typedef void(CORECLR_DELEGATE_CALLTYPE* execute_function_fn)(void* ctx, void* pctx);
typedef void(CORECLR_DELEGATE_CALLTYPE* state_fn)(int state);

extern load_file_fn loadFile;
extern interpret_as_string_fn interpretAsString;
extern remove_file_fn removeFile;
extern allocate_pointer_fn allocatePointer;
extern get_plugin_memory_fn getMemory;
extern execute_function_fn execFunction;
extern state_fn set_state;

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

#ifdef _WIN32
const char* dlerror()
{
    static char buf[1024];
    DWORD num;

    num = GetLastError();

    if (FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        num,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        buf,
        sizeof(buf),
        NULL)
        == 0)
    {
        _snprintf(buf, sizeof(buf), "unknown error %x", num);
    }

    return buf;
}
#endif

bool Extension::LoadExtension(bool late)
{
#ifdef _WIN32
    m_hModule = dlmount(GeneratePath(std::string("addons/swiftly/extensions/win64/") + m_name + ".dll").c_str());
    if (!m_hModule)
    {
        std::string err = dlerror();
        PRINTF("Failed to load extension: %s\n", err.c_str());
        m_errored = true;
        m_error = err;
        return false;
    }
#else
    m_hModule = dlopen(GeneratePath(std::string("addons/swiftly/extensions/linuxsteamrt64/") + m_name + ".so").c_str(), RTLD_NOW);

    if (!m_hModule) {
        std::string err = dlerror();
        PRINTF("Failed to load extension: %s\n", err.c_str());
        m_errored = true;
        m_error = err;
        return false;
    }
#endif

    void* fnGetClass = reinterpret_cast<void*>(dlsym(m_hModule, "GetExtensionClass"));
    if (!fnGetClass) {
        PRINT("Failed to load extension: GetExtensionClass is not present.\n");
        m_errored = true;
        m_error = "GetExtensionClass is not present";
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
        m_errored = true;
        m_error = err;
        return false;
    }
    return true;
}

bool Extension::UnloadExtension()
{
    for (auto plugin : g_pluginManager.GetPluginsList())
        if (plugin->GetPluginState() == PluginState_t::Started) {
            std::string error = "";
            if (!this->GetAPI()->OnPluginUnload(plugin->GetName(), plugin->GetContext(), (PluginKind_t)plugin->GetKind(), error)) {
                PRINTF("An error has occured while trying to unload the extension from plugin '%s'.\n", plugin->GetName().c_str());
                PRINTF("Extension: %s.\n", m_name.c_str());
                PRINTF("Error: %s.\n", error.c_str());
                m_errored = true;
                m_error = error;
                return false;
            }
        }

    std::string err;
    bool res = m_api->Unload(err);
    if (!res) {
        PRINT("An error has occured while trying to unload the extension.\n");
        PRINTF("Extension: %s.\n", m_name.c_str());
        PRINTF("Error: %s\n", err.c_str());
        m_errored = true;
        m_error = err;
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

std::string Extension::GetError()
{
    return m_error;
}

bool Extension::HasError()
{
    return m_errored;
}

EXT_API void* swiftly_GetDotnetPointer(int kind)
{
    if (kind == 1) return (void*)loadFile;
    else if (kind == 2) return (void*)interpretAsString;
    else if (kind == 3) return (void*)removeFile;
    else if (kind == 4) return (void*)allocatePointer;
    else if (kind == 5) return (void*)getMemory;
    else if (kind == 6) return (void*)execFunction;
    else if (kind == 7) return (void*)set_state;
    else return nullptr;
}

void* GetDotnetPointer(int kind) { return nullptr; }