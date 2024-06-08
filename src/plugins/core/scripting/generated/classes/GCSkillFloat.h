class GCSkillFloat;

#ifndef _gccskillfloat_h
#define _gccskillfloat_h

#include "../../../scripting.h"




class GCSkillFloat
{
private:
    void *m_ptr;

public:
    GCSkillFloat() {}
    GCSkillFloat(void *ptr) : m_ptr(ptr) {}

    std::vector<float> GetValue() const { float* outValue = GetSchemaValue<float*>(m_ptr, "CSkillFloat", "m_pValue"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetValue(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "CSkillFloat", "m_pValue"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSkillFloat", "m_pValue", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif