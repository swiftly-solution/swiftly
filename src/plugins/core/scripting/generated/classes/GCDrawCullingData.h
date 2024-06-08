class GCDrawCullingData;

#ifndef _gccdrawcullingdata_h
#define _gccdrawcullingdata_h

#include "../../../scripting.h"




class GCDrawCullingData
{
private:
    void *m_ptr;

public:
    GCDrawCullingData() {}
    GCDrawCullingData(void *ptr) : m_ptr(ptr) {}

    Vector GetConeApex() const { return GetSchemaValue<Vector>(m_ptr, "CDrawCullingData", "m_vConeApex"); }
    void SetConeApex(Vector value) { SetSchemaValue(m_ptr, "CDrawCullingData", "m_vConeApex", false, value); }
    std::vector<int8_t> GetConeAxis() const { int8_t* outValue = GetSchemaValue<int8_t*>(m_ptr, "CDrawCullingData", "m_ConeAxis"); std::vector<int8_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetConeAxis(std::vector<int8_t> value) { int8_t* outValue = GetSchemaValue<int8_t*>(m_ptr, "CDrawCullingData", "m_ConeAxis"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CDrawCullingData", "m_ConeAxis", false, outValue); }
    int8_t GetConeCutoff() const { return GetSchemaValue<int8_t>(m_ptr, "CDrawCullingData", "m_ConeCutoff"); }
    void SetConeCutoff(int8_t value) { SetSchemaValue(m_ptr, "CDrawCullingData", "m_ConeCutoff", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif