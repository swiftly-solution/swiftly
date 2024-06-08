#include "../../../core/scripting/generated/classes/GC_INIT_RandomSecondSequence.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomSecondSequence(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomSecondSequence>("C_INIT_RandomSecondSequence")
        .addProperty("SequenceMin", &GC_INIT_RandomSecondSequence::GetSequenceMin, &GC_INIT_RandomSecondSequence::SetSequenceMin)
        .addProperty("SequenceMax", &GC_INIT_RandomSecondSequence::GetSequenceMax, &GC_INIT_RandomSecondSequence::SetSequenceMax)
        .endClass();
}