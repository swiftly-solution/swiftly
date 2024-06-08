class GCCurrentRotationVelocityMetricEvaluator;

#ifndef _gcccurrentrotationvelocitymetricevaluator_h
#define _gcccurrentrotationvelocitymetricevaluator_h

#include "../../../scripting.h"




class GCCurrentRotationVelocityMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCCurrentRotationVelocityMetricEvaluator() {}
    GCCurrentRotationVelocityMetricEvaluator(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif