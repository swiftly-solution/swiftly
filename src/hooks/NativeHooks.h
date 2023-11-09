#ifndef _nativehooks_h
#define _nativehooks_h

#include "FuncHook.h"

class CBasePlayerController;
class CCommand;

void Hook_Host_Say(CBasePlayerController *, CCommand &, bool, int, const char *);
bool InitializeHooks();

extern FuncHook<decltype(Hook_Host_Say)> Host_Say;

#endif