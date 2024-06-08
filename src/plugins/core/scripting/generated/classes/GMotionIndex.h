class GMotionIndex;

#ifndef _gcmotionindex_h
#define _gcmotionindex_h

#include "../../../scripting.h"




class GMotionIndex
{
private:
    void *m_ptr;

public:
    GMotionIndex() {}
    GMotionIndex(void *ptr) : m_ptr(ptr) {}

    uint16_t GetGroup() const { return GetSchemaValue<uint16_t>(m_ptr, "MotionIndex", "m_nGroup"); }
    void SetGroup(uint16_t value) { SetSchemaValue(m_ptr, "MotionIndex", "m_nGroup", false, value); }
    uint16_t GetMotion() const { return GetSchemaValue<uint16_t>(m_ptr, "MotionIndex", "m_nMotion"); }
    void SetMotion(uint16_t value) { SetSchemaValue(m_ptr, "MotionIndex", "m_nMotion", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif