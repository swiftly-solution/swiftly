#include "game.h"

#include <swiftly-ext/core.h>

std::string GetGameName()
{
#if SOURCE_ENGINE == SE_CS2
    return "cs2";
#else
    return "unknown";
#endif
}

int GetMaxGameClients()
{
#if SOURCE_ENGINE == SE_CS2
    return 64;
#else
    return 64;
#endif
}

EXT_API const char* swiftly_GetGameName() {
    return GetGameName().c_str();
}