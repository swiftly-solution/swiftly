#include "manager.h"

#include <swiftly-ext/core.h>

dyno::DataObject GetDataObject(char arg)
{
    if (arg == 'p')
        return dyno::DataObject(dyno::DataType::Pointer);
    else if (arg == 'f')
        return dyno::DataObject(dyno::DataType::Float);
    else if (arg == 'b')
        return dyno::DataObject(dyno::DataType::Bool);
    else if (arg == 'd')
        return dyno::DataObject(dyno::DataType::Double);
    else if (arg == 'i')
        return dyno::DataObject(dyno::DataType::Int32);
    else if (arg == 'u')
        return dyno::DataObject(dyno::DataType::UInt32);
    else if (arg == 's')
        return dyno::DataObject(dyno::DataType::String);
    else if (arg == 'I')
        return dyno::DataObject(dyno::DataType::Int64);
    else if (arg == 'U')
        return dyno::DataObject(dyno::DataType::UInt64);
    else if (arg == 'v')
        return dyno::DataObject(dyno::DataType::Void);
    else
        return dyno::DataObject(dyno::DataType::Pointer);
}

std::vector<dyno::DataObject> GetDataObjectList(std::string args)
{
    std::vector<dyno::DataObject> data;
    for (int i = 0; i < args.size(); i++) data.push_back(GetDataObject(args.at(i)));
    return data;
}

void HookManager::Initialize()
{
    for (auto hook : funchookQueue)
        hook->Initialize();

    initialized = true;
}

void HookManager::Shutdown()
{
    for (auto hook : funchookQueue)
        hook->Disable();
}

void HookManager::AddToQueue(FunctionHook* hook)
{
    if (initialized) hook->Initialize();
    funchookQueue.push_back(hook);
}

void HookManager::AddToQueue(VFunctionHook* hook)
{
    if (initialized) hook->Initialize();
    vfunchookQueue.push_back(hook);
}

EXT_API void* swiftly_FunctionHook_Init(const char* sig, bool cbtype, void* cb, const char* func_args, char return_val)
{
    return new FunctionHook(std::string(sig), (dyno::CallbackType)cbtype, reinterpret_cast<dyno::CallbackHandler>(cb), func_args, return_val);
}

EXT_API void* swiftly_FunctionHook_InitPtr(void* sig, bool cbtype, void* cb, const char* func_args, char return_val)
{
    return new FunctionHook(sig, (dyno::CallbackType)cbtype, reinterpret_cast<dyno::CallbackHandler>(cb), func_args, return_val);
}

EXT_API void swiftly_FunctionHook_Destroy(void* ptr)
{
    FunctionHook* fhook = (FunctionHook*)ptr;
    delete fhook;
}

EXT_API void swiftly_FunctionHook_Enable(void* ptr)
{
    FunctionHook* fhook = (FunctionHook*)ptr;
    fhook->Enable();
}

EXT_API void swiftly_FunctionHook_Disable(void* ptr)
{
    FunctionHook* fhook = (FunctionHook*)ptr;
    fhook->Disable();
}

EXT_API void* swiftly_VFunctionHook_Init(const char* lib, const char* vtable, const char* offset, bool cbtype, void* func, const char* function_args, char return_val)
{
    return new VFunctionHook(lib, vtable, offset, (dyno::CallbackType)cbtype, reinterpret_cast<dyno::CallbackHandler>(func), function_args, return_val);
}

EXT_API void swiftly_VFunctionHook_Destroy(void* ptr)
{
    VFunctionHook* vhook = (VFunctionHook*)ptr;
    delete vhook;
}

EXT_API void swiftly_VFunctionHook_Enable(void* ptr)
{
    VFunctionHook* vhook = (VFunctionHook*)ptr;
    vhook->Enable();
}

EXT_API void swiftly_VFunctionHook_Disable(void* ptr)
{
    VFunctionHook* vhook = (VFunctionHook*)ptr;
    vhook->Disable();
}