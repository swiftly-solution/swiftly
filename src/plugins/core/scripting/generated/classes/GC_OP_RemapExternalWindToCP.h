class GC_OP_RemapExternalWindToCP;

#ifndef _gcc_op_remapexternalwindtocp_h
#define _gcc_op_remapexternalwindtocp_h

#include "../../../scripting.h"




class GC_OP_RemapExternalWindToCP
{
private:
    void *m_ptr;

public:
    GC_OP_RemapExternalWindToCP() {}
    GC_OP_RemapExternalWindToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetCP() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapExternalWindToCP", "m_nCP"); }
    void SetCP(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapExternalWindToCP", "m_nCP", false, value); }
    int32_t GetCPOutput() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapExternalWindToCP", "m_nCPOutput"); }
    void SetCPOutput(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapExternalWindToCP", "m_nCPOutput", false, value); }
    bool GetSetMagnitude() const { return GetSchemaValue<bool>(m_ptr, "C_OP_RemapExternalWindToCP", "m_bSetMagnitude"); }
    void SetSetMagnitude(bool value) { SetSchemaValue(m_ptr, "C_OP_RemapExternalWindToCP", "m_bSetMagnitude", false, value); }
    int32_t GetOutVectorField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_RemapExternalWindToCP", "m_nOutVectorField"); }
    void SetOutVectorField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_RemapExternalWindToCP", "m_nOutVectorField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif