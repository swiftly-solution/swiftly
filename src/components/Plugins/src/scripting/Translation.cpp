#include "../../../../common.h"
#include "../../../../translations/Translations.h"

SMM_API const char *scripting_Translations_Fetch(const char *key)
{
    if (key == nullptr)
        return nullptr;

    std::string translation = g_translations->FetchTranslation(key);

    char *result = new char[translation.size() + 1];
    strcpy(result, translation.c_str());
    return result;
}