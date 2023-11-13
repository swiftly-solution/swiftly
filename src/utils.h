#ifndef _utils_h
#define _utils_h

#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include <platform.h>

#define PREFIX "[Swiftly]"

#define GCC_COMPILER (defined(__GNUC__) && !defined(__clang__))

#define PRINT(CATEGORY, FORMAT_STR) g_SMAPI->ConPrint(std::string(PREFIX).append(" [").append(CATEGORY).append("] ").append(FORMAT_STR).c_str())
#define PRINTF(CATEGORY, FORMAT_STR, ...) g_SMAPI->ConPrintf(std::string(PREFIX).append(" [").append(CATEGORY).append("] ").append(FORMAT_STR).c_str(), __VA_ARGS__)
#define PRINTRET(CATEGORY, FORMAT_STR, RET) \
    {                                       \
        PRINT(CATEGORY, FORMAT_STR);        \
        return RET;                         \
    }
#define PRINTFRET(CATEGORY, FORMAT_STR, RET, ...)  \
    {                                              \
        PRINTF(CATEGORY, FORMAT_STR, __VA_ARGS__); \
        return RET;                                \
    }
#define CLIENT_PRINT(SLOT, CATEGORY, FORMAT_STR) g_SMAPI->ClientConPrintf(SLOT, std::string(PREFIX).append(" [").append(CATEGORY).append("] ").append(FORMAT_STR).c_str())
#define CLIENT_PRINTF(SLOT, CATEGORY, FORMAT_STR, ...) g_SMAPI->ClientConPrintf(SLOT, std::string(PREFIX).append(" [").append(CATEGORY).append("] ").append(FORMAT_STR).c_str(), __VA_ARGS__)

template <typename T, int index, typename... Args>
constexpr T CallVFunc(void *pThis, Args... args) noexcept
{
    return reinterpret_cast<T (*)(void *, Args...)>(reinterpret_cast<void ***>(pThis)[0][index])(pThis, args...);
}

#define ARR_SIZE(array) sizeof(array) / sizeof(array[0])

#ifdef _WIN32
#define WIN_LINUX(win, linux) win
#else
#define WIN_LINUX(win, linux) linux
#endif

template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    int size_s = snprintf(nullptr, 0, format.c_str(), args...) + 1; // Extra space for '\0'
    if (size_s <= 0)
        throw std::runtime_error("Error during formatting.");

    size_t size = static_cast<size_t>(size_s);
    std::unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

std::vector<std::string> explode(std::string s, std::string delimiter);
std::string implode(std::vector<std::string> elements, std::string delimiter);

#endif