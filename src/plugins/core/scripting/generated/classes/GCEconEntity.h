class GCEconEntity;

#ifndef _gcceconentity_h
#define _gcceconentity_h

#include "../../../scripting.h"


#include "GCAttributeContainer.h"
#include "GCBaseEntity.h"

class GCEconEntity
{
private:
    void *m_ptr;

public:
    GCEconEntity() {}
    GCEconEntity(void *ptr) : m_ptr(ptr) {}

    GCAttributeContainer GetAttributeManager() const { return GetSchemaValue<GCAttributeContainer>(m_ptr, "CEconEntity", "m_AttributeManager"); }
    void SetAttributeManager(GCAttributeContainer value) { SetSchemaValue(m_ptr, "CEconEntity", "m_AttributeManager", false, value); }
    uint32_t GetOriginalOwnerXuidLow() const { return GetSchemaValue<uint32_t>(m_ptr, "CEconEntity", "m_OriginalOwnerXuidLow"); }
    void SetOriginalOwnerXuidLow(uint32_t value) { SetSchemaValue(m_ptr, "CEconEntity", "m_OriginalOwnerXuidLow", false, value); }
    uint32_t GetOriginalOwnerXuidHigh() const { return GetSchemaValue<uint32_t>(m_ptr, "CEconEntity", "m_OriginalOwnerXuidHigh"); }
    void SetOriginalOwnerXuidHigh(uint32_t value) { SetSchemaValue(m_ptr, "CEconEntity", "m_OriginalOwnerXuidHigh", false, value); }
    int32_t GetFallbackPaintKit() const { return GetSchemaValue<int32_t>(m_ptr, "CEconEntity", "m_nFallbackPaintKit"); }
    void SetFallbackPaintKit(int32_t value) { SetSchemaValue(m_ptr, "CEconEntity", "m_nFallbackPaintKit", false, value); }
    int32_t GetFallbackSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CEconEntity", "m_nFallbackSeed"); }
    void SetFallbackSeed(int32_t value) { SetSchemaValue(m_ptr, "CEconEntity", "m_nFallbackSeed", false, value); }
    float GetFallbackWear() const { return GetSchemaValue<float>(m_ptr, "CEconEntity", "m_flFallbackWear"); }
    void SetFallbackWear(float value) { SetSchemaValue(m_ptr, "CEconEntity", "m_flFallbackWear", false, value); }
    int32_t GetFallbackStatTrak() const { return GetSchemaValue<int32_t>(m_ptr, "CEconEntity", "m_nFallbackStatTrak"); }
    void SetFallbackStatTrak(int32_t value) { SetSchemaValue(m_ptr, "CEconEntity", "m_nFallbackStatTrak", false, value); }
    GCBaseEntity* GetOldProvidee() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CEconEntity", "m_hOldProvidee"); }
    void SetOldProvidee(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'OldProvidee' is not possible.\n"); }
    int32_t GetOldOwnerClass() const { return GetSchemaValue<int32_t>(m_ptr, "CEconEntity", "m_iOldOwnerClass"); }
    void SetOldOwnerClass(int32_t value) { SetSchemaValue(m_ptr, "CEconEntity", "m_iOldOwnerClass", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif