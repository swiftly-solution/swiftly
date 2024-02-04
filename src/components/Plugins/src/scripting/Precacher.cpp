#include "../../../../common.h"
#include "../../../../precacher/Precacher.h"

SMM_API void scripting_Precacher_AddModel(const char *model)
{
    if (model == nullptr)
        return;

    g_precacher->AddModel(model);
}

SMM_API void scripting_Precacher_AddSound(const char *path)
{
    if (path == nullptr)
        return;

    g_precacher->AddSound(path);
}