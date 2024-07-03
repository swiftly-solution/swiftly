#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gdynpitchvol_base_t::Gdynpitchvol_base_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gdynpitchvol_base_t::Gdynpitchvol_base_t(void *ptr) {
    m_ptr = ptr;
}
int32_t Gdynpitchvol_base_t::GetPreset() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "preset");
}
void Gdynpitchvol_base_t::SetPreset(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "preset", true, value);
}
int32_t Gdynpitchvol_base_t::GetPitchrun() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "pitchrun");
}
void Gdynpitchvol_base_t::SetPitchrun(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "pitchrun", true, value);
}
int32_t Gdynpitchvol_base_t::GetPitchstart() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "pitchstart");
}
void Gdynpitchvol_base_t::SetPitchstart(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "pitchstart", true, value);
}
int32_t Gdynpitchvol_base_t::GetSpinup() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "spinup");
}
void Gdynpitchvol_base_t::SetSpinup(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "spinup", true, value);
}
int32_t Gdynpitchvol_base_t::GetSpindown() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "spindown");
}
void Gdynpitchvol_base_t::SetSpindown(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "spindown", true, value);
}
int32_t Gdynpitchvol_base_t::GetVolrun() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "volrun");
}
void Gdynpitchvol_base_t::SetVolrun(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "volrun", true, value);
}
int32_t Gdynpitchvol_base_t::GetVolstart() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "volstart");
}
void Gdynpitchvol_base_t::SetVolstart(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "volstart", true, value);
}
int32_t Gdynpitchvol_base_t::GetFadein() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "fadein");
}
void Gdynpitchvol_base_t::SetFadein(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "fadein", true, value);
}
int32_t Gdynpitchvol_base_t::GetFadeout() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "fadeout");
}
void Gdynpitchvol_base_t::SetFadeout(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "fadeout", true, value);
}
int32_t Gdynpitchvol_base_t::GetLfotype() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lfotype");
}
void Gdynpitchvol_base_t::SetLfotype(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lfotype", true, value);
}
int32_t Gdynpitchvol_base_t::GetLforate() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lforate");
}
void Gdynpitchvol_base_t::SetLforate(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lforate", true, value);
}
int32_t Gdynpitchvol_base_t::GetLfomodpitch() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lfomodpitch");
}
void Gdynpitchvol_base_t::SetLfomodpitch(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lfomodpitch", true, value);
}
int32_t Gdynpitchvol_base_t::GetLfomodvol() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lfomodvol");
}
void Gdynpitchvol_base_t::SetLfomodvol(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lfomodvol", true, value);
}
int32_t Gdynpitchvol_base_t::GetCspinup() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "cspinup");
}
void Gdynpitchvol_base_t::SetCspinup(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "cspinup", true, value);
}
int32_t Gdynpitchvol_base_t::GetCspincount() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "cspincount");
}
void Gdynpitchvol_base_t::SetCspincount(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "cspincount", true, value);
}
int32_t Gdynpitchvol_base_t::GetPitch() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "pitch");
}
void Gdynpitchvol_base_t::SetPitch(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "pitch", true, value);
}
int32_t Gdynpitchvol_base_t::GetSpinupsav() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "spinupsav");
}
void Gdynpitchvol_base_t::SetSpinupsav(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "spinupsav", true, value);
}
int32_t Gdynpitchvol_base_t::GetSpindownsav() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "spindownsav");
}
void Gdynpitchvol_base_t::SetSpindownsav(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "spindownsav", true, value);
}
int32_t Gdynpitchvol_base_t::GetPitchfrac() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "pitchfrac");
}
void Gdynpitchvol_base_t::SetPitchfrac(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "pitchfrac", true, value);
}
int32_t Gdynpitchvol_base_t::GetVol() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "vol");
}
void Gdynpitchvol_base_t::SetVol(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "vol", true, value);
}
int32_t Gdynpitchvol_base_t::GetFadeinsav() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "fadeinsav");
}
void Gdynpitchvol_base_t::SetFadeinsav(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "fadeinsav", true, value);
}
int32_t Gdynpitchvol_base_t::GetFadeoutsav() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "fadeoutsav");
}
void Gdynpitchvol_base_t::SetFadeoutsav(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "fadeoutsav", true, value);
}
int32_t Gdynpitchvol_base_t::GetVolfrac() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "volfrac");
}
void Gdynpitchvol_base_t::SetVolfrac(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "volfrac", true, value);
}
int32_t Gdynpitchvol_base_t::GetLfofrac() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lfofrac");
}
void Gdynpitchvol_base_t::SetLfofrac(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lfofrac", true, value);
}
int32_t Gdynpitchvol_base_t::GetLfomult() const {
    return GetSchemaValue<int32_t>(m_ptr, "dynpitchvol_base_t", "lfomult");
}
void Gdynpitchvol_base_t::SetLfomult(int32_t value) {
    SetSchemaValue(m_ptr, "dynpitchvol_base_t", "lfomult", true, value);
}
std::string Gdynpitchvol_base_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gdynpitchvol_base_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassdynpitchvol_base_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gdynpitchvol_base_t>("dynpitchvol_base_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Preset", &Gdynpitchvol_base_t::GetPreset, &Gdynpitchvol_base_t::SetPreset)
        .addProperty("Pitchrun", &Gdynpitchvol_base_t::GetPitchrun, &Gdynpitchvol_base_t::SetPitchrun)
        .addProperty("Pitchstart", &Gdynpitchvol_base_t::GetPitchstart, &Gdynpitchvol_base_t::SetPitchstart)
        .addProperty("Spinup", &Gdynpitchvol_base_t::GetSpinup, &Gdynpitchvol_base_t::SetSpinup)
        .addProperty("Spindown", &Gdynpitchvol_base_t::GetSpindown, &Gdynpitchvol_base_t::SetSpindown)
        .addProperty("Volrun", &Gdynpitchvol_base_t::GetVolrun, &Gdynpitchvol_base_t::SetVolrun)
        .addProperty("Volstart", &Gdynpitchvol_base_t::GetVolstart, &Gdynpitchvol_base_t::SetVolstart)
        .addProperty("Fadein", &Gdynpitchvol_base_t::GetFadein, &Gdynpitchvol_base_t::SetFadein)
        .addProperty("Fadeout", &Gdynpitchvol_base_t::GetFadeout, &Gdynpitchvol_base_t::SetFadeout)
        .addProperty("Lfotype", &Gdynpitchvol_base_t::GetLfotype, &Gdynpitchvol_base_t::SetLfotype)
        .addProperty("Lforate", &Gdynpitchvol_base_t::GetLforate, &Gdynpitchvol_base_t::SetLforate)
        .addProperty("Lfomodpitch", &Gdynpitchvol_base_t::GetLfomodpitch, &Gdynpitchvol_base_t::SetLfomodpitch)
        .addProperty("Lfomodvol", &Gdynpitchvol_base_t::GetLfomodvol, &Gdynpitchvol_base_t::SetLfomodvol)
        .addProperty("Cspinup", &Gdynpitchvol_base_t::GetCspinup, &Gdynpitchvol_base_t::SetCspinup)
        .addProperty("Cspincount", &Gdynpitchvol_base_t::GetCspincount, &Gdynpitchvol_base_t::SetCspincount)
        .addProperty("Pitch", &Gdynpitchvol_base_t::GetPitch, &Gdynpitchvol_base_t::SetPitch)
        .addProperty("Spinupsav", &Gdynpitchvol_base_t::GetSpinupsav, &Gdynpitchvol_base_t::SetSpinupsav)
        .addProperty("Spindownsav", &Gdynpitchvol_base_t::GetSpindownsav, &Gdynpitchvol_base_t::SetSpindownsav)
        .addProperty("Pitchfrac", &Gdynpitchvol_base_t::GetPitchfrac, &Gdynpitchvol_base_t::SetPitchfrac)
        .addProperty("Vol", &Gdynpitchvol_base_t::GetVol, &Gdynpitchvol_base_t::SetVol)
        .addProperty("Fadeinsav", &Gdynpitchvol_base_t::GetFadeinsav, &Gdynpitchvol_base_t::SetFadeinsav)
        .addProperty("Fadeoutsav", &Gdynpitchvol_base_t::GetFadeoutsav, &Gdynpitchvol_base_t::SetFadeoutsav)
        .addProperty("Volfrac", &Gdynpitchvol_base_t::GetVolfrac, &Gdynpitchvol_base_t::SetVolfrac)
        .addProperty("Lfofrac", &Gdynpitchvol_base_t::GetLfofrac, &Gdynpitchvol_base_t::SetLfofrac)
        .addProperty("Lfomult", &Gdynpitchvol_base_t::GetLfomult, &Gdynpitchvol_base_t::SetLfomult)
        .addFunction("ToPtr", &Gdynpitchvol_base_t::ToPtr)
        .addFunction("IsValid", &Gdynpitchvol_base_t::IsValid)
        .endClass();
}