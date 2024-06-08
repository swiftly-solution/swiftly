class GCEntitySubclassVDataBase;

#ifndef _gccentitysubclassvdatabase_h
#define _gccentitysubclassvdatabase_h

#include "../../../scripting.h"




class GCEntitySubclassVDataBase
{
private:
    void *m_ptr;

public:
    GCEntitySubclassVDataBase() {}
    GCEntitySubclassVDataBase(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif