#ifndef _resourcemonitor_h
#define _resourcemonitor_h

#include <map>
#include <list>
#include <string>
#include <chrono>

#define PERF_RECORD(key, plugin_id)     \
    if (g_ResourceMonitor->IsEnabled()) \
        TempResMon djhgbjswefseiughwsoeirfwoietfiwoer(key, plugin_id);

class ResourceMonitor
{
private:
    bool m_enabled = false;
    std::map<std::string, std::map<std::string, std::list<float>>> resmonTimesTable;

public:
    ResourceMonitor() {}

    void Enable();
    void Disable();
    bool IsEnabled() { return this->m_enabled; }
    void RecordTime(std::string plugin_id, std::string key, float value);

    std::map<std::string, std::map<std::string, std::list<float>>> GetResmonTimeTables() { return this->resmonTimesTable; }
};

extern ResourceMonitor* g_ResourceMonitor;

class TempResMon
{
private:
    std::string m_plugin_id;
    std::string m_key;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime = std::chrono::high_resolution_clock::now();

public:
    TempResMon(std::string key, std::string plugin_id)
    {
        m_plugin_id = plugin_id;
        m_key = key;
        startTime = std::chrono::high_resolution_clock::now();
    }

    ~TempResMon()
    {
        g_ResourceMonitor->RecordTime(m_plugin_id, m_key, float(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - startTime).count()) / 1000.0);
    }
};

#endif