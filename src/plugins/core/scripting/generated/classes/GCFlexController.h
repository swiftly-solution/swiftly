class GCFlexController;

#ifndef _gccflexcontroller_h
#define _gccflexcontroller_h

#include "../../../scripting.h"




class GCFlexController
{
private:
    void *m_ptr;

public:
    GCFlexController() {}
    GCFlexController(void *ptr) : m_ptr(ptr) {}

    CUtlString GetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CFlexController", "m_szName"); }
    void SetName(CUtlString value) { SetSchemaValue(m_ptr, "CFlexController", "m_szName", false, value); }
    CUtlString GetType() const { return GetSchemaValue<CUtlString>(m_ptr, "CFlexController", "m_szType"); }
    void SetType(CUtlString value) { SetSchemaValue(m_ptr, "CFlexController", "m_szType", false, value); }
    float GetMin() const { return GetSchemaValue<float>(m_ptr, "CFlexController", "min"); }
    void SetMin(float value) { SetSchemaValue(m_ptr, "CFlexController", "min", false, value); }
    float GetMax() const { return GetSchemaValue<float>(m_ptr, "CFlexController", "max"); }
    void SetMax(float value) { SetSchemaValue(m_ptr, "CFlexController", "max", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif