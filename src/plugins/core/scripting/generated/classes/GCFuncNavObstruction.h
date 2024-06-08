class GCFuncNavObstruction;

#ifndef _gccfuncnavobstruction_h
#define _gccfuncnavobstruction_h

#include "../../../scripting.h"




class GCFuncNavObstruction
{
private:
    void *m_ptr;

public:
    GCFuncNavObstruction() {}
    GCFuncNavObstruction(void *ptr) : m_ptr(ptr) {}

    bool GetDisabled() const { return GetSchemaValue<bool>(m_ptr, "CFuncNavObstruction", "m_bDisabled"); }
    void SetDisabled(bool value) { SetSchemaValue(m_ptr, "CFuncNavObstruction", "m_bDisabled", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif