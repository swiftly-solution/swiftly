class GCSkillInt;

#ifndef _gccskillint_h
#define _gccskillint_h

#include "../../../scripting.h"




class GCSkillInt
{
private:
    void *m_ptr;

public:
    GCSkillInt() {}
    GCSkillInt(void *ptr) : m_ptr(ptr) {}

    std::vector<int32_t> GetValue() const { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSkillInt", "m_pValue"); std::vector<int32_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetValue(std::vector<int32_t> value) { int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CSkillInt", "m_pValue"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSkillInt", "m_pValue", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif