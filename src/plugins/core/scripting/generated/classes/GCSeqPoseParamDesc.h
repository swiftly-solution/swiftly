class GCSeqPoseParamDesc;

#ifndef _gccseqposeparamdesc_h
#define _gccseqposeparamdesc_h

#include "../../../scripting.h"




class GCSeqPoseParamDesc
{
private:
    void *m_ptr;

public:
    GCSeqPoseParamDesc() {}
    GCSeqPoseParamDesc(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CSeqPoseParamDesc", "m_sName"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CSeqPoseParamDesc", "m_sName", false, value); }
    float GetStart() const { return GetSchemaValue<float>(m_ptr, "CSeqPoseParamDesc", "m_flStart"); }
    void SetStart(float value) { SetSchemaValue(m_ptr, "CSeqPoseParamDesc", "m_flStart", false, value); }
    float GetEnd() const { return GetSchemaValue<float>(m_ptr, "CSeqPoseParamDesc", "m_flEnd"); }
    void SetEnd(float value) { SetSchemaValue(m_ptr, "CSeqPoseParamDesc", "m_flEnd", false, value); }
    float GetLoop() const { return GetSchemaValue<float>(m_ptr, "CSeqPoseParamDesc", "m_flLoop"); }
    void SetLoop(float value) { SetSchemaValue(m_ptr, "CSeqPoseParamDesc", "m_flLoop", false, value); }
    bool GetLooping() const { return GetSchemaValue<bool>(m_ptr, "CSeqPoseParamDesc", "m_bLooping"); }
    void SetLooping(bool value) { SetSchemaValue(m_ptr, "CSeqPoseParamDesc", "m_bLooping", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif