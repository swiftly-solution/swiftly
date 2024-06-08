#include "../../../core/scripting/generated/classes/GVMixPitchShiftDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixPitchShiftDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixPitchShiftDesc_t>("VMixPitchShiftDesc_t")
        .addProperty("GrainSampleCount", &GVMixPitchShiftDesc_t::GetGrainSampleCount, &GVMixPitchShiftDesc_t::SetGrainSampleCount)
        .addProperty("PitchShift", &GVMixPitchShiftDesc_t::GetPitchShift, &GVMixPitchShiftDesc_t::SetPitchShift)
        .addProperty("Quality", &GVMixPitchShiftDesc_t::GetQuality, &GVMixPitchShiftDesc_t::SetQuality)
        .addProperty("ProcType", &GVMixPitchShiftDesc_t::GetProcType, &GVMixPitchShiftDesc_t::SetProcType)
        .endClass();
}