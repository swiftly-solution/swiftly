class GCLogicScript;

#ifndef _gcclogicscript_h
#define _gcclogicscript_h

#include "../../../scripting.h"




class GCLogicScript
{
private:
    void *m_ptr;

public:
    GCLogicScript() {}
    GCLogicScript(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif