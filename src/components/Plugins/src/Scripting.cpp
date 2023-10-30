#include "../../../common.h"

SMM_API void scripting_Print(const char *str)
{
    if (!g_SMAPI)
        return;

    if (strcmp(str, "") == 0)
        return;

    g_SMAPI->ConPrint(str);
}