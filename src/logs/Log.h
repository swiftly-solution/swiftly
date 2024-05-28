#ifndef _log_h
#define _log_h

#include <string>

#include "../types/LogType.h"

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

    void WriteLog(LogType_t logType, std::string str);
    std::string GenerateLogName();
};

#endif