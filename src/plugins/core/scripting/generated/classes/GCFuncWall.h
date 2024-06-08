class GCFuncWall;

#ifndef _gccfuncwall_h
#define _gccfuncwall_h

#include "../../../scripting.h"




class GCFuncWall
{
private:
    void *m_ptr;

public:
    GCFuncWall() {}
    GCFuncWall(void *ptr) : m_ptr(ptr) {}

    int32_t GetState() const { return GetSchemaValue<int32_t>(m_ptr, "CFuncWall", "m_nState"); }
    void SetState(int32_t value) { SetSchemaValue(m_ptr, "CFuncWall", "m_nState", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif