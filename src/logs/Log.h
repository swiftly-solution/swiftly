#ifndef _log_h
#define _log_h

#include <string>

enum ELogType
{
    LOGLEVEL_DEBUG = 1,
    LOGLEVEL_WARNING = 2,
    LOGLEVEL_ERROR = 3,
    LOGLEVEL_COMMON = 4,
};

class Log
{
private:
    std::string m_path;

public:
    Log(std::string path)
    {
        this->m_path = "addons/swiftly/logs" + path;
    }
    ~Log() {}

    void WriteLog(ELogType logType, std::string str);
    std::string GenerateLogName();
};

#endif