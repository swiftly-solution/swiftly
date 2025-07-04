#ifndef _memory_hooks_functions_h
#define _memory_hooks_functions_h

#include <string>
#include <vector>
#include <any>

#include <dynohook/core.h>
#include <dynohook/os.h>
#include <dynohook/ihook.h>
#include <dynohook/imanager.h>

#if DYNO_PLATFORM_WINDOWS
#include <dynohook/conventions/x64_windows_call.h>
#define DEFAULT_CALLCONV dyno::x64WindowsCall
#else
#include <dynohook/conventions/x64_systemV_call.h>
#define DEFAULT_CALLCONV dyno::x64SystemVcall
#endif

#include <utils/utils.h>

dyno::DataObject GetDataObject(char arg);
std::vector<dyno::DataObject> GetDataObjectList(std::string args);

class FunctionHook
{
private:
    void* m_pfn;
    dyno::IHook* hookFunc;
    dyno::CallbackType m_callbackType;
    dyno::CallbackHandler m_handler;
    std::string m_function_args;
    std::string m_signature_name;
    char m_function_return;
    bool enabled = true;
public:
    FunctionHook(std::string signature_name, dyno::CallbackType callbackType, dyno::CallbackHandler handler, std::string function_args, char function_return);
    FunctionHook(const char* signature_name, dyno::CallbackType callbackType, dyno::CallbackHandler handler, std::string function_args, char function_return);
    FunctionHook(void* signature_name, dyno::CallbackType callbackType, dyno::CallbackHandler handler, std::string function_args, char function_return);
    ~FunctionHook();

    void Initialize();
    void Enable();
    void Disable();

    dyno::IHook* GetHookFunction();

    std::any Call(std::vector<std::any> arguments);
};

#endif