class GCFlexOp;

#ifndef _gccflexop_h
#define _gccflexop_h

#include "../../../scripting.h"

#include "../types/GFlexOpCode_t.h"


class GCFlexOp
{
private:
    void *m_ptr;

public:
    GCFlexOp() {}
    GCFlexOp(void *ptr) : m_ptr(ptr) {}

    FlexOpCode_t GetOpCode() const { return GetSchemaValue<FlexOpCode_t>(m_ptr, "CFlexOp", "m_OpCode"); }
    void SetOpCode(FlexOpCode_t value) { SetSchemaValue(m_ptr, "CFlexOp", "m_OpCode", false, value); }
    int32_t GetData() const { return GetSchemaValue<int32_t>(m_ptr, "CFlexOp", "m_Data"); }
    void SetData(int32_t value) { SetSchemaValue(m_ptr, "CFlexOp", "m_Data", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif