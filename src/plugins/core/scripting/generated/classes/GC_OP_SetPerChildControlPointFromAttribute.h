class GC_OP_SetPerChildControlPointFromAttribute;

#ifndef _gcc_op_setperchildcontrolpointfromattribute_h
#define _gcc_op_setperchildcontrolpointfromattribute_h

#include "../../../scripting.h"


#include "GParticleAttributeIndex_t.h"

class GC_OP_SetPerChildControlPointFromAttribute
{
private:
    void *m_ptr;

public:
    GC_OP_SetPerChildControlPointFromAttribute() {}
    GC_OP_SetPerChildControlPointFromAttribute(void *ptr) : m_ptr(ptr) {}

    int32_t GetChildGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nChildGroupID"); }
    void SetChildGroupID(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nChildGroupID", false, value); }
    int32_t GetFirstControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nFirstControlPoint"); }
    void SetFirstControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nFirstControlPoint", false, value); }
    int32_t GetNumControlPoints() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nNumControlPoints"); }
    void SetNumControlPoints(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nNumControlPoints", false, value); }
    int32_t GetParticleIncrement() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nParticleIncrement"); }
    void SetParticleIncrement(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nParticleIncrement", false, value); }
    int32_t GetFirstSourcePoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nFirstSourcePoint"); }
    void SetFirstSourcePoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nFirstSourcePoint", false, value); }
    bool GetNumBasedOnParticleCount() const { return GetSchemaValue<bool>(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_bNumBasedOnParticleCount"); }
    void SetNumBasedOnParticleCount(bool value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_bNumBasedOnParticleCount", false, value); }
    GParticleAttributeIndex_t GetAttributeToRead() const { return GetSchemaValue<GParticleAttributeIndex_t>(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nAttributeToRead"); }
    void SetAttributeToRead(GParticleAttributeIndex_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nAttributeToRead", false, value); }
    int32_t GetCPField() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nCPField"); }
    void SetCPField(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetPerChildControlPointFromAttribute", "m_nCPField", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif