#include "monitor.h"

#include <memory/encoders/json.h>
#include <utils/utils.h>
#include <algorithm>

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

std::string ResourceMonitor::GenerateJSONPerformance(std::string plugin_id)
{
    rapidjson::Document doc(rapidjson::kArrayType);

    rapidjson::Document v1 = encoders::json::FromString("{\"args\": {\"name\": \"Swiftly\"},\"cat\": \"__metadata\",\"name\": \"process_name\",\"ph\": \"M\",\"pid\": 1,\"tid\": 1,\"ts\": 0}");
    doc.PushBack(v1, doc.GetAllocator());
    rapidjson::Document v2 = encoders::json::FromString("{\"args\":{\"name\":\"Swiftly Main\"},\"cat\":\"__metadata\",\"name\":\"thread_name\",\"ph\":\"M\",\"pid\":1,\"tid\":1,\"ts\":0}");
    doc.PushBack(v2, doc.GetAllocator());
    rapidjson::Document v3 = encoders::json::FromString("{\"args\":{\"name\":\"Swiftly Profiler\"},\"cat\":\"__metadata\",\"name\":\"thread_name\",\"ph\":\"M\",\"pid\":1,\"tid\":2,\"ts\":0}");
    doc.PushBack(v3, doc.GetAllocator());

    uint64_t t = 0;
    auto timings = GetResmonTimeTables();
    if (plugin_id == "") {
        for (auto it = timings.begin(); it != timings.end(); ++it) {
            for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {

                auto [min, max] = std::minmax_element(it2->second.begin(), it2->second.end());

                float avg = 0;
                uint64_t avgCount = 0;
                for (std::vector<float>::iterator ii = it2->second.begin(); ii != it2->second.end(); ++ii)
                {
                    avg += *(ii);
                    ++avgCount;
                }

                avg /= (float)(avgCount);

                std::string event_name = string_format("%s [%s] (min=%s, avg=%s, max=%s, calls=%d)",
                    it2->first.c_str(), it->first.c_str(),
                    (*min) < 0.5 ? string_format("%d.00μs", (uint64_t)((*min) * 1000.0f)).c_str() : string_format("%.2fms", *min).c_str(),
                    avg < 0.5 ? string_format("%d.00μs", (uint64_t)(avg * 1000.0f)).c_str() : string_format("%.2fms", avg).c_str(),
                    (*max) < 0.5 ? string_format("%d.00μs", (uint64_t)((*max) * 1000.0f)).c_str() : string_format("%.2fms", *max).c_str(),
                    it2->second.size()
                );

                for (float time : it2->second) {
                    uint64_t uint_time = (uint64_t)(time * 1000.0f);

                    rapidjson::Value val(rapidjson::kObjectType);
                    rapidjson::Value val2(rapidjson::kObjectType);

                    t++;

                    val.AddMember("name", rapidjson::Value().SetString(event_name.c_str(), doc.GetAllocator()), doc.GetAllocator());
                    val.AddMember("ph", rapidjson::Value().SetString("B", doc.GetAllocator()), doc.GetAllocator());
                    val.AddMember("tid", rapidjson::Value().SetInt(2), doc.GetAllocator());
                    val.AddMember("pid", rapidjson::Value().SetInt(1), doc.GetAllocator());
                    val.AddMember("ts", rapidjson::Value().SetUint64(t), doc.GetAllocator());

                    doc.PushBack(val, doc.GetAllocator());

                    t += uint_time;

                    val2.AddMember("name", rapidjson::Value().SetString(event_name.c_str(), doc.GetAllocator()), doc.GetAllocator());
                    val2.AddMember("ph", rapidjson::Value().SetString("E", doc.GetAllocator()), doc.GetAllocator());
                    val2.AddMember("tid", rapidjson::Value().SetInt(2), doc.GetAllocator());
                    val2.AddMember("pid", rapidjson::Value().SetInt(1), doc.GetAllocator());
                    val2.AddMember("ts", rapidjson::Value().SetUint64(t), doc.GetAllocator());

                    doc.PushBack(val2, doc.GetAllocator());
                }
            }
        }
    }
    else {
        for (auto it2 = timings[plugin_id].begin(); it2 != timings[plugin_id].end(); ++it2) {
            auto [min, max] = std::minmax_element(it2->second.begin(), it2->second.end());

            float avg = 0;
            uint64_t avgCount = 0;
            for (std::vector<float>::iterator ii = it2->second.begin(); ii != it2->second.end(); ++ii)
            {
                avg += *(ii);
                ++avgCount;
            }

            avg /= (float)(avgCount);

            std::string event_name = string_format("%s (min=%s, avg=%s, max=%s, calls=%d)",
                it2->first.c_str(),
                (*min) < 0.5 ? string_format("%d.00μs", (uint64_t)((*min) * 1000.0f)).c_str() : string_format("%.2fms", *min).c_str(),
                avg < 0.5 ? string_format("%d.00μs", (uint64_t)(avg * 1000.0f)).c_str() : string_format("%.2fms", avg).c_str(),
                (*max) < 0.5 ? string_format("%d.00μs", (uint64_t)((*max) * 1000.0f)).c_str() : string_format("%.2fms", *max).c_str(),
                it2->second.size()
            );

            for (float time : it2->second) {
                uint64_t uint_time = (uint64_t)(time * 1000.0f);

                rapidjson::Value val(rapidjson::kObjectType);
                rapidjson::Value val2(rapidjson::kObjectType);

                t++;

                val.AddMember("name", rapidjson::Value().SetString(event_name.c_str(), doc.GetAllocator()), doc.GetAllocator());
                val.AddMember("ph", rapidjson::Value().SetString("B", doc.GetAllocator()), doc.GetAllocator());
                val.AddMember("tid", rapidjson::Value().SetInt(2), doc.GetAllocator());
                val.AddMember("pid", rapidjson::Value().SetInt(1), doc.GetAllocator());
                val.AddMember("ts", rapidjson::Value().SetUint64(t), doc.GetAllocator());

                doc.PushBack(val, doc.GetAllocator());

                t += uint_time;

                val2.AddMember("name", rapidjson::Value().SetString(event_name.c_str(), doc.GetAllocator()), doc.GetAllocator());
                val2.AddMember("ph", rapidjson::Value().SetString("E", doc.GetAllocator()), doc.GetAllocator());
                val2.AddMember("tid", rapidjson::Value().SetInt(2), doc.GetAllocator());
                val2.AddMember("pid", rapidjson::Value().SetInt(1), doc.GetAllocator());
                val2.AddMember("ts", rapidjson::Value().SetUint64(t), doc.GetAllocator());

                doc.PushBack(val2, doc.GetAllocator());
            }
        }
    }

    return std::string("{\"traceEvents\":") + encoders::json::ToString(doc) + "}";
}