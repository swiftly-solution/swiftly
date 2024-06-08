class GCTwoBoneIKUpdateNode;

#ifndef _gcctwoboneikupdatenode_h
#define _gcctwoboneikupdatenode_h

#include "../../../scripting.h"


#include "GTwoBoneIKSettings_t.h"

class GCTwoBoneIKUpdateNode
{
private:
    void *m_ptr;

public:
    GCTwoBoneIKUpdateNode() {}
    GCTwoBoneIKUpdateNode(void *ptr) : m_ptr(ptr) {}

    GTwoBoneIKSettings_t GetOpFixedData() const { return GetSchemaValue<GTwoBoneIKSettings_t>(m_ptr, "CTwoBoneIKUpdateNode", "m_opFixedData"); }
    void SetOpFixedData(GTwoBoneIKSettings_t value) { SetSchemaValue(m_ptr, "CTwoBoneIKUpdateNode", "m_opFixedData", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif