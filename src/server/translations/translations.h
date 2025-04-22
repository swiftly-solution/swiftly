#ifndef _server_translations_translations_h
#define _server_translations_translations_h

#include "translation.h"
#include <map>
#include <string>

class Translations
{
private:
    std::map<std::string, Translation> m_translations;

public:
    void LoadTranslations();
    std::string FetchTranslation(std::string key, int playerid = -1);
};

extern Translations g_translations;

#endif