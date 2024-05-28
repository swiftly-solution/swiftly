#include "Log.h"
#include "../files/Files.h"
#include "../configuration/Configuration.h"

std::string Log::GenerateLogName()
{
    std::string loggingMode = g_Config->FetchValue<std::string>("core.logging.mode");
    if (loggingMode == "daily")
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return string_format("%s_%02d-%02d-%d.log", this->m_path.c_str(), ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900).c_str();
    }
    else if (loggingMode == "map")
        return string_format("%s_%s.log", this->m_path.c_str(), engine->GetServerGlobals()->mapname.ToCStr());
    else
        return string_format("%s.log", this->m_path.c_str());
}

void Log::WriteLog(ELogType logType, std::string str)
{
    auto GetLogPrefix = [logType]()
    {
        if (logType == LOGLEVEL_DEBUG)
            return "Debug";
        else if (logType == LOGLEVEL_ERROR)
            return "Error";
        else if (logType == LOGLEVEL_WARNING)
            return "Warning";
        else if (logType == LOGLEVEL_COMMON)
            return "Common";
        else
            return "Unknown";
    };

    Files::Append(this->GenerateLogName(), string_format("[%s] %s", GetLogPrefix(), str.c_str()));
}
