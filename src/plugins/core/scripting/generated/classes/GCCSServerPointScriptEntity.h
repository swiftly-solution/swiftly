class GCCSServerPointScriptEntity;

#ifndef _gcccsserverpointscriptentity_h
#define _gcccsserverpointscriptentity_h

#include "../../../scripting.h"




class GCCSServerPointScriptEntity
{
private:
    void *m_ptr;

public:
    GCCSServerPointScriptEntity() {}
    GCCSServerPointScriptEntity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif