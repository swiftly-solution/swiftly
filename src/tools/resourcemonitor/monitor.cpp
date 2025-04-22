#include "monitor.h"

void ResourceMonitor::Enable()
{
    resmonTimesTable.clear();
    m_status = true;
}

void ResourceMonitor::Disable()
{
    m_status = false;
    resmonTimesTable.clear();
}

bool ResourceMonitor::IsEnabled()
{
    return m_status;
}

std::map<std::string, std::map<std::string, std::vector<float>>> ResourceMonitor::GetResmonTimeTables()
{
    return resmonTimesTable;
}

void ResourceMonitor::RecordTime(std::string plugin_id, std::string key, float value)
{
    if (!m_status) return;

    if (resmonTimesTable.find(plugin_id) == resmonTimesTable.end())
        resmonTimesTable.insert({ plugin_id, {} });

    if (resmonTimesTable[plugin_id].find(key) == resmonTimesTable[plugin_id].end())
        resmonTimesTable[plugin_id].insert({ key, {} });

    resmonTimesTable[plugin_id][key].push_back(value);
}

void ResourceMonitor::StartTime(std::string plugin_id, std::string key)
{
    if (!m_status) return;

    if (resmonTempTables.find(plugin_id) == resmonTempTables.end())
        resmonTempTables.insert({ plugin_id, {} });

    resmonTempTables[plugin_id].insert_or_assign(key, std::chrono::high_resolution_clock::now());
}

void ResourceMonitor::StopTime(std::string plugin_id, std::string key)
{
    if (!m_status) return;

    if (resmonTempTables.find(plugin_id) == resmonTempTables.end()) return;
    if (resmonTempTables[plugin_id].find(key) == resmonTempTables[plugin_id].end()) return;

    RecordTime(plugin_id, key, float(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - resmonTempTables[plugin_id][key]).count()) / 1000.0);
}