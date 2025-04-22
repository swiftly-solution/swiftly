#include "log.h"
#include <filesystem/files/files.h>
#include <server/configuration/configuration.h>
#include <core/entrypoint.h>
#include <time.h>

std::string Log::GenerateLogName()
{
    std::string loggingMode = g_Config.FetchValue<std::string>("core.logging.mode");
    if (loggingMode == "daily")
    {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        return string_format("%s_%02d-%02d-%d.log", this->m_path.c_str(), ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900).c_str();
    }
    else if (loggingMode == "map")
        return string_format("%s_%s.log", this->m_path.c_str(), engine->GetServerGlobals()->mapname.ToCStr());
    else
        return string_format("%s.log", this->m_path.c_str());
}

void Log::WriteLog(LogType_t logType, std::string str)
{
    auto GetLogPrefix = [logType]()
        {
            if (logType == LogType_t::Debug)
                return "Debug";
            else if (logType == LogType_t::Error)
                return "Error";
            else if (logType == LogType_t::Warning)
                return "Warning";
            else if (logType == LogType_t::Common)
                return "Common";
            else
                return "Unknown";
        };

    Files::Append(GenerateLogName(), string_format("[%s] %s", GetLogPrefix(), str.c_str()));
}
