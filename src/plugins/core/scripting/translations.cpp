#include "../scripting.h"
#include "../../../translations/Translations.h"

std::string scripting_FetchTranslation(Plugin *plugin, std::string key)
{
    return g_translations->FetchTranslation(key);
}