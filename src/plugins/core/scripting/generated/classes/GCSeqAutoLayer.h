class GCSeqAutoLayer;

#ifndef _gccseqautolayer_h
#define _gccseqautolayer_h

#include "../../../scripting.h"


#include "GCSeqAutoLayerFlag.h"
#include "GCSeqAutoLayer.h"

class GCSeqAutoLayer
{
private:
    void *m_ptr;

public:
    GCSeqAutoLayer() {}
    GCSeqAutoLayer(void *ptr) : m_ptr(ptr) {}

    int16_t GetLocalReference() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqAutoLayer", "m_nLocalReference"); }
    void SetLocalReference(int16_t value) { SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_nLocalReference", false, value); }
    int16_t GetLocalPose() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqAutoLayer", "m_nLocalPose"); }
    void SetLocalPose(int16_t value) { SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_nLocalPose", false, value); }
    GCSeqAutoLayerFlag GetFlags() const { return GetSchemaValue<GCSeqAutoLayerFlag>(m_ptr, "CSeqAutoLayer", "m_flags"); }
    void SetFlags(GCSeqAutoLayerFlag value) { SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_flags", false, value); }
    float GetStart() const { return GetSchemaValue<float>(m_ptr, "CSeqAutoLayer", "m_start"); }
    void SetStart(float value) { SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_start", false, value); }
    float GetPeak() const { return GetSchemaValue<float>(m_ptr, "CSeqAutoLayer", "m_peak"); }
    void SetPeak(float value) { SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_peak", false, value); }
    float GetTail() const { return GetSchemaValue<float>(m_ptr, "CSeqAutoLayer", "m_tail"); }
    void SetTail(float value) { SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_tail", false, value); }
    float GetEnd() const { return GetSchemaValue<float>(m_ptr, "CSeqAutoLayer", "m_end"); }
    void SetEnd(float value) { SetSchemaValue(m_ptr, "CSeqAutoLayer", "m_end", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif