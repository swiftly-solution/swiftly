class GCAttributeList;

#ifndef _gccattributelist_h
#define _gccattributelist_h

#include "../../../scripting.h"


#include "GCEconItemAttribute.h"
#include "GCAttributeManager.h"

class GCAttributeList
{
private:
    void *m_ptr;

public:
    GCAttributeList() {}
    GCAttributeList(void *ptr) : m_ptr(ptr) {}

    std::vector<GCEconItemAttribute> GetAttributes() const { CUtlVector<GCEconItemAttribute>* vec = GetSchemaValue<CUtlVector<GCEconItemAttribute>*>(m_ptr, "CAttributeList", "m_Attributes"); std::vector<GCEconItemAttribute> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAttributes(std::vector<GCEconItemAttribute> value) { SetSchemaValueCUtlVector<GCEconItemAttribute>(m_ptr, "CAttributeList", "m_Attributes", false, value); }
    GCAttributeManager* GetManager() const { return GetSchemaValue<GCAttributeManager*>(m_ptr, "CAttributeList", "m_pManager"); }
    void SetManager(GCAttributeManager* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Manager' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif