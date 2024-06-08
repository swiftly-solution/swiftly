#include "../../../core/scripting/generated/classes/GSequenceWeightedList_t.h"
#include "../core.h"

void SetupLuaClassGSequenceWeightedList_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSequenceWeightedList_t>("SequenceWeightedList_t")
        .addProperty("Sequence", &GSequenceWeightedList_t::GetSequence, &GSequenceWeightedList_t::SetSequence)
        .addProperty("RelativeWeight", &GSequenceWeightedList_t::GetRelativeWeight, &GSequenceWeightedList_t::SetRelativeWeight)
        .endClass();
}