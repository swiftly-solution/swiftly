class GMotionDBIndex;

#ifndef _gcmotiondbindex_h
#define _gcmotiondbindex_h

#include "../../../scripting.h"




class GMotionDBIndex
{
private:
    void *m_ptr;

public:
    GMotionDBIndex() {}
    GMotionDBIndex(void *ptr) : m_ptr(ptr) {}

    uint32_t GetIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "MotionDBIndex", "m_nIndex"); }
    void SetIndex(uint32_t value) { SetSchemaValue(m_ptr, "MotionDBIndex", "m_nIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif