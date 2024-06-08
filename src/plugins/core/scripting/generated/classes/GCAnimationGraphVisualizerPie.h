class GCAnimationGraphVisualizerPie;

#ifndef _gccanimationgraphvisualizerpie_h
#define _gccanimationgraphvisualizerpie_h

#include "../../../scripting.h"




class GCAnimationGraphVisualizerPie
{
private:
    void *m_ptr;

public:
    GCAnimationGraphVisualizerPie() {}
    GCAnimationGraphVisualizerPie(void *ptr) : m_ptr(ptr) {}

    Vector GetWsCenter() const { return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsCenter"); }
    void SetWsCenter(Vector value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsCenter", false, value); }
    Vector GetWsStart() const { return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsStart"); }
    void SetWsStart(Vector value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsStart", false, value); }
    Vector GetWsEnd() const { return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsEnd"); }
    void SetWsEnd(Vector value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsEnd", false, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CAnimationGraphVisualizerPie", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPie", "m_Color", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif