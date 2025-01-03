#include "../../scripting.h"

PluginLogger::PluginLogger(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
    g_Logger->AddLogger(m_plugin_name, true);
}

void PluginLogger::Write(int level, std::string message)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginLogger::Write(level=%d)", level));

    Log* logger = g_Logger->FetchLogger(this->plugin_name);
    if (!logger)
        return;

    logger->WriteLog((LogType_t)level, message);
}