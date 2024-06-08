class GSequenceHistory_t;

#ifndef _gcsequencehistory_t_h
#define _gcsequencehistory_t_h

#include "../../../scripting.h"

#include "../types/GAnimLoopMode_t.h"


class GSequenceHistory_t
{
private:
    void *m_ptr;

public:
    GSequenceHistory_t() {}
    GSequenceHistory_t(void *ptr) : m_ptr(ptr) {}

    float GetSeqFixedCycle() const { return GetSchemaValue<float>(m_ptr, "SequenceHistory_t", "m_flSeqFixedCycle"); }
    void SetSeqFixedCycle(float value) { SetSchemaValue(m_ptr, "SequenceHistory_t", "m_flSeqFixedCycle", true, value); }
    AnimLoopMode_t GetSeqLoopMode() const { return GetSchemaValue<AnimLoopMode_t>(m_ptr, "SequenceHistory_t", "m_nSeqLoopMode"); }
    void SetSeqLoopMode(AnimLoopMode_t value) { SetSchemaValue(m_ptr, "SequenceHistory_t", "m_nSeqLoopMode", true, value); }
    float GetPlaybackRate() const { return GetSchemaValue<float>(m_ptr, "SequenceHistory_t", "m_flPlaybackRate"); }
    void SetPlaybackRate(float value) { SetSchemaValue(m_ptr, "SequenceHistory_t", "m_flPlaybackRate", true, value); }
    float GetCyclesPerSecond() const { return GetSchemaValue<float>(m_ptr, "SequenceHistory_t", "m_flCyclesPerSecond"); }
    void SetCyclesPerSecond(float value) { SetSchemaValue(m_ptr, "SequenceHistory_t", "m_flCyclesPerSecond", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif