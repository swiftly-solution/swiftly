class GC_OP_InheritFromPeerSystem;

#ifndef _gcc_op_inheritfrompeersystem_h
#define _gcc_op_inheritfrompeersystem_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_InheritFromPeerSystem
{
private:
    void *m_ptr;

public:
    GC_OP_InheritFromPeerSystem() {}
    GC_OP_InheritFromPeerSystem(void *ptr) : m_ptr(ptr) {}

    GParticleAttributeIndex_t GetFieldOutput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_InheritFromPeerSystem", "m_nFieldOutput"); }
    void SetFieldOutput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_InheritFromPeerSystem", "m_nFieldOutput", false, value); }
    GParticleAttributeIndex_t GetFieldInput() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_InheritFromPeerSystem", "m_nFieldInput"); }
    void SetFieldInput(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_InheritFromPeerSystem", "m_nFieldInput", false, value); }
    int32_t GetIncrement() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_InheritFromPeerSystem", "m_nIncrement"); }
    void SetIncrement(int32_t value) { SetSchemaValue(m_ptr, "C_OP_InheritFromPeerSystem", "m_nIncrement", false, value); }
    int32_t GetGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_InheritFromPeerSystem", "m_nGroupID"); }
    void SetGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_OP_InheritFromPeerSystem", "m_nGroupID", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif