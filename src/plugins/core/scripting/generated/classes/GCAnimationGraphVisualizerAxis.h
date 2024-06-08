class GCAnimationGraphVisualizerAxis;

#ifndef _gccanimationgraphvisualizeraxis_h
#define _gccanimationgraphvisualizeraxis_h

#include "../../../scripting.h"




class GCAnimationGraphVisualizerAxis
{
private:
    void *m_ptr;

public:
    GCAnimationGraphVisualizerAxis() {}
    GCAnimationGraphVisualizerAxis(void *ptr) : m_ptr(ptr) {}

    float GetAxisSize() const { return GetSchemaValue<float>(m_ptr, "CAnimationGraphVisualizerAxis", "m_flAxisSize"); }
    void SetAxisSize(float value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerAxis", "m_flAxisSize", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif