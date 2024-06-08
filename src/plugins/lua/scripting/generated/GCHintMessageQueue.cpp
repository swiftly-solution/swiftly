#include "../../../core/scripting/generated/classes/GCHintMessageQueue.h"
#include "../core.h"

void SetupLuaClassGCHintMessageQueue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHintMessageQueue>("CHintMessageQueue")
        .addProperty("TmMessageEnd", &GCHintMessageQueue::GetTmMessageEnd, &GCHintMessageQueue::SetTmMessageEnd)
        .addProperty("PlayerController", &GCHintMessageQueue::GetPlayerController, &GCHintMessageQueue::SetPlayerController)
        .endClass();
}