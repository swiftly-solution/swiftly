#include "../../scripting.h"
#include "../../../../server/translations/Translations.h"

std::string scripting_FetchTranslation(std::string key, int playerid)
{
    return g_translations->FetchTranslation(key, playerid);
}