class GC_OP_PlayEndCapWhenFinished;

#ifndef _gcc_op_playendcapwhenfinished_h
#define _gcc_op_playendcapwhenfinished_h

#include "../../../scripting.h"




class GC_OP_PlayEndCapWhenFinished
{
private:
    void *m_ptr;

public:
    GC_OP_PlayEndCapWhenFinished() {}
    GC_OP_PlayEndCapWhenFinished(void *ptr) : m_ptr(ptr) {}

    bool GetFireOnEmissionEnd() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PlayEndCapWhenFinished", "m_bFireOnEmissionEnd"); }
    void SetFireOnEmissionEnd(bool value) { SetSchemaValue(m_ptr, "C_OP_PlayEndCapWhenFinished", "m_bFireOnEmissionEnd", false, value); }
    bool GetIncludeChildren() const { return GetSchemaValue<bool>(m_ptr, "C_OP_PlayEndCapWhenFinished", "m_bIncludeChildren"); }
    void SetIncludeChildren(bool value) { SetSchemaValue(m_ptr, "C_OP_PlayEndCapWhenFinished", "m_bIncludeChildren", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif