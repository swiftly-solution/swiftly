class GCBoneVelocityMetricEvaluator;

#ifndef _gccbonevelocitymetricevaluator_h
#define _gccbonevelocitymetricevaluator_h

#include "../../../scripting.h"




class GCBoneVelocityMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCBoneVelocityMetricEvaluator() {}
    GCBoneVelocityMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    int32_t GetBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CBoneVelocityMetricEvaluator", "m_nBoneIndex"); }
    void SetBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "CBoneVelocityMetricEvaluator", "m_nBoneIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif