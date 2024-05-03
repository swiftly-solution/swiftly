#include "../../../../common.h"
#include "../../../../utils/memstr.h"
#include "../../../../translations/Translations.h"

SMM_API const char *scripting_Translations_Fetch(const char *key)
{
    if (key == nullptr)
        return nullptr;

    std::string translation = g_translations->FetchTranslation(key);

    MemStr str(translation);
    return str.Get();
}