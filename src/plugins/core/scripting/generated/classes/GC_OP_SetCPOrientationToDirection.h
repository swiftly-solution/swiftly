class GC_OP_SetCPOrientationToDirection;

#ifndef _gcc_op_setcporientationtodirection_h
#define _gcc_op_setcporientationtodirection_h

#include "../../../scripting.h"




class GC_OP_SetCPOrientationToDirection
{
private:
    void *m_ptr;

public:
    GC_OP_SetCPOrientationToDirection() {}
    GC_OP_SetCPOrientationToDirection(void *ptr) : m_ptr(ptr) {}

    int32_t GetInputControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetCPOrientationToDirection", "m_nInputControlPoint"); }
    void SetInputControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToDirection", "m_nInputControlPoint", false, value); }
    int32_t GetOutputControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "C_OP_SetCPOrientationToDirection", "m_nOutputControlPoint"); }
    void SetOutputControlPoint(int32_t value) { SetSchemaValue(m_ptr, "C_OP_SetCPOrientationToDirection", "m_nOutputControlPoint", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif