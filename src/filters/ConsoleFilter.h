#ifndef _consolefilter_h
#define _consolefilter_h

#include <map>
#include <string>
#include <regex>
#include "../entrypoint.h"
#include "../common.h"

void Hook_LoggingSystem_LogDirect(int, int, const char *, ...);
void Hook_LoggingSystem_Log(int, int, const char *, ...);
void Hook_LoggingSystem_LogAssert(const char *, ...);
void Hook_Msg(const char *, ...);
void Hook_Warning(const char *, ...);

class ConsoleFilter
{
private:
    bool m_status = false;
    std::map<std::string, std::regex> filter;
    std::map<std::string, uint64> counter;

public:
    ConsoleFilter() {}

    void LoadFilters();
    void Toggle();
    bool NeedFiltering(std::string message);
    std::map<std::string, uint64> GetCounters() { return this->counter; }

    bool Status() { return this->m_status; }
};

extern ConsoleFilter *g_conFilter;

#endif