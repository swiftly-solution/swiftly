#ifndef _nativehooks_h
#define _nativehooks_h

#include "FuncHook.h"

class CBasePlayerController;
class CCommand;

void Hook_LoggingSystem_LogDirect(int, int, const char *, ...);
void Hook_LoggingSystem_Log(int, int, const char *, ...);
void Hook_LoggingSystem_LogAssert(const char *, ...);
void Hook_Msg(const char *, ...);
void Hook_Warning(const char *, ...);
void Hook_ClientPrint(CBasePlayerController *, int, const char *, const char *, const char *, const char *, const char *);
void Hook_PrecacheResource(const char *, int64_t);
bool Hook_IsHearingClient(void *, int);
bool InitializeHooks();

#endif