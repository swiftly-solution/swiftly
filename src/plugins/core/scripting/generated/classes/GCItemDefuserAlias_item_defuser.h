class GCItemDefuserAlias_item_defuser;

#ifndef _gccitemdefuseralias_item_defuser_h
#define _gccitemdefuseralias_item_defuser_h

#include "../../../scripting.h"




class GCItemDefuserAlias_item_defuser
{
private:
    void *m_ptr;

public:
    GCItemDefuserAlias_item_defuser() {}
    GCItemDefuserAlias_item_defuser(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif