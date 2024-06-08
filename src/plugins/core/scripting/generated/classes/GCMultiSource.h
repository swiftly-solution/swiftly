class GCMultiSource;

#ifndef _gccmultisource_h
#define _gccmultisource_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"

class GCMultiSource
{
private:
    void *m_ptr;

public:
    GCMultiSource() {}
    GCMultiSource(void *ptr) : m_ptr(ptr) {}

    GCBaseEntity* GetRgEntities() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CMultiSource", "m_rgEntities"); }
    void SetRgEntities(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'RgEntities' is not possible.\n"); }
    std::vector<int32_t> GetRgTriggered() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMultiSource", "m_rgTriggered"); std::vector<int32_t> ret; for(int i = 0; i < 32; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetRgTriggered(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CMultiSource", "m_rgTriggered"); for(int i = 0; i < 32; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMultiSource", "m_rgTriggered", false, outValue); }
    GCEntityIOOutput GetOnTrigger() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CMultiSource", "m_OnTrigger"); }
    void SetOnTrigger(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CMultiSource", "m_OnTrigger", false, value); }
    int32_t GetTotal() const { return GetSchemaValue<int32_t>(m_ptr, "CMultiSource", "m_iTotal"); }
    void SetTotal(int32_t value) { SetSchemaValue(m_ptr, "CMultiSource", "m_iTotal", false, value); }
    CUtlSymbolLarge GetGlobalstate() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CMultiSource", "m_globalstate"); }
    void SetGlobalstate(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CMultiSource", "m_globalstate", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif