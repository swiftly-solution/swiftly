#include "../../../core/scripting/generated/classes/GSequenceHistory_t.h"
#include "../core.h"

void SetupLuaClassGSequenceHistory_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSequenceHistory_t>("SequenceHistory_t")
        .addProperty("SeqFixedCycle", &GSequenceHistory_t::GetSeqFixedCycle, &GSequenceHistory_t::SetSeqFixedCycle)
        .addProperty("SeqLoopMode", &GSequenceHistory_t::GetSeqLoopMode, &GSequenceHistory_t::SetSeqLoopMode)
        .addProperty("PlaybackRate", &GSequenceHistory_t::GetPlaybackRate, &GSequenceHistory_t::SetPlaybackRate)
        .addProperty("CyclesPerSecond", &GSequenceHistory_t::GetCyclesPerSecond, &GSequenceHistory_t::SetCyclesPerSecond)
        .endClass();
}