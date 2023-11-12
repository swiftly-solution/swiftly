#ifndef _translations_h
#define _translations_h

#include "Translation.h"
#include <map>
#include <string>

class Translations
{
private:
    std::map<std::string, Translation *> m_translations;

public:
    Translations() {}

    void LoadTranslations();
    std::string FetchTranslation(std::string key);
};

extern Translations *g_translations;

#endif