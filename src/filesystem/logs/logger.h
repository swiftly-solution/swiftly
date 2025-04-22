#ifndef _logger_h
#define _logger_h

#include <map>
#include <string>
#include <server/configuration/configuration.h>

#include "log.h"

class Logger
{
private:
    std::map<std::string, Log*> m_Loggers;

public:
    Log* FetchLogger(std::string key);
    void AddLogger(std::string key, bool plugin);
    void RemoveLogger(std::string key);
};

extern Logger g_Logger;

#endif