#include "../../../../common.h"
#include "../../../../logs/Logger.h"

SMM_API void scripting_Logger_CreateLogger(const char *plugin_name)
{
    if (plugin_name == nullptr)
        return;

    g_Logger->AddLogger(plugin_name, true);
}

SMM_API void scripting_Logger_WriteLog(const char *plugin_name, ELogType log_type, const char *text)
{
    Log *logger = g_Logger->FetchLogger(plugin_name);
    if (logger == nullptr)
        return;

    if (text == nullptr)
        return;

    logger->WriteLog(log_type, text);
}