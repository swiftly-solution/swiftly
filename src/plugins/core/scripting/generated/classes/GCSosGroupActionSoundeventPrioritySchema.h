class GCSosGroupActionSoundeventPrioritySchema;

#ifndef _gccsosgroupactionsoundeventpriorityschema_h
#define _gccsosgroupactionsoundeventpriorityschema_h

#include "../../../scripting.h"




class GCSosGroupActionSoundeventPrioritySchema
{
private:
    void *m_ptr;

public:
    GCSosGroupActionSoundeventPrioritySchema() {}
    GCSosGroupActionSoundeventPrioritySchema(void *ptr) : m_ptr(ptr) {}

    CUtlString GetPriorityValue() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityValue"); }
    void SetPriorityValue(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityValue", false, value); }
    CUtlString GetPriorityVolumeScalar() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityVolumeScalar"); }
    void SetPriorityVolumeScalar(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityVolumeScalar", false, value); }
    CUtlString GetPriorityContributeButDontRead() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityContributeButDontRead"); }
    void SetPriorityContributeButDontRead(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_priorityContributeButDontRead", false, value); }
    CUtlString GetPriorityReadButDontContribute() const { return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_bPriorityReadButDontContribute"); }
    void SetPriorityReadButDontContribute(CUtlString value) { SetSchemaValue(m_ptr, "CSosGroupActionSoundeventPrioritySchema", "m_bPriorityReadButDontContribute", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif