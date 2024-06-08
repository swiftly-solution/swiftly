class GCAmbientGeneric;

#ifndef _gccambientgeneric_h
#define _gccambientgeneric_h

#include "../../../scripting.h"


#include "Gdynpitchvol_t.h"
#include "GCBaseEntity.h"

class GCAmbientGeneric
{
private:
    void *m_ptr;

public:
    GCAmbientGeneric() {}
    GCAmbientGeneric(void *ptr) : m_ptr(ptr) {}

    float GetRadius() const { return GetSchemaValue<float>(m_ptr, "CAmbientGeneric", "m_radius"); }
    void SetRadius(float value) { SetSchemaValue(m_ptr, "CAmbientGeneric", "m_radius", false, value); }
    float GetMaxRadius() const { return GetSchemaValue<float>(m_ptr, "CAmbientGeneric", "m_flMaxRadius"); }
    void SetMaxRadius(float value) { SetSchemaValue(m_ptr, "CAmbientGeneric", "m_flMaxRadius", false, value); }
    soundlevel_t GetSoundLevel() const { return GetSchemaValue<soundlevel_t>(m_ptr, "CAmbientGeneric", "m_iSoundLevel"); }
    void SetSoundLevel(soundlevel_t value) { SetSchemaValue(m_ptr, "CAmbientGeneric", "m_iSoundLevel", false, value); }
    Gdynpitchvol_t GetDpv() const { return GetSchemaValue<Gdynpitchvol_t>(m_ptr, "CAmbientGeneric", "m_dpv"); }
    void SetDpv(Gdynpitchvol_t value) { SetSchemaValue(m_ptr, "CAmbientGeneric", "m_dpv", false, value); }
    bool GetActive() const { return GetSchemaValue<bool>(m_ptr, "CAmbientGeneric", "m_fActive"); }
    void SetActive(bool value) { SetSchemaValue(m_ptr, "CAmbientGeneric", "m_fActive", false, value); }
    bool GetLooping() const { return GetSchemaValue<bool>(m_ptr, "CAmbientGeneric", "m_fLooping"); }
    void SetLooping(bool value) { SetSchemaValue(m_ptr, "CAmbientGeneric", "m_fLooping", false, value); }
    CUtlSymbolLarge GetSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAmbientGeneric", "m_iszSound"); }
    void SetSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CAmbientGeneric", "m_iszSound", false, value); }
    CUtlSymbolLarge GetSourceEntName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CAmbientGeneric", "m_sSourceEntName"); }
    void SetSourceEntName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CAmbientGeneric", "m_sSourceEntName", false, value); }
    GCBaseEntity* GetSoundSource() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CAmbientGeneric", "m_hSoundSource"); }
    void SetSoundSource(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'SoundSource' is not possible.\n"); }
    CEntityIndex GetSoundSourceEntIndex() const { return GetSchemaValue<CEntityIndex>(m_ptr, "CAmbientGeneric", "m_nSoundSourceEntIndex"); }
    void SetSoundSourceEntIndex(CEntityIndex value) { SetSchemaValue(m_ptr, "CAmbientGeneric", "m_nSoundSourceEntIndex", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif