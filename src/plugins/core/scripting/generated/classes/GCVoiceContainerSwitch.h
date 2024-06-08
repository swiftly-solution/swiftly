class GCVoiceContainerSwitch;

#ifndef _gccvoicecontainerswitch_h
#define _gccvoicecontainerswitch_h

#include "../../../scripting.h"


#include "GCVoiceContainerBase.h"

class GCVoiceContainerSwitch
{
private:
    void *m_ptr;

public:
    GCVoiceContainerSwitch() {}
    GCVoiceContainerSwitch(void *ptr) : m_ptr(ptr) {}

    std::vector<GCVoiceContainerBase*> GetSoundsToPlay() const { CUtlVector<GCVoiceContainerBase*>* vec = GetSchemaValue<CUtlVector<GCVoiceContainerBase*>*>(m_ptr, "CVoiceContainerSwitch", "m_soundsToPlay"); std::vector<GCVoiceContainerBase*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSoundsToPlay(std::vector<GCVoiceContainerBase*> value) { SetSchemaValueCUtlVector<GCVoiceContainerBase*>(m_ptr, "CVoiceContainerSwitch", "m_soundsToPlay", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif