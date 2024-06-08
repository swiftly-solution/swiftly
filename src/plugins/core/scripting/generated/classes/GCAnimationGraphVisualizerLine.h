class GCAnimationGraphVisualizerLine;

#ifndef _gccanimationgraphvisualizerline_h
#define _gccanimationgraphvisualizerline_h

#include "../../../scripting.h"




class GCAnimationGraphVisualizerLine
{
private:
    void *m_ptr;

public:
    GCAnimationGraphVisualizerLine() {}
    GCAnimationGraphVisualizerLine(void *ptr) : m_ptr(ptr) {}

    Vector GetWsPositionStart() const { return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerLine", "m_vWsPositionStart"); }
    void SetWsPositionStart(Vector value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerLine", "m_vWsPositionStart", false, value); }
    Vector GetWsPositionEnd() const { return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerLine", "m_vWsPositionEnd"); }
    void SetWsPositionEnd(Vector value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerLine", "m_vWsPositionEnd", false, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CAnimationGraphVisualizerLine", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerLine", "m_Color", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif