#include "../../../core/scripting/generated/classes/GC_INIT_RandomModelSequence.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomModelSequence(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomModelSequence>("C_INIT_RandomModelSequence")
        .addProperty("ActivityName", &GC_INIT_RandomModelSequence::GetActivityName, &GC_INIT_RandomModelSequence::SetActivityName)
        .addProperty("SequenceName", &GC_INIT_RandomModelSequence::GetSequenceName, &GC_INIT_RandomModelSequence::SetSequenceName)
        .endClass();
}