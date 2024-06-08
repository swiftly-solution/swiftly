class GCAudioSentence;

#ifndef _gccaudiosentence_h
#define _gccaudiosentence_h

#include "../../../scripting.h"


#include "GCAudioPhonemeTag.h"
#include "GCAudioEmphasisSample.h"
#include "GCAudioMorphData.h"

class GCAudioSentence
{
private:
    void *m_ptr;

public:
    GCAudioSentence() {}
    GCAudioSentence(void *ptr) : m_ptr(ptr) {}

    bool GetShouldVoiceDuck() const { return GetSchemaValue<bool>(m_ptr, "CAudioSentence", "m_bShouldVoiceDuck"); }
    void SetShouldVoiceDuck(bool value) { SetSchemaValue(m_ptr, "CAudioSentence", "m_bShouldVoiceDuck", false, value); }
    std::vector<GCAudioPhonemeTag> GetRunTimePhonemes() const { CUtlVector<GCAudioPhonemeTag>* vec = GetSchemaValue<CUtlVector<GCAudioPhonemeTag>*>(m_ptr, "CAudioSentence", "m_RunTimePhonemes"); std::vector<GCAudioPhonemeTag> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRunTimePhonemes(std::vector<GCAudioPhonemeTag> value) { SetSchemaValueCUtlVector<GCAudioPhonemeTag>(m_ptr, "CAudioSentence", "m_RunTimePhonemes", false, value); }
    std::vector<GCAudioEmphasisSample> GetEmphasisSamples() const { CUtlVector<GCAudioEmphasisSample>* vec = GetSchemaValue<CUtlVector<GCAudioEmphasisSample>*>(m_ptr, "CAudioSentence", "m_EmphasisSamples"); std::vector<GCAudioEmphasisSample> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetEmphasisSamples(std::vector<GCAudioEmphasisSample> value) { SetSchemaValueCUtlVector<GCAudioEmphasisSample>(m_ptr, "CAudioSentence", "m_EmphasisSamples", false, value); }
    GCAudioMorphData GetMorphData() const { return GetSchemaValue<GCAudioMorphData>(m_ptr, "CAudioSentence", "m_morphData"); }
    void SetMorphData(GCAudioMorphData value) { SetSchemaValue(m_ptr, "CAudioSentence", "m_morphData", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif