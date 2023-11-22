#ifndef _swiftly_memory_h
#define _swiftly_memory_h

#include "swiftly_oslink.h"
#include <map>
#include <fstream>
#include "types.h"

HINSTANCE mainProgram;
bool isSet = false;

std::map<const char *, void *> functions;

typedef const char *(*Player_GetName)(uint32_t);
typedef uint64_t (*Player_GetSteamID)(uint32_t);
typedef void (*Player_Drop)(uint32_t, ENetworkDisconnectionReason);
typedef bool (*Player_IsAuthenticated)(uint32_t);
typedef const char *(*Player_GetConvar)(uint32_t, const char *);
typedef void (*Player_Kill)(uint32_t);

typedef uint8_t (*Player_GetTeam)(uint32_t);
typedef void (*Player_SetTeam)(uint32_t, int);

typedef int (*Player_GetHealth)(uint32_t);
typedef void (*Player_SetHealth)(uint32_t, int);
typedef void (*Player_TakeHealth)(uint32_t, int);

typedef int (*Player_GetArmor)(uint32_t);
typedef void (*Player_SetArmor)(uint32_t, int);
typedef void (*Player_TakeArmor)(uint32_t, int);

typedef const char *(*Player_GetClanTag)(uint32_t);
typedef void (*Player_SetClanTag)(uint32_t, const char *);

typedef void (*Player_SendMessage)(uint32_t, HudDestination, const char *);
typedef void (*Players_SendMessage)(HudDestination, const char *);

typedef const char *(*Database_EscapeString)(const char *, const char *);
typedef bool (*Database_Connect)(const char *);

typedef void (*Commands_RegisterCommand)(const char *, const char *, void *);
typedef void (*Commands_UnregisterCommand)(const char *);

typedef const char *(*Configuration_Fetch)(const char *);

typedef void (*Logger_CreateLogger)(const char *);
typedef void (*Logger_WriteLog)(const char *, ELogType, const char *);

void *FetchFunctionPtr(const char *filePath, const char *function_name)
{
    if (!isSet)
    {
        isSet = true;
        mainProgram = dlmount(filePath);
    }

    if (functions.find(function_name) != functions.end())
        return functions.at(function_name);

    void *func = reinterpret_cast<void *>(dlsym(mainProgram, function_name));
    functions.insert(std::make_pair(function_name, func));

    return func;
}

#endif