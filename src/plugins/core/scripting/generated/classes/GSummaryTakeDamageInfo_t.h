class GSummaryTakeDamageInfo_t;

#ifndef _gcsummarytakedamageinfo_t_h
#define _gcsummarytakedamageinfo_t_h

#include "../../../scripting.h"


#include "GCTakeDamageInfo.h"
#include "GCTakeDamageResult.h"
#include "GCBaseEntity.h"

class GSummaryTakeDamageInfo_t
{
private:
    void *m_ptr;

public:
    GSummaryTakeDamageInfo_t() {}
    GSummaryTakeDamageInfo_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetSummarisedCount() const { return GetSchemaValue<int32_t>(m_ptr, "SummaryTakeDamageInfo_t", "nSummarisedCount"); }
    void SetSummarisedCount(int32_t value) { SetSchemaValue(m_ptr, "SummaryTakeDamageInfo_t", "nSummarisedCount", true, value); }
    GCTakeDamageInfo GetInfo() const { return GetSchemaValue<GCTakeDamageInfo>(m_ptr, "SummaryTakeDamageInfo_t", "info"); }
    void SetInfo(GCTakeDamageInfo value) { SetSchemaValue(m_ptr, "SummaryTakeDamageInfo_t", "info", true, value); }
    GCTakeDamageResult GetResult() const { return GetSchemaValue<GCTakeDamageResult>(m_ptr, "SummaryTakeDamageInfo_t", "result"); }
    void SetResult(GCTakeDamageResult value) { SetSchemaValue(m_ptr, "SummaryTakeDamageInfo_t", "result", true, value); }
    GCBaseEntity* GetTarget() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "SummaryTakeDamageInfo_t", "hTarget"); }
    void SetTarget(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif