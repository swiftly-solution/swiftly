class GCSosGroupActionSetSoundeventParameterSchema;

#ifndef _gccsosgroupactionsetsoundeventparameterschema_h
#define _gccsosgroupactionsetsoundeventparameterschema_h

#include "../../../scripting.h"

#include "../types/GSosActionSortType_t.h"


class GCSosGroupActionSetSoundeventParameterSchema
{
private:
    void *m_ptr;

public:
    GCSosGroupActionSetSoundeventParameterSchema() {}
    GCSosGroupActionSetSoundeventParameterSchema(void *ptr) : m_ptr(ptr) {}

    int32_t GetMaxCount() const { return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_nMaxCount"); }
    void SetMaxCount(int32_t value) { SetSchemaValue(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_nMaxCount", false, value); }
    float GetMinValue() const { return GetSchemaValue<float>(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_flMinValue"); }
    void SetMinValue(float value) { SetSchemaValue(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_flMinValue", false, value); }
    float GetMaxValue() const { return GetSchemaValue<float>(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_flMaxValue"); }
    void SetMaxValue(float value) { SetSchemaValue(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_flMaxValue", false, value); }
    CUtlString GetOpvarName() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_opvarName"); }
    void SetOpvarName(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_opvarName", false, value); }
    SosActionSortType_t GetSortType() const { return GetSchemaValue<SosActionSortType_t>(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_nSortType"); }
    void SetSortType(SosActionSortType_t value) { SetSchemaValue(m_ptr, "CSosGroupActionSetSoundeventParameterSchema", "m_nSortType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif