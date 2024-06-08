class GCPointHurt;

#ifndef _gccpointhurt_h
#define _gccpointhurt_h

#include "../../../scripting.h"


#include "GCBaseEntity.h"

class GCPointHurt
{
private:
    void *m_ptr;

public:
    GCPointHurt() {}
    GCPointHurt(void *ptr) : m_ptr(ptr) {}

    int32_t GetDamage() const { return GetSchemaValue<int32_t>(m_ptr, "CPointHurt", "m_nDamage"); }
    void SetDamage(int32_t value) { SetSchemaValue(m_ptr, "CPointHurt", "m_nDamage", false, value); }
    int32_t GetBitsDamageType() const { return GetSchemaValue<int32_t>(m_ptr, "CPointHurt", "m_bitsDamageType"); }
    void SetBitsDamageType(int32_t value) { SetSchemaValue(m_ptr, "CPointHurt", "m_bitsDamageType", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CPointHurt", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CPointHurt", "m_flRadius", false, value); }
    float GetDelay() const { return GetSchemaValue<float>(m_ptr, "CPointHurt", "m_flDelay"); }
    void SetDelay(float value) { SetSchemaValue(m_ptr, "CPointHurt", "m_flDelay", false, value); }
    CUtlSymbolLarge GetStrTarget() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPointHurt", "m_strTarget"); }
    void SetStrTarget(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPointHurt", "m_strTarget", false, value); }
    GCBaseEntity* GetActivator() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CPointHurt", "m_pActivator"); }
    void SetActivator(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif