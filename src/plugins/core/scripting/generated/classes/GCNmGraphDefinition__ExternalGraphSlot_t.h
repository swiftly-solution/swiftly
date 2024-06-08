class GCNmGraphDefinition__ExternalGraphSlot_t;

#ifndef _gccnmgraphdefinition__externalgraphslot_t_h
#define _gccnmgraphdefinition__externalgraphslot_t_h

#include "../../../scripting.h"




class GCNmGraphDefinition__ExternalGraphSlot_t
{
private:
    void *m_ptr;

public:
    GCNmGraphDefinition__ExternalGraphSlot_t() {}
    GCNmGraphDefinition__ExternalGraphSlot_t(void *ptr) : m_ptr(ptr) {}

    int16_t GetNodeIdx() const { return GetSchemaValue<int16_t>(m_ptr, "CNmGraphDefinition__ExternalGraphSlot_t", "m_nNodeIdx"); }
    void SetNodeIdx(int16_t value) { SetSchemaValue(m_ptr, "CNmGraphDefinition__ExternalGraphSlot_t", "m_nNodeIdx", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif