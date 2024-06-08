class GCPathCorner;

#ifndef _gccpathcorner_h
#define _gccpathcorner_h

#include "../../../scripting.h"


#include "GCEntityIOOutput.h"

class GCPathCorner
{
private:
    void *m_ptr;

public:
    GCPathCorner() {}
    GCPathCorner(void *ptr) : m_ptr(ptr) {}

    float GetWait() const { return GetSchemaValue<float>(m_ptr, "CPathCorner", "m_flWait"); }
    void SetWait(float value) { SetSchemaValue(m_ptr, "CPathCorner", "m_flWait", false, value); }
    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CPathCorner", "m_flRadius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CPathCorner", "m_flRadius", false, value); }
    GCEntityIOOutput GetOnPass() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CPathCorner", "m_OnPass"); }
    void SetOnPass(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CPathCorner", "m_OnPass", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif