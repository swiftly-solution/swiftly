#ifndef _hooks_funchook_h
#define _hooks_funchook_h

#include <functional>
#include <tier1/utlvector.h>
#include <funchook.h>
#include "../signatures/Signatures.h"
#include "../signatures/Offsets.h"
#include "../../common.h"
#include "../../entrypoint.h"
#include "../../utils/utils.h"
#include "../../engine/addons/addons.h"

class FuncHookBase
{
public:
    virtual const char *GetName() = 0;
    virtual void Free() = 0;
    virtual bool Create() = 0;
    virtual void Enable() = 0;
    virtual void Disable() = 0;
};

extern CUtlVector<FuncHookBase *> g_vecHooks;

template <typename T>
class FuncHook : FuncHookBase
{
private:
    const char *m_name;
    T *m_fn;
    T *m_pfn;
    
    const char* m_lib;
    const char* m_cls;
    const char* m_off;

    funchook_t *m_hook;
    bool m_installed;

public:
    FuncHook(T *fn, const char *name)
    {
        this->m_fn = fn;
        this->m_name = name;

        g_vecHooks.AddToTail(this);
    }

    FuncHook(T *fn, const char* lib, const char* cls, const char* off)
    {
        this->m_fn = fn;
        this->m_lib = lib;
        this->m_cls = cls;
        this->m_off = off;
        this->m_name = off;

        g_vecHooks.AddToTail(this);
    }

    ~FuncHook()
    {
        this->Free();
    }

    bool Create() override;
    void Enable() override;
    void Disable() override;
    void Free() override;
    const char *GetName() override { return this->m_name; }
    T *GetFn() { return this->m_fn; }

    template <typename... Args>
    auto operator()(Args &&...args)
    {
        return std::invoke(this->m_pfn, std::forward<Args>(args)...);
    }
};

extern CUtlVector<FuncHookBase *> g_funcHooks;

template <typename T>
bool FuncHook<T>::Create()
{
    void *ptr = nullptr;
    if(this->m_lib == nullptr) {
        if (!g_Signatures->Exists(this->m_name))
        {
            if(std::string(this->m_name) == "HostStateRequest") {
                PLUGIN_PRINT("FuncHook", "The signature for \"HostStateRequest\" has not been found. The \"Addons\" system has been forcefully disabled.\n");
                g_addons.SetStatus(false);
                return true;
            }
            
            PLUGIN_PRINTF("FuncHook", "Failed create for %s.\nError Message: Signature was not found.\n", this->GetName());
            return false;
        }

        ptr = g_Signatures->FetchRawSignature(this->m_name);
    } else {
        DynLibUtils::CModule mod = DetermineModuleByLibrary(this->m_lib);
        void* serverSideClientVTable = mod.GetVirtualTableByName(this->m_cls);
        ptr = ((void**)serverSideClientVTable)[g_Offsets->GetOffset(this->m_off)];
    }

    if (ptr == nullptr)
    {
        PLUGIN_PRINTF("FuncHook", "Failed create for %s.\nError Message: Invalid signature pointer.\n", this->GetName());
        return false;
    }

    this->m_pfn = reinterpret_cast<T *>(ptr);

    this->m_hook = funchook_create();
    funchook_prepare(this->m_hook, (void **)&this->m_pfn, (void *)this->m_fn);

    g_funcHooks.AddToTail(this);

    return true;
}

template <typename T>
void FuncHook<T>::Enable()
{
    if (!this->m_hook)
        return;
    if(this->m_installed)
        return;

    int err = funchook_install(this->m_hook, 0);

    if (!err)
        this->m_installed = true;
    else
        PLUGIN_PRINTF("FuncHook", "Failed enable for %s.\nError Code: %d\nError Message: %s\n", this->GetName(), err, funchook_error_message(this->m_hook));
}

template <typename T>
void FuncHook<T>::Disable()
{
    if (!this->m_hook)
        return;
    if(!this->m_installed)
        return;

    int err = funchook_uninstall(this->m_hook, 0);

    if (!err)
        this->m_installed = false;
    else
        PLUGIN_PRINTF("FuncHook", "Failed disable for %s.\nError Code: %d\nError Message: %s\n", this->GetName(), err, funchook_error_message(this->m_hook));
}

template <typename T>
void FuncHook<T>::Free()
{
    if (!this->m_hook)
        return;

    if (this->m_installed)
        this->Disable();

    int err = funchook_destroy(this->m_hook);

    if (err != 0)
        PLUGIN_PRINTF("FuncHook", "Failed destruction for %s.\nError Code: %d\nError Message: %s\n", this->GetName(), err, funchook_error_message(this->m_hook));
}

#endif