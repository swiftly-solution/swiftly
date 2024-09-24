#include "ConsoleFilter.h"
#include "../../common.h"
#include "../../server/configuration/Configuration.h"

#include "../resourcemonitor/ResourceMonitor.h"
#include "../../filesystem/files/Files.h"
#include "../../memory/hooks/FuncHook.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

FuncHook<decltype(Hook_CLoggingSystem_LogDirect)> CLoggingSystem_LogDirect(Hook_CLoggingSystem_LogDirect, "CLoggingSystem_LogDirect");

int Hook_CLoggingSystem_LogDirect(void* _this, int chan, int severity, LeafCodeInfo_t* leafCode, LoggingMetaData_t* meta, Color color, char const* str, va_list* args)
{
    if (!g_conFilter->Status()) return CLoggingSystem_LogDirect(_this, chan, severity, leafCode, meta, color, str, args);

    char buf[MAX_LOGGING_MESSAGE_LENGTH];

    if (args) {
        va_list cpargs;
        va_copy(cpargs, *args);
        V_vsnprintf(buf, sizeof(buf), str, cpargs);
        va_end(cpargs);
    }

    if (g_conFilter->NeedFiltering((args ? buf : str))) return 0;
    return CLoggingSystem_LogDirect(_this, chan, severity, leafCode, meta, color, str, args);
}

void ConFilterError(std::string text)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Console Filter", "%s\n", text.c_str());
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

        try
        {
            std::regex tmp(it->value.GetString(), std::regex_constants::ECMAScript | std::regex_constants::optimize | std::regex_constants::nosubs);
        }
        catch (const std::regex_error& err)
        {
            ConFilterError(string_format("The regex for \"%s\" is not valid.", key.c_str()));
            ConFilterError(string_format("Error: %s", err.what()));
            continue;
        }

        this->filter.insert({ key, std::regex(it->value.GetString(), std::regex_constants::ECMAScript | std::regex_constants::optimize | std::regex_constants::nosubs) });
        this->counter.insert({ key, 0 });
    }
}

bool ConsoleFilter::NeedFiltering(std::string message)
{
    if (!this->Status())
        return false;

    PERF_RECORD("Console Filter", "core");

    for (auto it = this->filter.begin(); it != this->filter.end(); ++it)
    {
        std::string key = it->first;
        std::regex val = it->second;

        if (std::regex_search(message, val))
        {
            this->counter[key]++;
            return true;
        }
    }

    return false;
}