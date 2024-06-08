class GCSosGroupActionLimitSchema;

#ifndef _gccsosgroupactionlimitschema_h
#define _gccsosgroupactionlimitschema_h

#include "../../../scripting.h"

#include "../types/GSosActionStopType_t.h"
#include "../types/GSosActionSortType_t.h"


class GCSosGroupActionLimitSchema
{
private:
    void *m_ptr;

public:
    GCSosGroupActionLimitSchema() {}
    GCSosGroupActionLimitSchema(void *ptr) : m_ptr(ptr) {}

    int32_t GetMaxCount() const { return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionLimitSchema", "m_nMaxCount"); }
    void SetMaxCount(int32_t value) { SetSchemaValue(m_ptr, "CSosGroupActionLimitSchema", "m_nMaxCount", false, value); }
    SosActionStopType_t GetStopType() const { return GetSchemaValue<SosActionStopType_t>(m_ptr, "CSosGroupActionLimitSchema", "m_nStopType"); }
    void SetStopType(SosActionStopType_t value) { SetSchemaValue(m_ptr, "CSosGroupActionLimitSchema", "m_nStopType", false, value); }
    SosActionSortType_t GetSortType() const { return GetSchemaValue<SosActionSortType_t>(m_ptr, "CSosGroupActionLimitSchema", "m_nSortType"); }
    void SetSortType(SosActionSortType_t value) { SetSchemaValue(m_ptr, "CSosGroupActionLimitSchema", "m_nSortType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif