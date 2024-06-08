class GCSeqAutoLayerFlag;

#ifndef _gccseqautolayerflag_h
#define _gccseqautolayerflag_h

#include "../../../scripting.h"




class GCSeqAutoLayerFlag
{
private:
    void *m_ptr;

public:
    GCSeqAutoLayerFlag() {}
    GCSeqAutoLayerFlag(void *ptr) : m_ptr(ptr) {}

    bool GetPost() const { return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bPost"); }
    void SetPost(bool value) { SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bPost", false, value); }
    bool GetSpline() const { return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bSpline"); }
    void SetSpline(bool value) { SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bSpline", false, value); }
    bool GetXFade() const { return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bXFade"); }
    void SetXFade(bool value) { SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bXFade", false, value); }
    bool GetNoBlend() const { return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bNoBlend"); }
    void SetNoBlend(bool value) { SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bNoBlend", false, value); }
    bool GetLocal() const { return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bLocal"); }
    void SetLocal(bool value) { SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bLocal", false, value); }
    bool GetPose() const { return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bPose"); }
    void SetPose(bool value) { SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bPose", false, value); }
    bool GetFetchFrame() const { return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bFetchFrame"); }
    void SetFetchFrame(bool value) { SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bFetchFrame", false, value); }
    bool GetSubtract() const { return GetSchemaValue<bool>(m_ptr, "CSeqAutoLayerFlag", "m_bSubtract"); }
    void SetSubtract(bool value) { SetSchemaValue(m_ptr, "CSeqAutoLayerFlag", "m_bSubtract", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif