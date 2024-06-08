class GCAI_Expresser;

#ifndef _gccai_expresser_h
#define _gccai_expresser_h

#include "../../../scripting.h"


#include "GCBaseFlex.h"

class GCAI_Expresser
{
private:
    void *m_ptr;

public:
    GCAI_Expresser() {}
    GCAI_Expresser(void *ptr) : m_ptr(ptr) {}

    int32_t GetVoicePitch() const { return GetSchemaValue<int32_t>(m_ptr, "CAI_Expresser", "m_voicePitch"); }
    void SetVoicePitch(int32_t value) { SetSchemaValue(m_ptr, "CAI_Expresser", "m_voicePitch", false, value); }
    bool GetAllowSpeakingInterrupts() const { return GetSchemaValue<bool>(m_ptr, "CAI_Expresser", "m_bAllowSpeakingInterrupts"); }
    void SetAllowSpeakingInterrupts(bool value) { SetSchemaValue(m_ptr, "CAI_Expresser", "m_bAllowSpeakingInterrupts", false, value); }
    bool GetConsiderSceneInvolvementAsSpeech() const { return GetSchemaValue<bool>(m_ptr, "CAI_Expresser", "m_bConsiderSceneInvolvementAsSpeech"); }
    void SetConsiderSceneInvolvementAsSpeech(bool value) { SetSchemaValue(m_ptr, "CAI_Expresser", "m_bConsiderSceneInvolvementAsSpeech", false, value); }
    bool GetSceneEntityDisabled() const { return GetSchemaValue<bool>(m_ptr, "CAI_Expresser", "m_bSceneEntityDisabled"); }
    void SetSceneEntityDisabled(bool value) { SetSchemaValue(m_ptr, "CAI_Expresser", "m_bSceneEntityDisabled", false, value); }
    int32_t GetLastSpokenPriority() const { return GetSchemaValue<int32_t>(m_ptr, "CAI_Expresser", "m_nLastSpokenPriority"); }
    void SetLastSpokenPriority(int32_t value) { SetSchemaValue(m_ptr, "CAI_Expresser", "m_nLastSpokenPriority", false, value); }
    GCBaseFlex* GetOuter() const { return GetSchemaValue<GCBaseFlex*>(m_ptr, "CAI_Expresser", "m_pOuter"); }
    void SetOuter(GCBaseFlex* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Outer' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif