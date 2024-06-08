class GCTestEffect;

#ifndef _gcctesteffect_h
#define _gcctesteffect_h

#include "../../../scripting.h"


#include "GCBeam.h"

class GCTestEffect
{
private:
    void *m_ptr;

public:
    GCTestEffect() {}
    GCTestEffect(void *ptr) : m_ptr(ptr) {}

    int32_t GetLoop() const { return GetSchemaValue<int32_t>(m_ptr, "CTestEffect", "m_iLoop"); }
    void SetLoop(int32_t value) { SetSchemaValue(m_ptr, "CTestEffect", "m_iLoop", false, value); }
    int32_t GetBeam() const { return GetSchemaValue<int32_t>(m_ptr, "CTestEffect", "m_iBeam"); }
    void SetBeam(int32_t value) { SetSchemaValue(m_ptr, "CTestEffect", "m_iBeam", false, value); }
    std::vector<GCBeam*> GetBeam1() const { GCBeam** outValue = GetSchemaValue<GCBeam**>(m_ptr, "CTestEffect", "m_pBeam"); std::vector<GCBeam*> ret; for(int i = 0; i < 24; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetBeam1(std::vector<GCBeam*> value) { GCBeam** outValue = GetSchemaValue<GCBeam**>(m_ptr, "CTestEffect", "m_pBeam"); for(int i = 0; i < 24; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CTestEffect", "m_pBeam", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif