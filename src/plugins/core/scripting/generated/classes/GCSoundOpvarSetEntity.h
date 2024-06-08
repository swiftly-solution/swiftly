class GCSoundOpvarSetEntity;

#ifndef _gccsoundopvarsetentity_h
#define _gccsoundopvarsetentity_h

#include "../../../scripting.h"




class GCSoundOpvarSetEntity
{
private:
    void *m_ptr;

public:
    GCSoundOpvarSetEntity() {}
    GCSoundOpvarSetEntity(void *ptr) : m_ptr(ptr) {}

    CUtlSymbolLarge GetStackName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetEntity", "m_iszStackName"); }
    void SetStackName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_iszStackName", false, value); }
    CUtlSymbolLarge GetOperatorName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetEntity", "m_iszOperatorName"); }
    void SetOperatorName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_iszOperatorName", false, value); }
    CUtlSymbolLarge GetOpvarName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetEntity", "m_iszOpvarName"); }
    void SetOpvarName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_iszOpvarName", false, value); }
    int32_t GetOpvarType() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetEntity", "m_nOpvarType"); }
    void SetOpvarType(int32_t value) { SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_nOpvarType", false, value); }
    int32_t GetOpvarIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetEntity", "m_nOpvarIndex"); }
    void SetOpvarIndex(int32_t value) { SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_nOpvarIndex", false, value); }
    float GetOpvarValue() const { return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetEntity", "m_flOpvarValue"); }
    void SetOpvarValue(float value) { SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_flOpvarValue", false, value); }
    CUtlSymbolLarge GetOpvarValueString() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetEntity", "m_OpvarValueString"); }
    void SetOpvarValueString(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_OpvarValueString", false, value); }
    bool GetSetOnSpawn() const { return GetSchemaValue<bool>(m_ptr, "CSoundOpvarSetEntity", "m_bSetOnSpawn"); }
    void SetSetOnSpawn(bool value) { SetSchemaValue(m_ptr, "CSoundOpvarSetEntity", "m_bSetOnSpawn", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif