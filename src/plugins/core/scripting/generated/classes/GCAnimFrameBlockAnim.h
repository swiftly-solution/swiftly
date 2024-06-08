class GCAnimFrameBlockAnim;

#ifndef _gccanimframeblockanim_h
#define _gccanimframeblockanim_h

#include "../../../scripting.h"




class GCAnimFrameBlockAnim
{
private:
    void *m_ptr;

public:
    GCAnimFrameBlockAnim() {}
    GCAnimFrameBlockAnim(void *ptr) : m_ptr(ptr) {}

    int32_t GetStartFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimFrameBlockAnim", "m_nStartFrame"); }
    void SetStartFrame(int32_t value) { SetSchemaValue(m_ptr, "CAnimFrameBlockAnim", "m_nStartFrame", false, value); }
    int32_t GetEndFrame() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimFrameBlockAnim", "m_nEndFrame"); }
    void SetEndFrame(int32_t value) { SetSchemaValue(m_ptr, "CAnimFrameBlockAnim", "m_nEndFrame", false, value); }
    std::vector<int32> GetSegmentIndexArray() const { CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimFrameBlockAnim", "m_segmentIndexArray"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSegmentIndexArray(std::vector<int32> value) { SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimFrameBlockAnim", "m_segmentIndexArray", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif