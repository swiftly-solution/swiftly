class GCAnimData;

#ifndef _gccanimdata_h
#define _gccanimdata_h

#include "../../../scripting.h"


#include "GCAnimDesc.h"
#include "GCAnimDecoder.h"
#include "GCAnimFrameSegment.h"

class GCAnimData
{
private:
    void *m_ptr;

public:
    GCAnimData() {}
    GCAnimData(void *ptr) : m_ptr(ptr) {}

    CBufferString GetName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimData", "m_name"); }
    void SetName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimData", "m_name", false, value); }
    std::vector<GCAnimDesc> GetAnimArray() const { CUtlVector<GCAnimDesc>* vec = GetSchemaValue<CUtlVector<GCAnimDesc>*>(m_ptr, "CAnimData", "m_animArray"); std::vector<GCAnimDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAnimArray(std::vector<GCAnimDesc> value) { SetSchemaValueCUtlVector<GCAnimDesc>(m_ptr, "CAnimData", "m_animArray", false, value); }
    std::vector<GCAnimDecoder> GetDecoderArray() const { CUtlVector<GCAnimDecoder>* vec = GetSchemaValue<CUtlVector<GCAnimDecoder>*>(m_ptr, "CAnimData", "m_decoderArray"); std::vector<GCAnimDecoder> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDecoderArray(std::vector<GCAnimDecoder> value) { SetSchemaValueCUtlVector<GCAnimDecoder>(m_ptr, "CAnimData", "m_decoderArray", false, value); }
    int32_t GetMaxUniqueFrameIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimData", "m_nMaxUniqueFrameIndex"); }
    void SetMaxUniqueFrameIndex(int32_t value) { SetSchemaValue(m_ptr, "CAnimData", "m_nMaxUniqueFrameIndex", false, value); }
    std::vector<GCAnimFrameSegment> GetSegmentArray() const { CUtlVector<GCAnimFrameSegment>* vec = GetSchemaValue<CUtlVector<GCAnimFrameSegment>*>(m_ptr, "CAnimData", "m_segmentArray"); std::vector<GCAnimFrameSegment> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSegmentArray(std::vector<GCAnimFrameSegment> value) { SetSchemaValueCUtlVector<GCAnimFrameSegment>(m_ptr, "CAnimData", "m_segmentArray", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif