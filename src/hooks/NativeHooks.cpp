#include "NativeHooks.h"

CUtlVector<FuncHookBase *> g_funcHooks;

bool InitializeHooks()
{
    g_funcHooks.PurgeAndDeleteElements();

    return true;
}