class GCRenderBufferBinding;

#ifndef _gccrenderbufferbinding_h
#define _gccrenderbufferbinding_h

#include "../../../scripting.h"




class GCRenderBufferBinding
{
private:
    void *m_ptr;

public:
    GCRenderBufferBinding() {}
    GCRenderBufferBinding(void *ptr) : m_ptr(ptr) {}

    uint64_t GetBuffer() const { return GetSchemaValue<uint64_t>(m_ptr, "CRenderBufferBinding", "m_hBuffer"); }
    void SetBuffer(uint64_t value) { SetSchemaValue(m_ptr, "CRenderBufferBinding", "m_hBuffer", false, value); }
    uint32_t GetBindOffsetBytes() const { return GetSchemaValue<uint32_t>(m_ptr, "CRenderBufferBinding", "m_nBindOffsetBytes"); }
    void SetBindOffsetBytes(uint32_t value) { SetSchemaValue(m_ptr, "CRenderBufferBinding", "m_nBindOffsetBytes", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif