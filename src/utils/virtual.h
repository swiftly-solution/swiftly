#pragma once

template <typename T, typename... Args>
constexpr T CallVFunc(int index, void *pThis, Args... args) noexcept
{
    return reinterpret_cast<T (*)(void *, Args...)>(reinterpret_cast<void ***>(pThis)[0][index])(pThis, args...);
}

#define CALL_VIRTUAL(retType, idx, ...) CallVFunc<retType>(idx, __VA_ARGS__)