class Gdynpitchvol_base_t;

#ifndef _gcdynpitchvol_base_t_h
#define _gcdynpitchvol_base_t_h

#include "../../../scripting.h"




class Gdynpitchvol_base_t
{
private:
    void *m_ptr;

public:
    Gdynpitchvol_base_t() {}
    Gdynpitchvol_base_t(void *ptr) : m_ptr(ptr) {}

    int32_t GetPreset() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "preset"); }
    void SetPreset(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "preset", true, value); }
    int32_t GetPitchrun() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "pitchrun"); }
    void SetPitchrun(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "pitchrun", true, value); }
    int32_t GetPitchstart() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "pitchstart"); }
    void SetPitchstart(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "pitchstart", true, value); }
    int32_t GetSpinup() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "spinup"); }
    void SetSpinup(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "spinup", true, value); }
    int32_t GetSpindown() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "spindown"); }
    void SetSpindown(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "spindown", true, value); }
    int32_t GetVolrun() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "volrun"); }
    void SetVolrun(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "volrun", true, value); }
    int32_t GetVolstart() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "volstart"); }
    void SetVolstart(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "volstart", true, value); }
    int32_t GetFadein() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "fadein"); }
    void SetFadein(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "fadein", true, value); }
    int32_t GetFadeout() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "fadeout"); }
    void SetFadeout(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "fadeout", true, value); }
    int32_t GetLfotype() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lfotype"); }
    void SetLfotype(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lfotype", true, value); }
    int32_t GetLforate() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lforate"); }
    void SetLforate(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lforate", true, value); }
    int32_t GetLfomodpitch() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lfomodpitch"); }
    void SetLfomodpitch(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lfomodpitch", true, value); }
    int32_t GetLfomodvol() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lfomodvol"); }
    void SetLfomodvol(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lfomodvol", true, value); }
    int32_t GetCspinup() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "cspinup"); }
    void SetCspinup(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "cspinup", true, value); }
    int32_t GetCspincount() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "cspincount"); }
    void SetCspincount(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "cspincount", true, value); }
    int32_t GetPitch() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "pitch"); }
    void SetPitch(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "pitch", true, value); }
    int32_t GetSpinupsav() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "spinupsav"); }
    void SetSpinupsav(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "spinupsav", true, value); }
    int32_t GetSpindownsav() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "spindownsav"); }
    void SetSpindownsav(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "spindownsav", true, value); }
    int32_t GetPitchfrac() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "pitchfrac"); }
    void SetPitchfrac(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "pitchfrac", true, value); }
    int32_t GetVol() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "vol"); }
    void SetVol(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "vol", true, value); }
    int32_t GetFadeinsav() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "fadeinsav"); }
    void SetFadeinsav(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "fadeinsav", true, value); }
    int32_t GetFadeoutsav() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "fadeoutsav"); }
    void SetFadeoutsav(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "fadeoutsav", true, value); }
    int32_t GetVolfrac() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "volfrac"); }
    void SetVolfrac(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "volfrac", true, value); }
    int32_t GetLfofrac() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lfofrac"); }
    void SetLfofrac(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lfofrac", true, value); }
    int32_t GetLfomult() const { return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lfomult"); }
    void SetLfomult(int32_t value) { SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lfomult", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif