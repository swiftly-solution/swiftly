class GCCurrentVelocityMetricEvaluator;

#ifndef _gcccurrentvelocitymetricevaluator_h
#define _gcccurrentvelocitymetricevaluator_h

#include "../../../scripting.h"




class GCCurrentVelocityMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCCurrentVelocityMetricEvaluator() {}
    GCCurrentVelocityMetricEvaluator(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif