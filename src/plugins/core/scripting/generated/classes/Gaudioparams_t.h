class Gaudioparams_t;

#ifndef _gcaudioparams_t_h
#define _gcaudioparams_t_h

#include "../../../scripting.h"




class Gaudioparams_t
{
private:
    void *m_ptr;

public:
    Gaudioparams_t() {}
    Gaudioparams_t(void *ptr) : m_ptr(ptr) {}

    std::vector<Vector> GetLocalSound() const { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "audioparams_t", "localSound"); std::vector<Vector> ret; for(int i = 0; i < 8; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetLocalSound(std::vector<Vector> value) { Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "audioparams_t", "localSound"); for(int i = 0; i < 8; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "audioparams_t", "localSound", true, outValue); }
    int32_t GetSoundscapeIndex() const { return GetSchemaValue<int32_t>(m_ptr, "audioparams_t", "soundscapeIndex"); }
    void SetSoundscapeIndex(int32_t value) { SetSchemaValue(m_ptr, "audioparams_t", "soundscapeIndex", true, value); }
    uint8_t GetLocalBits() const { return GetSchemaValue<uint8_t>(m_ptr, "audioparams_t", "localBits"); }
    void SetLocalBits(uint8_t value) { SetSchemaValue(m_ptr, "audioparams_t", "localBits", true, value); }
    int32_t GetSoundscapeEntityListIndex() const { return GetSchemaValue<int32_t>(m_ptr, "audioparams_t", "soundscapeEntityListIndex"); }
    void SetSoundscapeEntityListIndex(int32_t value) { SetSchemaValue(m_ptr, "audioparams_t", "soundscapeEntityListIndex", true, value); }
    uint32_t GetSoundEventHash() const { return GetSchemaValue<uint32_t>(m_ptr, "audioparams_t", "soundEventHash"); }
    void SetSoundEventHash(uint32_t value) { SetSchemaValue(m_ptr, "audioparams_t", "soundEventHash", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif