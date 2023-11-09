#ifndef _hooks_funchook_h
#define _hooks_funchook_h

#include <functional>
#include <tier1/utlvector.h>
#include <funchook.h>
#include "../sig/Signatures.h"

class FuncHookBase
{
public:
    virtual const char *GetName() = 0;
    virtual void Free() = 0;
};

template <typename T>
class FuncHook : FuncHookBase
{
private:
    const char *m_name;
    T *m_fn;
    T *m_pfn;
    funchook_t *m_hook;
    bool m_installed;

public:
    FuncHook(T *fn, const char *name) : m_fn(fn), m_name(name) {}
    ~FuncHook()
    {
        this->Free();
    }

    bool Create();
    void Enable();
    void Disable();
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
    if (!g_Signatures->Exists(this->m_name))
        return false;

    void *ptr = g_Signatures->FetchRawSignature(this->m_name);
    if (ptr == nullptr)
        return false;

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

    int err = funchook_install(this->m_hook, 0);

    if (!err)
        this->m_installed = true;
    else
        PRINTF("FuncHook", "Failed enable for %s.\nError Code: %d\nError Message: %s\n", this->GetName(), err, funchook_error_message(this->m_hook));
}

template <typename T>
void FuncHook<T>::Disable()
{
    if (!this->m_hook)
        return;

    int err = funchook_uninstall(this->m_hook, 0);

    if (!err)
        this->m_installed = false;
    else
        PRINTF("FuncHook", "Failed disable for %s.\nError Code: %d\nError Message: %s\n", this->GetName(), err, funchook_error_message(this->m_hook));
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
        PRINTF("FuncHook", "Failed destruction for %s.\nError Code: %d\nError Message: %s\n", this->GetName(), err, funchook_error_message(this->m_hook));
}

#endif