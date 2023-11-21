#ifndef _virtual_h
#define _virtual_h

#include <platform.h>
#include <stdint.h>

template <typename T = void *>
T GetVMethod(unsigned int uIndex, void *pClass)
{
    if (!pClass)
    {
        return T();
    }

    void **pVTable = *static_cast<void ***>(pClass);
    if (!pVTable)
    {
        return T();
    }

    return reinterpret_cast<T>(pVTable[uIndex]);
}

template <typename T, typename... Args>
T CallVirtual(unsigned int uIndex, void *pClass, Args... args)
{
#ifdef _WIN32
    auto pFunc = GetVMethod<T(__thiscall *)(void *, Args...)>(uIndex, pClass);
#else
    auto pFunc = GetVMethod<T(__cdecl *)(void *, Args...)>(uIndex, pClass);
#endif
    if (!pFunc)
    {
        return T();
    }

    return pFunc(pClass, args...);
}

#define CALL_VIRTUAL(retType, idx, ...) CallVirtual<retType>(idx, __VA_ARGS__)

#endif