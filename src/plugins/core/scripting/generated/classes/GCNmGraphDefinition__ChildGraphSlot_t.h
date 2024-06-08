class GCNmGraphDefinition__ChildGraphSlot_t;

#ifndef _gccnmgraphdefinition__childgraphslot_t_h
#define _gccnmgraphdefinition__childgraphslot_t_h

#include "../../../scripting.h"




class GCNmGraphDefinition__ChildGraphSlot_t
{
private:
    void *m_ptr;

public:
    GCNmGraphDefinition__ChildGraphSlot_t() {}
    GCNmGraphDefinition__ChildGraphSlot_t(void *ptr) : m_ptr(ptr) {}

    int16_t GetNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmGraphDefinition__ChildGraphSlot_t", "m_nNodeIdx"); }
    void SetNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmGraphDefinition__ChildGraphSlot_t", "m_nNodeIdx", true, value); }
    int16_t GetDataSlotIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmGraphDefinition__ChildGraphSlot_t", "m_dataSlotIdx"); }
    void SetDataSlotIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmGraphDefinition__ChildGraphSlot_t", "m_dataSlotIdx", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif