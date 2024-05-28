#ifndef _translation_h
#define _translation_h

#include <map>
#include <string>

class Translation
{
private:
    std::map<std::string, std::string> m_values;

public:
    Translation() {}

    void RegisterLanguage(std::string lang, std::string value)
    {
        if (this->m_values.find(lang) != this->m_values.end())
            return;

        this->m_values.insert(std::make_pair(lang, value));
    }

    std::string FetchLanguage(std::string lang)
    {
        if (this->m_values.find(lang) == this->m_values.end())
            return "NO_TRANSLATION";

        return this->m_values.at(lang);
    }
};

#endif