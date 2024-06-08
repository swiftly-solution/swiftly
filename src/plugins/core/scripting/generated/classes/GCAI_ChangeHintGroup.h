class GCAI_ChangeHintGroup;

#ifndef _gccai_changehintgroup_h
#define _gccai_changehintgroup_h

#include "../../../scripting.h"




class GCAI_ChangeHintGroup
{
private:
    void *m_ptr;

public:
    GCAI_ChangeHintGroup() {}
    GCAI_ChangeHintGroup(void *ptr) : m_ptr(ptr) {}

    int32_t GetSearchType() const { return GetSchemaValue<int32_t>(m_ptr, "CAI_ChangeHintGroup", "m_iSearchType"); }
    void SetSearchType(int32_t value) { SetSchemaValue(m_ptr, "CAI_ChangeHintGroup", "m_iSearchType", false, value); }
    CUtlSymbolLarge GetStrSearchName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAI_ChangeHintGroup", "m_strSearchName"); }
    void SetStrSearchName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CAI_ChangeHintGroup", "m_strSearchName", false, value); }
    CUtlSymbolLarge GetStrNewHintGroup() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAI_ChangeHintGroup", "m_strNewHintGroup"); }
    void SetStrNewHintGroup(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CAI_ChangeHintGroup", "m_strNewHintGroup", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CAI_ChangeHintGroup", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CAI_ChangeHintGroup", "m_flRadius", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif