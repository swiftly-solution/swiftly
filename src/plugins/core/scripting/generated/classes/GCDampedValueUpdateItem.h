class GCDampedValueUpdateItem;

#ifndef _gccdampedvalueupdateitem_h
#define _gccdampedvalueupdateitem_h

#include "../../../scripting.h"


#include "GCAnimInputDamping.h"
#include "GCAnimParamHandle.h"

class GCDampedValueUpdateItem
{
private:
    void *m_ptr;

public:
    GCDampedValueUpdateItem() {}
    GCDampedValueUpdateItem(void *ptr) : m_ptr(ptr) {}

    GCAnimInputDamping GetDamping() const { return GetSchemaValue<GCAnimInputDamping>(m_ptr, "CDampedValueUpdateItem", "m_damping"); }
    void SetDamping(GCAnimInputDamping value) { SetSchemaValue(m_ptr, "CDampedValueUpdateItem", "m_damping", false, value); }
    GCAnimParamHandle GetParamIn() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CDampedValueUpdateItem", "m_hParamIn"); }
    void SetParamIn(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CDampedValueUpdateItem", "m_hParamIn", false, value); }
    GCAnimParamHandle GetParamOut() const { return GetSchemaValue<GCAnimParamHandle>(m_ptr, "CDampedValueUpdateItem", "m_hParamOut"); }
    void SetParamOut(GCAnimParamHandle value) { SetSchemaValue(m_ptr, "CDampedValueUpdateItem", "m_hParamOut", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif