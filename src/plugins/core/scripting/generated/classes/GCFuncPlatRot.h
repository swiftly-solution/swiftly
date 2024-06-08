class GCFuncPlatRot;

#ifndef _gccfuncplatrot_h
#define _gccfuncplatrot_h

#include "../../../scripting.h"




class GCFuncPlatRot
{
private:
    void *m_ptr;

public:
    GCFuncPlatRot() {}
    GCFuncPlatRot(void *ptr) : m_ptr(ptr) {}

    QAngle GetEnd() const { return GetSchemaValue<QAngle>(m_ptr, "CFuncPlatRot", "m_end"); }
    void SetEnd(QAngle value) { SetSchemaValue(m_ptr, "CFuncPlatRot", "m_end", false, value); }
    QAngle GetStart() const { return GetSchemaValue<QAngle>(m_ptr, "CFuncPlatRot", "m_start"); }
    void SetStart(QAngle value) { SetSchemaValue(m_ptr, "CFuncPlatRot", "m_start", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif