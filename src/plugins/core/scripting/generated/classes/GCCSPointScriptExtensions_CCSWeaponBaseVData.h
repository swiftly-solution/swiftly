class GCCSPointScriptExtensions_CCSWeaponBaseVData;

#ifndef _gcccspointscriptextensions_ccsweaponbasevdata_h
#define _gcccspointscriptextensions_ccsweaponbasevdata_h

#include "../../../scripting.h"




class GCCSPointScriptExtensions_CCSWeaponBaseVData
{
private:
    void *m_ptr;

public:
    GCCSPointScriptExtensions_CCSWeaponBaseVData() {}
    GCCSPointScriptExtensions_CCSWeaponBaseVData(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif