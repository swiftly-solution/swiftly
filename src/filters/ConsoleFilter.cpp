#include "ConsoleFilter.h"
#include "../common.h"
#include "../configuration/Configuration.h"

#include "../files/Files.h"
#include "../hooks/FuncHook.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

FuncHook<decltype(Hook_LoggingSystem_LogDirect)> LoggingSystemt_LogDirect(Hook_LoggingSystem_LogDirect, "LoggingSystem_LogDirect");
FuncHook<decltype(Hook_LoggingSystem_Log)> LoggingSystemt_Log(Hook_LoggingSystem_Log, "LoggingSystem_Log");
FuncHook<decltype(Hook_Msg)> TMsg(Hook_Msg, "Msg");
FuncHook<decltype(Hook_Warning)> TWarning(Hook_Warning, "Warning");
FuncHook<decltype(Hook_LoggingSystem_LogAssert)> LoggingSystemt_LogAssert(Hook_LoggingSystem_LogAssert, "LoggingSystem_LogAssert");

#define CHECKLOGS()                                                \
    va_list args;                                                  \
    char buffer[4096];                                             \
    va_start(args, message);                                       \
                                                                   \
    size_t len = vsnprintf(buffer, sizeof(buffer), message, args); \
    if (len >= sizeof(buffer))                                     \
    {                                                              \
        len = sizeof(buffer) - 1;                                  \
        buffer[len] = '\0';                                        \
    }                                                              \
    va_end(args);                                                  \
    if (g_conFilter->Status())                                     \
        if (g_conFilter->NeedFiltering(buffer))                    \
            return;

void Hook_LoggingSystem_LogDirect(int channelId, int severity, const char *message, ...)
{
    CHECKLOGS();
    LoggingSystemt_LogDirect(channelId, severity, buffer);
}

void Hook_LoggingSystem_Log(int channelId, int severity, const char *message, ...)
{
    CHECKLOGS();
    LoggingSystemt_Log(channelId, severity, buffer);
}

void Hook_LoggingSystem_LogAssert(const char *message, ...)
{
    CHECKLOGS();
    LoggingSystemt_LogAssert(buffer);
}

void Hook_Msg(const char *message, ...)
{
    CHECKLOGS()
    TMsg(buffer);
}

void Hook_Warning(const char *message, ...)
{
    CHECKLOGS()
    TWarning(buffer);
}

void ConFilterError(std::string text)
{
    if (!g_SMAPI)
        return;

    PRINTF("Console Filter", "%s\n", text.c_str());
}

void ConsoleFilter::Toggle()
{
    this->m_status = !this->m_status;
}

void ConsoleFilter::LoadFilters()
{
    this->filter.clear();
    this->counter.clear();

    rapidjson::Document confilterFile;
    confilterFile.Parse(Files::Read("addons/swiftly/configs/console_filter.json").c_str());
    if (confilterFile.HasParseError())
        return ConFilterError(string_format("A parsing error has been detected.\nError (offset %u): %s\n", (unsigned)confilterFile.GetErrorOffset(), GetParseError_En(confilterFile.GetParseError())));

    if (confilterFile.IsArray())
        return ConFilterError("Console filters file cannot be an array.");

    for (auto it = confilterFile.MemberBegin(); it != confilterFile.MemberEnd(); ++it)
    {
        std::string key = it->name.GetString();

        if (!it->value.IsString())
        {
            ConFilterError(string_format("The field \"%s\" is not a string.", key));
            continue;
        }

        this->filter.insert(std::make_pair(key, it->value.GetString()));
        this->counter.insert(std::make_pair(key, 0));
    }
}

bool ConsoleFilter::NeedFiltering(std::string message)
{
    if (!this->Status())
        return false;

    for (std::map<std::string, std::string>::iterator it = this->filter.begin(); it != this->filter.end(); ++it)
    {
        std::string key = it->first;
        std::string val = it->second;

        if (message.find(val) != std::string::npos)
        {
            if (this->counter.find(key) != this->counter.end())
                this->counter[key]++;
            return true;
        }
    }

    return false;
}