#include "translation.h"

void Translation::RegisterLanguage(std::string lang, std::string value)
{
    if (m_values.find(lang) != m_values.end())
        return;

    m_values.insert({lang, value});
}

std::string Translation::FetchLanguage(std::string lang)
{
    if (m_values.find(lang) == m_values.end())
        return "NO_TRANSLATION";

    return m_values[lang];
}