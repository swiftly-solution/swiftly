class GCAnimationGraphVisualizerText;

#ifndef _gccanimationgraphvisualizertext_h
#define _gccanimationgraphvisualizertext_h

#include "../../../scripting.h"




class GCAnimationGraphVisualizerText
{
private:
    void *m_ptr;

public:
    GCAnimationGraphVisualizerText() {}
    GCAnimationGraphVisualizerText(void *ptr) : m_ptr(ptr) {}

    Vector GetWsPosition() const { return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerText", "m_vWsPosition"); }
    void SetWsPosition(Vector value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerText", "m_vWsPosition", false, value); }
    Color GetColor() const { return GetSchemaValue<Color>(m_ptr, "CAnimationGraphVisualizerText", "m_Color"); }
    void SetColor(Color value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerText", "m_Color", false, value); }
    CUtlString GetText() const { return GetSchemaValue<CUtlString>(m_ptr, "CAnimationGraphVisualizerText", "m_Text"); }
    void SetText(CUtlString value) { SetSchemaValue(m_ptr, "CAnimationGraphVisualizerText", "m_Text", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif