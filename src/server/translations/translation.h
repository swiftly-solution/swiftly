#ifndef _server_translations_translation_h
#define _server_translations_translation_h

#include <map>
#include <string>

class Translation
{
private:
    std::map<std::string, std::string> m_values;

public:
    void RegisterLanguage(std::string lang, std::string value);
    std::string FetchLanguage(std::string lang);
};

#endif