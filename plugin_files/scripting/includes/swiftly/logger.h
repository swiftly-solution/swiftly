#ifndef _swiftly_logger_h
#define _swiftly_logger_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "types.h"
#include <string>

class Logger
{
private:
    std::string m_pluginName;
    bool canWrite = false;

public:
    Logger(const char *mainFilePath, const char *pluginName)
    {
        this->m_pluginName = pluginName;
        void *loggerCreateLog = FetchFunctionPtr(mainFilePath, "scripting_Logger_CreateLogger");
        if (loggerCreateLog)
        {
            reinterpret_cast<Logger_CreateLogger>(loggerCreateLog)(this->m_pluginName.c_str());
            this->canWrite = true;
        }
        else
            this->canWrite = false;
    }

    void Write(ELogType log_type, const char *content, ...)
    {
        if (!this->canWrite)
            return;

        void *loggerWriteLog = FetchFunctionPtr(nullptr, "scripting_Logger_WriteLog");
        if (loggerWriteLog)
        {
            va_list ap;
            char buffer[4096];

            va_start(ap, content);
            UTIL_FormatArgs(buffer, sizeof(buffer), content, ap);
            va_end(ap);

            reinterpret_cast<Logger_WriteLog>(loggerWriteLog)(this->m_pluginName.c_str(), log_type, buffer);
        }
    }
};

extern Logger *logger;

#endif