class GCBlockSelectionMetricEvaluator;

#ifndef _gccblockselectionmetricevaluator_h
#define _gccblockselectionmetricevaluator_h

#include "../../../scripting.h"




class GCBlockSelectionMetricEvaluator
{
private:
    void *m_ptr;

public:
    GCBlockSelectionMetricEvaluator() {}
    GCBlockSelectionMetricEvaluator(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif