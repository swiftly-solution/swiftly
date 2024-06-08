class GCBonePositionMetricEvaluator;

#ifndef _gccbonepositionmetricevaluator_h
#define _gccbonepositionmetricevaluator_h

#include "../../../scripting.h"




class GCBonePositionMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCBonePositionMetricEvaluator() {}
    GCBonePositionMetricEvaluator(void *ptr) : m_ptr(ptr) {}

    int32_t GetBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CBonePositionMetricEvaluator", "m_nBoneIndex"); }
    void SetBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "CBonePositionMetricEvaluator", "m_nBoneIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif