#ifndef _memory_hooks_vfunctions_h
#define _memory_hooks_vfunctions_h

#include <string>
#include <vector>
#include <any>

#include <dynohook/core.h>
#include <dynohook/os.h>
#include <dynohook/ihook.h>
#include <dynohook/imanager.h>

#include <memory/virtual/virtual.h>

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

class VFunctionHook
{
private:
    void* m_pvtable;
    int m_ioffset;
    std::string m_library;
    std::string m_vtable;
    std::string m_offsetName;
    dyno::IHook* hookFunc;
    dyno::CallbackType m_callbackType;
    dyno::CallbackHandler m_handler;
    std::string m_function_args;
    char m_function_return;
    bool enabled = true;
public:
    VFunctionHook(std::string library, std::string vtable, std::string offsetName, dyno::CallbackType callbackType, dyno::CallbackHandler handler, std::string function_args, char function_return);
    ~VFunctionHook();

    void Initialize();
    void Enable();
    void Disable();

    std::any Call(std::vector<std::any> arguments);
};

#endif