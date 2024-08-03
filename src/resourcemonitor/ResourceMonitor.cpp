#include "ResourceMonitor.h"
#include <thread>
#include "../common.h"

void ResourceMonitor::Enable()
{
    if (this->m_enabled)
        return;

    this->m_enabled = true;
}

void ResourceMonitor::Disable()
{
    if (!this->m_enabled)
        return;

    this->m_enabled = false;
    this->resmonTimesTable.clear();
}

void ResourceMonitor::RecordTime(std::string plugin_id, std::string key, float value)
{
    if (this->resmonTimesTable.find(plugin_id) == this->resmonTimesTable.end())
        this->resmonTimesTable.insert({plugin_id, {}});

    if (this->resmonTimesTable[plugin_id].find(key) == this->resmonTimesTable[plugin_id].end())
        this->resmonTimesTable[plugin_id].insert({key, {}});

    this->resmonTimesTable[plugin_id][key].push_back(value);
}