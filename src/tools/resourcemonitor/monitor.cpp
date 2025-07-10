#include "monitor.h"

#include <memory/encoders/json.h>
#include <utils/utils.h>
#include <algorithm>

void ResourceMonitor::Enable()
{
    profilerEvents.clear();
    resmonTimesTable.clear();
    m_status = true;
}

void ResourceMonitor::Disable()
{
    m_status = false;
    resmonTimesTable.clear();
    profilerEvents.clear();
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

    auto registered_timestamp = std::chrono::high_resolution_clock::now();
    resmonTempTables[plugin_id].insert_or_assign(key, registered_timestamp);

    RecordInfo info;
    info.event = 'B';
    info.timestamp = std::chrono::duration_cast<std::chrono::microseconds>(registered_timestamp.time_since_epoch()).count();
    info.name = key;
    info.plugin_name = plugin_id;

    profilerEvents.push_back(info);
}

void ResourceMonitor::StopTime(std::string plugin_id, std::string key)
{
    if (!m_status) return;

    if (resmonTempTables.find(plugin_id) == resmonTempTables.end()) return;
    if (resmonTempTables[plugin_id].find(key) == resmonTempTables[plugin_id].end()) return;

    auto registered_timestamp = std::chrono::high_resolution_clock::now();
    RecordTime(plugin_id, key, float(std::chrono::duration_cast<std::chrono::microseconds>(registered_timestamp - resmonTempTables[plugin_id][key]).count()) / 1000.0);

    RecordInfo info;
    info.event = 'E';
    info.timestamp = std::chrono::duration_cast<std::chrono::microseconds>(registered_timestamp.time_since_epoch()).count();
    info.name = key;
    info.plugin_name = plugin_id;

    profilerEvents.push_back(info);
}

std::string ResourceMonitor::GenerateJSONPerformance(std::string plugin_id)
{
    rapidjson::Document doc(rapidjson::kArrayType);

    rapidjson::Document v1 = encoders::json::FromString("{\"args\": {\"name\": \"Swiftly\"},\"cat\": \"__metadata\",\"name\": \"process_name\",\"ph\": \"M\",\"pid\": 1,\"tid\": 1,\"ts\": 0}");
    doc.PushBack(v1, doc.GetAllocator());
    rapidjson::Document v2 = encoders::json::FromString("{\"args\":{\"name\":\"Swiftly Main\"},\"cat\":\"__metadata\",\"name\":\"thread_name\",\"ph\":\"M\",\"pid\":1,\"tid\":1,\"ts\":0}");
    doc.PushBack(v2, doc.GetAllocator());
    rapidjson::Document v3 = encoders::json::FromString("{\"args\":{\"name\":\"Swiftly Profiler\"},\"cat\":\"__metadata\",\"name\":\"thread_name\",\"ph\":\"M\",\"pid\":1,\"tid\":2,\"ts\":0}");
    doc.PushBack(v3, doc.GetAllocator());

    auto timings = profilerEvents;
    auto iter_end = timings.end();

    std::map<std::string, std::map<std::string, std::string>> cacheItems;

    for (auto it = timings.begin(); it != iter_end; ++it) {
        auto record = *it;
        if (plugin_id == "" || plugin_id == record.plugin_name) {
            auto event_name = cacheItems[record.plugin_name][record.name];
            if (event_name == "") {
                auto calls = resmonTimesTable[record.plugin_name][record.name];
                auto [min, max] = std::minmax_element(calls.begin(), calls.end());

                float avg = 0;
                for (std::vector<float>::iterator ii = calls.begin(); ii != calls.end(); ++ii)
                    avg += *(ii);

                avg /= (float)calls.size();

                std::string evname = string_format("%s [%s] (min=%s,avg=%s,max=%s,count=%llu)",
                    record.name.c_str(), record.plugin_name.c_str(),
                    (*min) < 0.5 ? string_format("%d.00μs", (uint64_t)((*min) * 1000.0f)).c_str() : string_format("%.2fms", *min).c_str(),
                    avg < 0.5 ? string_format("%d.00μs", (uint64_t)(avg * 1000.0f)).c_str() : string_format("%.2fms", avg).c_str(),
                    (*max) < 0.5 ? string_format("%d.00μs", (uint64_t)((*max) * 1000.0f)).c_str() : string_format("%.2fms", *max).c_str(),
                    calls.size()
                );

                cacheItems[record.plugin_name][record.name] = evname;
                event_name = evname;
            }

            rapidjson::Value val(rapidjson::kObjectType);
            val.AddMember("name", rapidjson::Value().SetString(event_name.c_str(), doc.GetAllocator()), doc.GetAllocator());
            val.AddMember("ph", rapidjson::Value().SetString(record.event == 'B' ? "B" : "E", doc.GetAllocator()), doc.GetAllocator());
            val.AddMember("tid", rapidjson::Value().SetInt(2), doc.GetAllocator());
            val.AddMember("pid", rapidjson::Value().SetInt(1), doc.GetAllocator());
            val.AddMember("ts", rapidjson::Value().SetUint64(record.timestamp), doc.GetAllocator());
            doc.PushBack(val, doc.GetAllocator());
        }
    }

    return std::string("{\"traceEvents\":") + encoders::json::ToString(doc) + "}";
}