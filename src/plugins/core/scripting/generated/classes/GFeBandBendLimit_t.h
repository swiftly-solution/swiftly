class GFeBandBendLimit_t;

#ifndef _gcfebandbendlimit_t_h
#define _gcfebandbendlimit_t_h

#include "../../../scripting.h"




class GFeBandBendLimit_t
{
private:
    void *m_ptr;

public:
    GFeBandBendLimit_t() {}
    GFeBandBendLimit_t(void *ptr) : m_ptr(ptr) {}

    float GetDistMin() const { return GetSchemaValue<float>(m_ptr, "FeBandBendLimit_t", "flDistMin"); }
    void SetDistMin(float value) { SetSchemaValue(m_ptr, "FeBandBendLimit_t", "flDistMin", true, value); }
    float GetDistMax() const { return GetSchemaValue<float>(m_ptr, "FeBandBendLimit_t", "flDistMax"); }
    void SetDistMax(float value) { SetSchemaValue(m_ptr, "FeBandBendLimit_t", "flDistMax", true, value); }
    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeBandBendLimit_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 6; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeBandBendLimit_t", "nNode"); for(int i = 0; i < 6; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeBandBendLimit_t", "nNode", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif