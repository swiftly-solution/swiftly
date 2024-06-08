class GCSeqIKLock;

#ifndef _gccseqiklock_h
#define _gccseqiklock_h

#include "../../../scripting.h"




class GCSeqIKLock
{
private:
    void *m_ptr;

public:
    GCSeqIKLock() {}
    GCSeqIKLock(void *ptr) : m_ptr(ptr) {}

    float GetPosWeight() const { return GetSchemaValue<float>(m_ptr, "CSeqIKLock", "m_flPosWeight"); }
    void SetPosWeight(float value) { SetSchemaValue(m_ptr, "CSeqIKLock", "m_flPosWeight", false, value); }
    float GetAngleWeight() const { return GetSchemaValue<float>(m_ptr, "CSeqIKLock", "m_flAngleWeight"); }
    void SetAngleWeight(float value) { SetSchemaValue(m_ptr, "CSeqIKLock", "m_flAngleWeight", false, value); }
    int16_t GetLocalBone() const { return GetSchemaValue<int16_t>(m_ptr, "CSeqIKLock", "m_nLocalBone"); }
    void SetLocalBone(int16_t value) { SetSchemaValue(m_ptr, "CSeqIKLock", "m_nLocalBone", false, value); }
    bool GetBonesOrientedAlongPositiveX() const { return GetSchemaValue<bool>(m_ptr, "CSeqIKLock", "m_bBonesOrientedAlongPositiveX"); }
    void SetBonesOrientedAlongPositiveX(bool value) { SetSchemaValue(m_ptr, "CSeqIKLock", "m_bBonesOrientedAlongPositiveX", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif