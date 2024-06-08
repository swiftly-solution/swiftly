class GCSosGroupActionTimeLimitSchema;

#ifndef _gccsosgroupactiontimelimitschema_h
#define _gccsosgroupactiontimelimitschema_h

#include "../../../scripting.h"




class GCSosGroupActionTimeLimitSchema
{
private:
    void *m_ptr;

public:
    GCSosGroupActionTimeLimitSchema() {}
    GCSosGroupActionTimeLimitSchema(void *ptr) : m_ptr(ptr) {}

    float GetMaxDuration() const { return GetSchemaValue<float>(m_ptr, "CSosGroupActionTimeLimitSchema", "m_flMaxDuration"); }
    void SetMaxDuration(float value) { SetSchemaValue(m_ptr, "CSosGroupActionTimeLimitSchema", "m_flMaxDuration", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif