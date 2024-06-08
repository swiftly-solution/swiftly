class GCJiggleBoneUpdateNode;

#ifndef _gccjiggleboneupdatenode_h
#define _gccjiggleboneupdatenode_h

#include "../../../scripting.h"


#include "GJiggleBoneSettingsList_t.h"

class GCJiggleBoneUpdateNode
{
private:
    void *m_ptr;

public:
    GCJiggleBoneUpdateNode() {}
    GCJiggleBoneUpdateNode(void *ptr) : m_ptr(ptr) {}

    GJiggleBoneSettingsList_t GetOpFixedData() const { return GetSchemaValue<GJiggleBoneSettingsList_t>(m_ptr, "CJiggleBoneUpdateNode", "m_opFixedData"); }
    void SetOpFixedData(GJiggleBoneSettingsList_t value) { SetSchemaValue(m_ptr, "CJiggleBoneUpdateNode", "m_opFixedData", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif