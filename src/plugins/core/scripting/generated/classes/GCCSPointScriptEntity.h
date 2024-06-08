class GCCSPointScriptEntity;

#ifndef _gcccspointscriptentity_h
#define _gcccspointscriptentity_h

#include "../../../scripting.h"




class GCCSPointScriptEntity
{
private:
    void *m_ptr;

public:
    GCCSPointScriptEntity() {}
    GCCSPointScriptEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif