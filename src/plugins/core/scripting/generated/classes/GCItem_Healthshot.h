class GCItem_Healthshot;

#ifndef _gccitem_healthshot_h
#define _gccitem_healthshot_h

#include "../../../scripting.h"




class GCItem_Healthshot
{
private:
    void *m_ptr;

public:
    GCItem_Healthshot() {}
    GCItem_Healthshot(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif