#ifndef _nativehooks_h
#define _nativehooks_h

#include "FuncHook.h"
#include "../sdk/entity/services.h"

class CBasePlayerController;
class CCommand;
class CGameRules;
class CCSGameRules;

void Hook_LoggingSystem_LogDirect(int, int, const char *, ...);
void Hook_LoggingSystem_Log(int, int, const char *, ...);
void Hook_LoggingSystem_LogAssert(const char *, ...);
void Hook_Msg(const char *, ...);
void Hook_Warning(const char *, ...);
void Hook_ClientPrint(CBasePlayerController *, int, const char *, const char *, const char *, const char *, const char *);
void Hook_PrecacheResource(const char *, int64_t);
bool Hook_IsHearingClient(void *, int);
void Hook_CGameRules_Constructor(CGameRules *);
bool InitializeHooks();

#endif