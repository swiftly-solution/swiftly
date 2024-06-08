class GCBoneConstraintBase;

#ifndef _gccboneconstraintbase_h
#define _gccboneconstraintbase_h

#include "../../../scripting.h"




class GCBoneConstraintBase
{
private:
    void *m_ptr;

public:
    GCBoneConstraintBase() {}
    GCBoneConstraintBase(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif