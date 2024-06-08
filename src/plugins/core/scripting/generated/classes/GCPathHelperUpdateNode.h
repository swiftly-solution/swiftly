class GCPathHelperUpdateNode;

#ifndef _gccpathhelperupdatenode_h
#define _gccpathhelperupdatenode_h

#include "../../../scripting.h"




class GCPathHelperUpdateNode
{
private:
    void *m_ptr;

public:
    GCPathHelperUpdateNode() {}
    GCPathHelperUpdateNode(void *ptr) : m_ptr(ptr) {}

    float GetStoppingRadius() const { return GetSchemaValue<float>(m_ptr, "CPathHelperUpdateNode", "m_flStoppingRadius"); }
    void SetStoppingRadius(float value) { SetSchemaValue(m_ptr, "CPathHelperUpdateNode", "m_flStoppingRadius", false, value); }
    float GetStoppingSpeedScale() const { return GetSchemaValue<float>(m_ptr, "CPathHelperUpdateNode", "m_flStoppingSpeedScale"); }
    void SetStoppingSpeedScale(float value) { SetSchemaValue(m_ptr, "CPathHelperUpdateNode", "m_flStoppingSpeedScale", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif