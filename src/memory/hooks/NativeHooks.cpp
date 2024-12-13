#include "NativeHooks.h"

CUtlVector<FuncHookBase *> g_funcHooks;

bool InitializeHooks()
{
    g_funcHooks.PurgeAndDeleteElements();

    FOR_EACH_VEC(g_vecHooks, i)
    {
        PLUGIN_PRINTF("Hooks", "Hooking %s...\n", g_vecHooks[i]->GetName());
        if (!g_vecHooks[i]->Create())
            return false;

        g_vecHooks[i]->Enable();
        PLUGIN_PRINTF("Hooks", "Hooked %s.\n", g_vecHooks[i]->GetName());
    }

    return true;
}

void UnloadHooks()
{
    FOR_EACH_VEC(g_vecHooks, i)
    {
        g_vecHooks[i]->Disable();
    }
}