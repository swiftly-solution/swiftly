#include "../../../../common.h"
#include "../../../../translations/Translations.h"

SMM_API const char *scripting_Translations_Fetch(const char *key)
{
    if (key == nullptr)
        return nullptr;

    return g_translations->FetchTranslation(key).c_str();
}