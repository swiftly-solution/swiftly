class GCSoundOpvarSetPointBase;

#ifndef _gccsoundopvarsetpointbase_h
#define _gccsoundopvarsetpointbase_h

#include "../../../scripting.h"


#include "GCEntityInstance.h"

class GCSoundOpvarSetPointBase
{
private:
    void *m_ptr;

public:
    GCSoundOpvarSetPointBase() {}
    GCSoundOpvarSetPointBase(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CSoundOpvarSetPointBase", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_bDisabled", false, value); }
    GCEntityInstance* GetSource() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CSoundOpvarSetPointBase", "m_hSource"); }
    void SetSource(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Source' is not possible.\n"); }
    CUtlSymbolLarge GetSourceEntityName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPointBase", "m_iszSourceEntityName"); }
    void SetSourceEntityName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_iszSourceEntityName", false, value); }
    Vector GetLastPosition() const { return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetPointBase", "m_vLastPosition"); }
    void SetLastPosition(Vector value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_vLastPosition", false, value); }
    CUtlSymbolLarge GetStackName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPointBase", "m_iszStackName"); }
    void SetStackName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_iszStackName", false, value); }
    CUtlSymbolLarge GetOperatorName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPointBase", "m_iszOperatorName"); }
    void SetOperatorName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_iszOperatorName", false, value); }
    CUtlSymbolLarge GetOpvarName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPointBase", "m_iszOpvarName"); }
    void SetOpvarName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_iszOpvarName", false, value); }
    int32_t GetOpvarIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetPointBase", "m_iOpvarIndex"); }
    void SetOpvarIndex(int32_t value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_iOpvarIndex", false, value); }
    bool GetUseAutoCompare() const { return GetSchemaValue<bool>(m_ptr, "CSoundOpvarSetPointBase", "m_bUseAutoCompare"); }
    void SetUseAutoCompare(bool value) { SetSchemaValue(m_ptr, "CSoundOpvarSetPointBase", "m_bUseAutoCompare", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif