#ifndef _nativehooks_h
#define _nativehooks_h

#include "FuncHook.h"

class CBasePlayerController;
class CCommand;

void __fastcall Hook_Host_Say(CBasePlayerController *, CCommand &, bool, int, const char *);
void __fastcall Hook_LoggingSystem_LogDirect(int, int, const char *, ...);
void __fastcall Hook_LoggingSystem_Log(int, int, const char *, ...);
void __fastcall Hook_LoggingSystem_LogAssert(const char *, ...);
void __fastcall Hook_Msg(const char *, ...);
void __fastcall Hook_Warning(const char *, ...);
bool InitializeHooks();

#endif