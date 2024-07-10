#ifndef _common_h
#define _common_h

#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include <tier0/platform.h>

#ifdef _WIN32
#define __FUNCTION_NAME__ __FUNCTION__
#else
#define __FUNCTION_NAME__ __FUNCTION__
#endif

//////////////////////////////////////////////////////////////
/////////////////         Windows Stuff        //////////////
////////////////////////////////////////////////////////////

#ifdef _WIN32
#ifdef GetTickCount
#undef GetTickCount
#endif
#ifdef GetCurrentTime
#undef GetCurrentTime
#endif
#ifdef VOID
#undef VOID
#endif
#ifdef GetObject
#undef GetObject
#endif
#endif

#ifdef _WIN32
#define WIN_LINUX(win, linux) win
#else
#define WIN_LINUX(win, linux) linux
#endif

#define PREFIX "[Swiftly]"

#define GCC_COMPILER (defined(__GNUC__) && !defined(__clang__))

void PLUGIN_PRINT(std::string category, std::string str);
void PLUGIN_PRINTF(std::string category, std::string str, ...);

#define PRINT(str) PLUGIN_PRINT(__FUNCTION_NAME__, str)
#define PRINTF(str, ...) PLUGIN_PRINTF(__FUNCTION_NAME__, str, __VA_ARGS__)
#define PRINTRET(FORMAT_STR, RET) \
    {                             \
        PRINT(FORMAT_STR);        \
        return RET;               \
    }
#define PRINTFRET(FORMAT_STR, RET, ...)  \
    {                                    \
        PRINTF(FORMAT_STR, __VA_ARGS__); \
        return RET;                      \
    }
#define CLIENT_PRINT(SLOT, FORMAT_STR) g_SMAPI->ClientConPrintf(SLOT, std::string(PREFIX).append(" [").append(__FUNCTION_NAME__).append("] ").append(FORMAT_STR).c_str())
#define CLIENT_PRINTF(SLOT, FORMAT_STR, ...) g_SMAPI->ClientConPrintf(SLOT, std::string(PREFIX).append(" [").append(__FUNCTION_NAME__).append("] ").append(FORMAT_STR).c_str(), __VA_ARGS__)

#ifndef SWIFTLY_DEBUG
#define DEBUG_PRINTF(FORMAT_STR, ...)
#define DEBUG_PRINT(FORMAT_STR)
#define DEBUG_CONTEXT()
#else
class DebugContext
{
private:
    std::string str;

public:
    DebugContext(std::string tmp)
    {
        this->str = tmp;
        PRINTF("%s begins\n", this->str.c_str());
    }

    ~DebugContext()
    {
        PRINTF("%s ends\n", this->str.c_str());
    }
};

#define DEBUG_PRINTF(FORMAT_STR, ...) PLUGIN_PRINTF(string_format("Debug - %s", __FUNCTION_NAME__), FORMAT_STR, __VA_ARGS__)
#define DEBUG_PRINT(FORMAT_STR) PLUGIN_PRINT(string_format("Debug - %s", __FUNCTION_NAME__), FORMAT_STR)
#define DEBUG_CONTEXT() DebugContext IDJHFBGIUSEFHWESOIGWSEHOIFSJIERGKSKEF(__FUNCTION_NAME__);
#endif

#endif