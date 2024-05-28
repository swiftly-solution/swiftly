#include "NativeHooks.h"

CUtlVector<FuncHookBase *> g_vecHooks;
CUtlVector<FuncHookBase *> g_funcHooks;

bool InitializeHooks()
{
    g_funcHooks.PurgeAndDeleteElements();

    FOR_EACH_VEC(g_vecHooks, i)
    {
        if (!g_vecHooks[i]->Create())
            return false;

        g_vecHooks[i]->Enable();
    }

    return true;
}

void UnloadHooks()
{
    FOR_EACH_VEC(g_vecHooks, i)
    {
        g_vecHooks[i]->Disable();
        g_vecHooks[i]->Free();
    }
}