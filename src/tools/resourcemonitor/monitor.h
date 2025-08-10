#ifndef _tools_resourcemonitor_monitor_h
#define _tools_resourcemonitor_monitor_h

#include <map>
#include <string>
#include <vector>
#include <chrono>
#include <queue>

struct RecordInfo
{
    char event;
    int64_t timestamp;
    std::string name;
    std::string plugin_name;
};

class ResourceMonitor
{
private:
    bool m_status = false;
    std::map<std::string, std::map<std::string, std::vector<float>>> resmonTimesTable;
    std::map<std::string, std::map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>>> resmonTempTables;
    std::vector<RecordInfo> profilerEvents;

public:
    void Enable();
    void Disable();
    bool IsEnabled();

    void RecordTime(std::string plugin_id, std::string key, float value);

    void StartTime(std::string plugin_id, std::string key);
    void StopTime(std::string plugin_id, std::string key);

    std::map<std::string, std::map<std::string, std::vector<float>>> GetResmonTimeTables();

    std::string GenerateJSONPerformance(std::string plugin_id = "");
};

extern ResourceMonitor g_ResourceMonitor;

#endif