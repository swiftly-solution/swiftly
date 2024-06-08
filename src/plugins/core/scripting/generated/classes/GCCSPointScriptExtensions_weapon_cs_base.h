class GCCSPointScriptExtensions_weapon_cs_base;

#ifndef _gcccspointscriptextensions_weapon_cs_base_h
#define _gcccspointscriptextensions_weapon_cs_base_h

#include "../../../scripting.h"




class GCCSPointScriptExtensions_weapon_cs_base
{
private:
    void *m_ptr;

public:
    GCCSPointScriptExtensions_weapon_cs_base() {}
    GCCSPointScriptExtensions_weapon_cs_base(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif