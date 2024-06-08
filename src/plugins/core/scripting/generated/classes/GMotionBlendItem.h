class GMotionBlendItem;

#ifndef _gcmotionblenditem_h
#define _gcmotionblenditem_h

#include "../../../scripting.h"




class GMotionBlendItem
{
private:
    void *m_ptr;

public:
    GMotionBlendItem() {}
    GMotionBlendItem(void *ptr) : m_ptr(ptr) {}

    float GetKeyValue() const { return GetSchemaValue<float>(m_ptr, "MotionBlendItem", "m_flKeyValue"); }
    void SetKeyValue(float value) { SetSchemaValue(m_ptr, "MotionBlendItem", "m_flKeyValue", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif