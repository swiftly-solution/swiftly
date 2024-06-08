#include "../../../core/scripting/generated/classes/GC_INIT_RandomSequence.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomSequence(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomSequence>("C_INIT_RandomSequence")
        .addProperty("SequenceMin", &GC_INIT_RandomSequence::GetSequenceMin, &GC_INIT_RandomSequence::SetSequenceMin)
        .addProperty("SequenceMax", &GC_INIT_RandomSequence::GetSequenceMax, &GC_INIT_RandomSequence::SetSequenceMax)
        .addProperty("Shuffle", &GC_INIT_RandomSequence::GetShuffle, &GC_INIT_RandomSequence::SetShuffle)
        .addProperty("Linear", &GC_INIT_RandomSequence::GetLinear, &GC_INIT_RandomSequence::SetLinear)
        .addProperty("WeightedList", &GC_INIT_RandomSequence::GetWeightedList, &GC_INIT_RandomSequence::SetWeightedList)
        .endClass();
}