#ifndef _swiftly_memory_h
#define _swiftly_memory_h

#include "swiftly_oslink.h"
#include <map>
#include <fstream>
#include "types.h"

typedef const char *(*Player_GetName)(uint32_t);
typedef uint64_t (*Player_GetSteamID)(uint32_t);
typedef void (*Player_Drop)(uint32_t, ENetworkDisconnectionReason);
typedef bool (*Player_IsAuthenticated)(uint32_t);
typedef const char *(*Player_GetConvar)(uint32_t, const char *);
typedef void (*Player_Kill)(uint32_t);

typedef uint8_t (*Player_GetTeam)(uint32_t);
typedef void (*Player_SetTeam)(uint32_t, int);

typedef void (*Player_SetModel)(uint32_t, const char *);

typedef int (*Player_GetHealth)(uint32_t);
typedef void (*Player_SetHealth)(uint32_t, int);
typedef void (*Player_TakeHealth)(uint32_t, int);

typedef int (*Player_GetArmor)(uint32_t);
typedef void (*Player_SetArmor)(uint32_t, int);
typedef void (*Player_TakeArmor)(uint32_t, int);

typedef int (*Player_GetMoney)(uint32_t);
typedef void (*Player_SetMoney)(uint32_t, int);
typedef void (*Player_TakeMoney)(uint32_t, int);

typedef void (*Player_ExecuteCommand)(uint32_t, const char *);

typedef const char *(*Player_GetClanTag)(uint32_t);
typedef void (*Player_SetClanTag)(uint32_t, const char *);

typedef void (*Player_SetVar)(uint32_t, const char *, int, ...);
typedef const char *(*Player_GetVar)(uint32_t, const char *);

typedef uint32_t (*Player_GetConnectedTime)(uint32_t);

typedef void (*Player_ShowMenu)(uint32_t, const char *);
typedef void (*Player_HideMenu)(uint32_t);
typedef void (*Player_SetFlashDuration)(uint32_t, float);

typedef int (*Player_FetchStat)(uint32_t, uint32_t);
typedef void (*Player_SetStat)(uint32_t, uint32_t, int);

typedef const char *(*Player_GetIPAddress)(uint32_t);
typedef void (*Player_SetMusicKit)(uint32_t, int);

typedef void (*Player_SetGloves)(uint32_t, int, int, int, float);

typedef void (*Player_SendMessage)(uint32_t, HudDestination, const char *);
typedef void (*Players_SendMessage)(HudDestination, const char *);

typedef int (*Player_GetLatency)(uint32_t);

typedef const char *(*Database_EscapeString)(const char *, const char *);
typedef bool (*Database_Connect)(const char *);

typedef void (*Commands_RegisterCommand)(const char *, const char *, void *);
typedef void (*Commands_UnregisterCommand)(const char *);

typedef const char *(*Configuration_Fetch)(const char *);
typedef uint32_t (*Configuration_FetchArraySize)(const char *);
typedef bool (*Configuration_Exists)(const char *);

typedef void (*Logger_CreateLogger)(const char *);
typedef void (*Logger_WriteLog)(const char *, ELogType, const char *);

typedef void (*Server_ExecuteCommand)(const char *);
typedef const char *(*Server_GetMap)();
typedef uint16_t (*Server_GetMaxPlayers)();
typedef bool (*Server_IsMapValid)(const char *);
typedef void (*Server_AddPrecacheModel)(const char *);

typedef uint64_t (*HTTP_CreateRequest)(const char *);
typedef void (*HTTP_SetBody)(uint64_t, const char *);
typedef void (*HTTP_AddHeader)(uint64_t, const char *, const char *);
typedef void (*HTTP_DeleteHeader)(uint64_t, const char *);
typedef void (*HTTP_AddMultipartFile)(uint64_t, const char *, const char *, const char *, const char *);
typedef void (*HTTP_SetContentType)(uint64_t, ContentType);
typedef void (*HTTP_SetBasicAuthentication)(uint64_t, const char *, const char *);
typedef void (*HTTP_SetBearerAuthenticationToken)(uint64_t, const char *);
typedef void (*HTTP_SetFollowRedirect)(uint64_t, bool);
typedef void (*HTTP_Close)(uint64_t);

typedef void (*HTTP_Get)(uint64_t, const char *);
typedef void (*HTTP_Delete)(uint64_t, const char *);
typedef void (*HTTP_Post)(uint64_t, const char *);
typedef void (*HTTP_Put)(uint64_t, const char *);
typedef void (*HTTP_Patch)(uint64_t, const char *);

typedef const char *(*HTTP_GetError)(uint64_t);
typedef const char *(*HTTP_GetBody)(uint64_t);
typedef int (*HTTP_GetStatusCode)(uint64_t);

void *FetchFunctionPtr(const char *filePath, const char *function_name);

#endif