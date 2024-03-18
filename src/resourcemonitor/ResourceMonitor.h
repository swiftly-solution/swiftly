#ifndef _resourcemonitor_h
#define _resourcemonitor_h

#include <map>
#include <set>
#include <string>

class ResourceMonitor
{
private:
    bool m_enabled = false;
    std::map<std::string, std::map<std::string, std::set<float>>> resmonTimesTable;

public:
    ResourceMonitor() {}

    void Enable();
    void Disable();
    bool IsEnabled() { return this->m_enabled; }
    void RecordTime(std::string plugin_id, std::string key, float value);

    std::map<std::string, std::map<std::string, std::set<float>>> GetResmonTimeTables() { return this->resmonTimesTable; }
};

extern ResourceMonitor *g_ResourceMonitor;

#endif