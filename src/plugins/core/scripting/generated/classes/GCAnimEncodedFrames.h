class GCAnimEncodedFrames;

#ifndef _gccanimencodedframes_h
#define _gccanimencodedframes_h

#include "../../../scripting.h"


#include "GCAnimFrameBlockAnim.h"
#include "GCAnimEncodeDifference.h"

class GCAnimEncodedFrames
{
private:
    void *m_ptr;

public:
    GCAnimEncodedFrames() {}
    GCAnimEncodedFrames(void *ptr) : m_ptr(ptr) {}

    CBufferString GetFileName() const { return GetSchemaValue<CBufferString>(m_ptr, "CAnimEncodedFrames", "m_fileName"); }
    void SetFileName(CBufferString value) { SetSchemaValue(m_ptr, "CAnimEncodedFrames", "m_fileName", false, value); }
    int32_t GetFrames() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimEncodedFrames", "m_nFrames"); }
    void SetFrames(int32_t value) { SetSchemaValue(m_ptr, "CAnimEncodedFrames", "m_nFrames", false, value); }
    int32_t GetFramesPerBlock() const { return GetSchemaValue<int32_t>(m_ptr, "CAnimEncodedFrames", "m_nFramesPerBlock"); }
    void SetFramesPerBlock(int32_t value) { SetSchemaValue(m_ptr, "CAnimEncodedFrames", "m_nFramesPerBlock", false, value); }
    std::vector<GCAnimFrameBlockAnim> GetFrameblockArray() const { CUtlVector<GCAnimFrameBlockAnim>* vec = GetSchemaValue<CUtlVector<GCAnimFrameBlockAnim>*>(m_ptr, "CAnimEncodedFrames", "m_frameblockArray"); std::vector<GCAnimFrameBlockAnim> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFrameblockArray(std::vector<GCAnimFrameBlockAnim> value) { SetSchemaValueCUtlVector<GCAnimFrameBlockAnim>(m_ptr, "CAnimEncodedFrames", "m_frameblockArray", false, value); }
    GCAnimEncodeDifference GetUsageDifferences() const { return GetSchemaValue<GCAnimEncodeDifference>(m_ptr, "CAnimEncodedFrames", "m_usageDifferences"); }
    void SetUsageDifferences(GCAnimEncodeDifference value) { SetSchemaValue(m_ptr, "CAnimEncodedFrames", "m_usageDifferences", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif