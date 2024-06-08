class GCSoundEnt;

#ifndef _gccsoundent_h
#define _gccsoundent_h

#include "../../../scripting.h"


#include "GCSound.h"

class GCSoundEnt
{
private:
    void *m_ptr;

public:
    GCSoundEnt() {}
    GCSoundEnt(void *ptr) : m_ptr(ptr) {}

    int32_t GetFreeSound() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundEnt", "m_iFreeSound"); }
    void SetFreeSound(int32_t value) { SetSchemaValue(m_ptr, "CSoundEnt", "m_iFreeSound", false, value); }
    int32_t GetActiveSound() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundEnt", "m_iActiveSound"); }
    void SetActiveSound(int32_t value) { SetSchemaValue(m_ptr, "CSoundEnt", "m_iActiveSound", false, value); }
    int32_t GetCLastActiveSounds() const { return GetSchemaValue<int32_t>(m_ptr, "CSoundEnt", "m_cLastActiveSounds"); }
    void SetCLastActiveSounds(int32_t value) { SetSchemaValue(m_ptr, "CSoundEnt", "m_cLastActiveSounds", false, value); }
    std::vector<GCSound> GetSoundPool() const { GCSound* outValue = GetSchemaValue<GCSound*>(m_ptr, "CSoundEnt", "m_SoundPool"); std::vector<GCSound> ret; for(int i = 0; i < 128; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetSoundPool(std::vector<GCSound> value) { GCSound* outValue = GetSchemaValue<GCSound*>(m_ptr, "CSoundEnt", "m_SoundPool"); for(int i = 0; i < 128; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CSoundEnt", "m_SoundPool", false, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif