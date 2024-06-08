class GCSeqPoseSetting;

#ifndef _gccseqposesetting_h
#define _gccseqposesetting_h

#include "../../../scripting.h"




class GCSeqPoseSetting
{
private:
    void *m_ptr;

public:
    GCSeqPoseSetting() {}
    GCSeqPoseSetting(void *ptr) : m_ptr(ptr) {}

    CBufferString GetPoseParameter() const { return GetSchemaValue<CBufferString>(m_ptr, "CSeqPoseSetting", "m_sPoseParameter"); }
    void SetPoseParameter(CBufferString value) { SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_sPoseParameter", false, value); }
    CBufferString GetAttachment() const { return GetSchemaValue<CBufferString>(m_ptr, "CSeqPoseSetting", "m_sAttachment"); }
    void SetAttachment(CBufferString value) { SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_sAttachment", false, value); }
    CBufferString GetReferenceSequence() const { return GetSchemaValue<CBufferString>(m_ptr, "CSeqPoseSetting", "m_sReferenceSequence"); }
    void SetReferenceSequence(CBufferString value) { SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_sReferenceSequence", false, value); }
    float GetValue() const { return GetSchemaValue<float>(m_ptr, "CSeqPoseSetting", "m_flValue"); }
    void SetValue(float value) { SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_flValue", false, value); }
    bool GetX() const { return GetSchemaValue<bool>(m_ptr, "CSeqPoseSetting", "m_bX"); }
    void SetX(bool value) { SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_bX", false, value); }
    bool GetY() const { return GetSchemaValue<bool>(m_ptr, "CSeqPoseSetting", "m_bY"); }
    void SetY(bool value) { SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_bY", false, value); }
    bool GetZ() const { return GetSchemaValue<bool>(m_ptr, "CSeqPoseSetting", "m_bZ"); }
    void SetZ(bool value) { SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_bZ", false, value); }
    int32_t GetType() const { return GetSchemaValue<int32_t>(m_ptr, "CSeqPoseSetting", "m_eType"); }
    void SetType(int32_t value) { SetSchemaValue(m_ptr, "CSeqPoseSetting", "m_eType", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif