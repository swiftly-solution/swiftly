#include "logger.h"
#include <filesystem/files/files.h>

Log* Logger::FetchLogger(std::string key)
{
    if (m_Loggers.find(key) == m_Loggers.end())
        return nullptr;

    return m_Loggers[key];
}

void Logger::AddLogger(std::string key, bool plugin)
{
    if (g_Config.FetchValue<bool>("core.logging.enabled") == false)
        return;
    if (FetchLogger(key))
        return;

    if (!Files::ExistsPath("addons/swiftly/logs"))
        Files::CreateDirectory("addons/swiftly/logs");
    if (!Files::ExistsPath("addons/swiftly/logs/plugins"))
        Files::CreateDirectory("addons/swiftly/logs/plugins");

    m_Loggers.insert({ key, new Log((plugin ? "plugins/" : "") + key) });
}

void Logger::RemoveLogger(std::string key)
{
    if (g_Config.FetchValue<bool>("core.logging.enabled") == false)
        return;
    if (!FetchLogger(key))
        return;

    delete m_Loggers[key];
    m_Loggers.erase(key);
}