class GCRuleBrushEntity;

#ifndef _gccrulebrushentity_h
#define _gccrulebrushentity_h

#include "../../../scripting.h"




class GCRuleBrushEntity
{
private:
    void *m_ptr;

public:
    GCRuleBrushEntity() {}
    GCRuleBrushEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif