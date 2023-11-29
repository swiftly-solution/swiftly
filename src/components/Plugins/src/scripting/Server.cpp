#include "../../../../common.h"

SMM_API void scripting_Server_ExecuteCommand(const char *str)
{
    if (str == nullptr)
        return;

    engine->ServerCommand(str);
}