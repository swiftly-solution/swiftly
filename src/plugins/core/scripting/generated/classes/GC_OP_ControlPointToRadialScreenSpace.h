class GC_OP_ControlPointToRadialScreenSpace;

#ifndef _gcc_op_controlpointtoradialscreenspace_h
#define _gcc_op_controlpointtoradialscreenspace_h

#include "../../../scripting.h"




class GC_OP_ControlPointToRadialScreenSpace
{
private:
    void *m_ptr;

public:
    GC_OP_ControlPointToRadialScreenSpace() {}
    GC_OP_ControlPointToRadialScreenSpace(void *ptr) : m_ptr(ptr) {}

    int32_t GetCPIn() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ControlPointToRadialScreenSpace", "m_nCPIn"); }
    void SetCPIn(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ControlPointToRadialScreenSpace", "m_nCPIn", false, value); }
    Vector GetCP1Pos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_ControlPointToRadialScreenSpace", "m_vecCP1Pos"); }
    void SetCP1Pos(Vector value) { SetSchemaValue(m_ptr, "C_OP_ControlPointToRadialScreenSpace", "m_vecCP1Pos", false, value); }
    int32_t GetCPOut() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ControlPointToRadialScreenSpace", "m_nCPOut"); }
    void SetCPOut(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ControlPointToRadialScreenSpace", "m_nCPOut", false, value); }
    int32_t GetCPOutField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ControlPointToRadialScreenSpace", "m_nCPOutField"); }
    void SetCPOutField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ControlPointToRadialScreenSpace", "m_nCPOutField", false, value); }
    int32_t GetCPSSPosOut() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_ControlPointToRadialScreenSpace", "m_nCPSSPosOut"); }
    void SetCPSSPosOut(int32_t value) { SetSchemaValue(m_ptr, "C_OP_ControlPointToRadialScreenSpace", "m_nCPSSPosOut", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif