class GC_INIT_PositionOffsetToCP;

#ifndef _gcc_init_positionoffsettocp_h
#define _gcc_init_positionoffsettocp_h

#include "../../../scripting.h"




class GC_INIT_PositionOffsetToCP
{
private:
    void *m_ptr;

public:
    GC_INIT_PositionOffsetToCP() {}
    GC_INIT_PositionOffsetToCP(void *ptr) : m_ptr(ptr) {}

    int32_t GetControlPointNumberStart() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PositionOffsetToCP", "m_nControlPointNumberStart"); }
    void SetControlPointNumberStart(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionOffsetToCP", "m_nControlPointNumberStart", false, value); }
    int32_t GetControlPointNumberEnd() const { return GetSchemaValue<int32_t>(m_ptr, "C_INIT_PositionOffsetToCP", "m_nControlPointNumberEnd"); }
    void SetControlPointNumberEnd(int32_t value) { SetSchemaValue(m_ptr, "C_INIT_PositionOffsetToCP", "m_nControlPointNumberEnd", false, value); }
    bool GetLocalCoords() const { return GetSchemaValue<bool>(m_ptr, "C_INIT_PositionOffsetToCP", "m_bLocalCoords"); }
    void SetLocalCoords(bool value) { SetSchemaValue(m_ptr, "C_INIT_PositionOffsetToCP", "m_bLocalCoords", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif