class GCAnimationGraphVisualizerSphere;

#ifndef _gccanimationgraphvisualizersphere_h
#define _gccanimationgraphvisualizersphere_h

#include "../../../scripting.h"




class GCAnimationGraphVisualizerSphere
{
private:
    void *m_ptr;

public:
    GCAnimationGraphVisualizerSphere() {}
    GCAnimationGraphVisualizerSphere(void *ptr) : m_ptr(ptr) {}

    Vector GetWsPosition() const { return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerSphere", "m_vWsPosition"); }
    void SetWsPosition(Vector value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerSphere", "m_vWsPosition", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CAnimationGraphVisualizerSphere", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerSphere", "m_flRadius", false, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CAnimationGraphVisualizerSphere", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerSphere", "m_Color", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif