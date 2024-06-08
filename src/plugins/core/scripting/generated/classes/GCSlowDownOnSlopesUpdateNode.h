class GCSlowDownOnSlopesUpdateNode;

#ifndef _gccslowdownonslopesupdatenode_h
#define _gccslowdownonslopesupdatenode_h

#include "../../../scripting.h"




class GCSlowDownOnSlopesUpdateNode
{
private:
    void *m_ptr;

public:
    GCSlowDownOnSlopesUpdateNode() {}
    GCSlowDownOnSlopesUpdateNode(void *ptr) : m_ptr(ptr) {}

    float GetSlowDownStrength() const { return GetSchemaValue<float>(m_ptr, "CSlowDownOnSlopesUpdateNode", "m_flSlowDownStrength"); }
    void SetSlowDownStrength(float value) { SetSchemaValue(m_ptr, "CSlowDownOnSlopesUpdateNode", "m_flSlowDownStrength", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif