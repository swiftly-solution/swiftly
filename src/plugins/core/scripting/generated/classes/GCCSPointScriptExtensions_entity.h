class GCCSPointScriptExtensions_entity;

#ifndef _gcccspointscriptextensions_entity_h
#define _gcccspointscriptextensions_entity_h

#include "../../../scripting.h"




class GCCSPointScriptExtensions_entity
{
private:
    void *m_ptr;

public:
    GCCSPointScriptExtensions_entity() {}
    GCCSPointScriptExtensions_entity(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif