#include "Logger.h"

Log *Logger::FetchLogger(std::string key)
{
    if (this->m_Loggers.find(key) == this->m_Loggers.end())
        return nullptr;

    return this->m_Loggers.at(key);
}

void Logger::AddLogger(std::string key, bool plugin)
{
    if (g_Config->FetchValue<bool>("core.logging.enabled") == false)
        return;
    if (this->m_Loggers.find(key) != this->m_Loggers.end())
        return;

    Log *logger = new Log((plugin ? "plugins/" : "") + key);
    this->m_Loggers.insert(std::make_pair(key, logger));
}

void Logger::RemoveLogger(std::string key)
{
    if (g_Config->FetchValue<bool>("core.logging.enabled") == false)
        return;
    if (this->m_Loggers.find(key) == this->m_Loggers.end())
        return;

    this->m_Loggers.erase(key);
}