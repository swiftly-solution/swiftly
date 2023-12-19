#ifndef _nativehooks_h
#define _nativehooks_h

#include "FuncHook.h"

class CBasePlayerController;
class CCommand;

void __fastcall Hook_LoggingSystem_LogDirect(int, int, const char *, ...);
void __fastcall Hook_LoggingSystem_Log(int, int, const char *, ...);
void __fastcall Hook_LoggingSystem_LogAssert(const char *, ...);
void __fastcall Hook_Msg(const char *, ...);
void __fastcall Hook_Warning(const char *, ...);
void __fastcall Hook_ClientPrint(CBasePlayerController *, int, const char *, const char *, const char *, const char *, const char *);
void __fastcall Hook_PrecacheResource(const char *, int64_t);
bool __fastcall Hook_IsHearingClient(void *, int);
bool InitializeHooks();

#endif