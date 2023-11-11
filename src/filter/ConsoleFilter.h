#ifndef _consolefilter_h
#define _consolefilter_h

#include <map>
#include <string>
#include "../common.h"

class ConsoleFilter
{
private:
    bool m_status = false;
    std::map<std::string, std::string> filter;
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