#ifndef _swiftly_logger_h
#define _swiftly_logger_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "types.h"
#include "swiftly.h"
#include <string>
#include <cstdarg>

class Logger
{
private:
    std::string m_pluginName;
    bool canWrite = false;

public:
    Logger(const char *mainFilePath, const char *pluginName)
    {
        this->m_pluginName = pluginName;

        REGISTER_METHOD_VOID(scripting_Logger_CreateLogger, this->m_pluginName.c_str());
        this->canWrite = (ptr != nullptr);
    }

    void Write(ELogType log_type, const char *content, ...)
    {
        if (!this->canWrite)
            return;

        va_list ap;
        char buffer[4096];

        va_start(ap, content);
        UTIL_FormatArgs(buffer, sizeof(buffer), content, ap);
        va_end(ap);

        REGISTER_METHOD_VOID(scripting_Logger_WriteLog, this->m_pluginName.c_str(), log_type, buffer)
    }
};

extern Logger *logger;

#endif