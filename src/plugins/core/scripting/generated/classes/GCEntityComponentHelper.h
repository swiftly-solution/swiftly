class GCEntityComponentHelper;

#ifndef _gccentitycomponenthelper_h
#define _gccentitycomponenthelper_h

#include "../../../scripting.h"


#include "GEntComponentInfo_t.h"
#include "GCEntityComponent.h"
#include "GCEntityComponentHelper.h"

class GCEntityComponentHelper
{
private:
    void *m_ptr;

public:
    GCEntityComponentHelper() {}
    GCEntityComponentHelper(void *ptr) : m_ptr(ptr) {}

    uint32_t GetFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "CEntityComponentHelper", "m_flags"); }
    void SetFlags(uint32_t value) { SetSchemaValue(m_ptr, "CEntityComponentHelper", "m_flags", false, value); }
    GEntComponentInfo_t* GetInfo() const { return GetSchemaValue<GEntComponentInfo_t*>(m_ptr, "CEntityComponentHelper", "m_pInfo"); }
    void SetInfo(GEntComponentInfo_t* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Info' is not possible.\n"); }
    int32_t GetPriority() const { return GetSchemaValue<int32_t>(m_ptr, "CEntityComponentHelper", "m_nPriority"); }
    void SetPriority(int32_t value) { SetSchemaValue(m_ptr, "CEntityComponentHelper", "m_nPriority", false, value); }
    GCEntityComponentHelper* GetNext() const { return GetSchemaValue<GCEntityComponentHelper*>(m_ptr, "CEntityComponentHelper", "m_pNext"); }
    void SetNext(GCEntityComponentHelper* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif