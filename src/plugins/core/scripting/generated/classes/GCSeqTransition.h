class GCSeqTransition;

#ifndef _gccseqtransition_h
#define _gccseqtransition_h

#include "../../../scripting.h"




class GCSeqTransition
{
private:
    void *m_ptr;

public:
    GCSeqTransition() {}
    GCSeqTransition(void *ptr) : m_ptr(ptr) {}

    float GetFadeInTime() const { return GetSchemaValue<float>(m_ptr, "CSeqTransition", "m_flFadeInTime"); }
    void SetFadeInTime(float value) { SetSchemaValue(m_ptr, "CSeqTransition", "m_flFadeInTime", false, value); }
    float GetFadeOutTime() const { return GetSchemaValue<float>(m_ptr, "CSeqTransition", "m_flFadeOutTime"); }
    void SetFadeOutTime(float value) { SetSchemaValue(m_ptr, "CSeqTransition", "m_flFadeOutTime", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif