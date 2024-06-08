class GAnimationDecodeDebugDump_t;

#ifndef _gcanimationdecodedebugdump_t_h
#define _gcanimationdecodedebugdump_t_h

#include "../../../scripting.h"

#include "../types/GAnimationProcessingType_t.h"
#include "GAnimationDecodeDebugDumpElement_t.h"

class GAnimationDecodeDebugDump_t
{
private:
    void *m_ptr;

public:
    GAnimationDecodeDebugDump_t() {}
    GAnimationDecodeDebugDump_t(void *ptr) : m_ptr(ptr) {}

    AnimationProcessingType_t GetProcessingType() const { return GetSchemaValue<AnimationProcessingType_t>(m_ptr, "AnimationDecodeDebugDump_t", "m_processingType"); }
    void SetProcessingType(AnimationProcessingType_t value) { SetSchemaValue(m_ptr, "AnimationDecodeDebugDump_t", "m_processingType", true, value); }
    std::vector<GAnimationDecodeDebugDumpElement_t> GetElems() const { CUtlVector<GAnimationDecodeDebugDumpElement_t>* vec = GetSchemaValue<CUtlVector<GAnimationDecodeDebugDumpElement_t>*>(m_ptr, "AnimationDecodeDebugDump_t", "m_elems"); std::vector<GAnimationDecodeDebugDumpElement_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetElems(std::vector<GAnimationDecodeDebugDumpElement_t> value) { SetSchemaValueCUtlVector<GAnimationDecodeDebugDumpElement_t>(m_ptr, "AnimationDecodeDebugDump_t", "m_elems", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif