class Gthinkfunc_t;

#ifndef _gcthinkfunc_t_h
#define _gcthinkfunc_t_h

#include "../../../scripting.h"




class Gthinkfunc_t
{
private:
    void *m_ptr;

public:
    Gthinkfunc_t() {}
    Gthinkfunc_t(void *ptr) : m_ptr(ptr) {}

    CUtlStringToken GetContext() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "thinkfunc_t", "m_nContext"); }
    void SetContext(CUtlStringToken value) { SetSchemaValue(m_ptr, "thinkfunc_t", "m_nContext", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif