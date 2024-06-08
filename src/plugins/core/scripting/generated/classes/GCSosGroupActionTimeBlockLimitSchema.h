class GCSosGroupActionTimeBlockLimitSchema;

#ifndef _gccsosgroupactiontimeblocklimitschema_h
#define _gccsosgroupactiontimeblocklimitschema_h

#include "../../../scripting.h"




class GCSosGroupActionTimeBlockLimitSchema
{
private:
    void *m_ptr;

public:
    GCSosGroupActionTimeBlockLimitSchema() {}
    GCSosGroupActionTimeBlockLimitSchema(void *ptr) : m_ptr(ptr) {}

    int32_t GetMaxCount() const { return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionTimeBlockLimitSchema", "m_nMaxCount"); }
    void SetMaxCount(int32_t value) { SetSchemaValue(m_ptr, "CSosGroupActionTimeBlockLimitSchema", "m_nMaxCount", false, value); }
    float GetMaxDuration() const { return GetSchemaValue<float>(m_ptr, "CSosGroupActionTimeBlockLimitSchema", "m_flMaxDuration"); }
    void SetMaxDuration(float value) { SetSchemaValue(m_ptr, "CSosGroupActionTimeBlockLimitSchema", "m_flMaxDuration", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif