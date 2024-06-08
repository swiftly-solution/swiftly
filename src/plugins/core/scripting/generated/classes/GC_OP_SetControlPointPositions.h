class GC_OP_SetControlPointPositions;

#ifndef _gcc_op_setcontrolpointpositions_h
#define _gcc_op_setcontrolpointpositions_h

#include "../../../scripting.h"




class GC_OP_SetControlPointPositions
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointPositions() {}
    GC_OP_SetControlPointPositions(void *ptr) : m_ptr(ptr) {}

    bool GetUseWorldLocation() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointPositions", "m_bUseWorldLocation"); }
    void SetUseWorldLocation(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_bUseWorldLocation", false, value); }
    bool GetOrient() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointPositions", "m_bOrient"); }
    void SetOrient(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_bOrient", false, value); }
    bool GetSetOnce() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetControlPointPositions", "m_bSetOnce"); }
    void SetSetOnce(bool value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_bSetOnce", false, value); }
    int32_t GetCP1() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointPositions", "m_nCP1"); }
    void SetCP1(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_nCP1", false, value); }
    int32_t GetCP2() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointPositions", "m_nCP2"); }
    void SetCP2(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_nCP2", false, value); }
    int32_t GetCP3() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointPositions", "m_nCP3"); }
    void SetCP3(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_nCP3", false, value); }
    int32_t GetCP4() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointPositions", "m_nCP4"); }
    void SetCP4(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_nCP4", false, value); }
    Vector GetCP1Pos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetControlPointPositions", "m_vecCP1Pos"); }
    void SetCP1Pos(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_vecCP1Pos", false, value); }
    Vector GetCP2Pos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetControlPointPositions", "m_vecCP2Pos"); }
    void SetCP2Pos(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_vecCP2Pos", false, value); }
    Vector GetCP3Pos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetControlPointPositions", "m_vecCP3Pos"); }
    void SetCP3Pos(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_vecCP3Pos", false, value); }
    Vector GetCP4Pos() const { return GetSchemaValue<Vector>(m_ptr, "C_OP_SetControlPointPositions", "m_vecCP4Pos"); }
    void SetCP4Pos(Vector value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_vecCP4Pos", false, value); }
    int32_t GetHeadLocation() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointPositions", "m_nHeadLocation"); }
    void SetHeadLocation(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointPositions", "m_nHeadLocation", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif