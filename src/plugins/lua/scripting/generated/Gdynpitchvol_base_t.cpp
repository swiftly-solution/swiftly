#include "../../../core/scripting/generated/classes/Gdynpitchvol_base_t.h"
#include "../core.h"

void SetupLuaClassGdynpitchvol_base_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gdynpitchvol_base_t>("dynpitchvol_base_t")
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
        .endClass();
}