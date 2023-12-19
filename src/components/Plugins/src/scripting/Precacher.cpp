#include "../../../../common.h"
#include "../../../../precacher/Precacher.h"

SMM_API void scripting_Precacher_AddModel(const char *model)
{
    if (model == nullptr)
        return;

    g_precacher->AddModel(model);
}