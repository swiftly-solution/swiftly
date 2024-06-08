class GCMotionNodeBlend1D;

#ifndef _gccmotionnodeblend1d_h
#define _gccmotionnodeblend1d_h

#include "../../../scripting.h"


#include "GMotionBlendItem.h"

class GCMotionNodeBlend1D
{
private:
    void *m_ptr;

public:
    GCMotionNodeBlend1D() {}
    GCMotionNodeBlend1D(void *ptr) : m_ptr(ptr) {}

    std::vector<GMotionBlendItem> GetBlendItems() const { CUtlVector<GMotionBlendItem>* vec = GetSchemaValue<CUtlVector<GMotionBlendItem>*>(m_ptr, "CMotionNodeBlend1D", "m_blendItems"); std::vector<GMotionBlendItem> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBlendItems(std::vector<GMotionBlendItem> value) { SetSchemaValueCUtlVector<GMotionBlendItem>(m_ptr, "CMotionNodeBlend1D", "m_blendItems", false, value); }
    int32_t GetParamIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CMotionNodeBlend1D", "m_nParamIndex"); }
    void SetParamIndex(int32_t value) { SetSchemaValue(m_ptr, "CMotionNodeBlend1D", "m_nParamIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif