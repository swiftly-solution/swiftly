class GC_OP_SetControlPointFromObjectScale;

#ifndef _gcc_op_setcontrolpointfromobjectscale_h
#define _gcc_op_setcontrolpointfromobjectscale_h

#include "../../../scripting.h"




class GC_OP_SetControlPointFromObjectScale
{
private:
    void *m_ptr;

public:
    GC_OP_SetControlPointFromObjectScale() {}
    GC_OP_SetControlPointFromObjectScale(void *ptr) : m_ptr(ptr) {}

    int32_t GetCPInput() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointFromObjectScale", "m_nCPInput"); }
    void SetCPInput(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFromObjectScale", "m_nCPInput", false, value); }
    int32_t GetCPOutput() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetControlPointFromObjectScale", "m_nCPOutput"); }
    void SetCPOutput(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetControlPointFromObjectScale", "m_nCPOutput", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif