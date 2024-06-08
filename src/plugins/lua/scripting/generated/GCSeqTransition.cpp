#include "../../../core/scripting/generated/classes/GCSeqTransition.h"
#include "../core.h"

void SetupLuaClassGCSeqTransition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqTransition>("CSeqTransition")
        .addProperty("FadeInTime", &GCSeqTransition::GetFadeInTime, &GCSeqTransition::SetFadeInTime)
        .addProperty("FadeOutTime", &GCSeqTransition::GetFadeOutTime, &GCSeqTransition::SetFadeOutTime)
        .endClass();
}