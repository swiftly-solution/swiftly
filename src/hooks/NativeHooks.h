#ifndef _nativehooks_h
#define _nativehooks_h

#include "FuncHook.h"

class CBasePlayerController;
class CCommand;

void FASTCALL Hook_Host_Say(CBasePlayerController *, CCommand &, bool, int, const char *);
void FASTCALL Hook_LoggingSystem_LogDirect(int, int, const char *, ...);
void FASTCALL Hook_LoggingSystem_Log(int, int, const char *, ...);
void FASTCALL Hook_LoggingSystem_LogAssert(const char *, ...);
void FASTCALL Hook_Msg(const char *, ...);
void FASTCALL Hook_Warning(const char *, ...);
void FASTCALL Hook_ClientPrint(CBasePlayerController *, int, const char *, const char *, const char *, const char *, const char *);
bool InitializeHooks();

#endif