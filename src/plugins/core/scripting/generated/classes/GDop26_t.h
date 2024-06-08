class GDop26_t;

#ifndef _gcdop26_t_h
#define _gcdop26_t_h

#include "../../../scripting.h"




class GDop26_t
{
private:
    void *m_ptr;

public:
    GDop26_t() {}
    GDop26_t(void *ptr) : m_ptr(ptr) {}

    std::vector<float> GetSupport() const { float* outValue = GetSchemaValue<float*>(m_ptr, "Dop26_t", "m_flSupport"); std::vector<float> ret; for(int i = 0; i < 26; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetSupport(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "Dop26_t", "m_flSupport"); for(int i = 0; i < 26; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "Dop26_t", "m_flSupport", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif