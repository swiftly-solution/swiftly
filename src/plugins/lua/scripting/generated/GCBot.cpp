#include "../../../core/scripting/generated/classes/GCBot.h"
#include "../core.h"

void SetupLuaClassGCBot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBot>("CBot")
        .addProperty("Controller", &GCBot::GetController, &GCBot::SetController)
        .addProperty("Player", &GCBot::GetPlayer, &GCBot::SetPlayer)
        .addProperty("HasSpawned", &GCBot::GetHasSpawned, &GCBot::SetHasSpawned)
        .addProperty("Id", &GCBot::GetId, &GCBot::SetId)
        .addProperty("IsRunning", &GCBot::GetIsRunning, &GCBot::SetIsRunning)
        .addProperty("IsCrouching", &GCBot::GetIsCrouching, &GCBot::SetIsCrouching)
        .addProperty("ForwardSpeed", &GCBot::GetForwardSpeed, &GCBot::SetForwardSpeed)
        .addProperty("LeftSpeed", &GCBot::GetLeftSpeed, &GCBot::SetLeftSpeed)
        .addProperty("VerticalSpeed", &GCBot::GetVerticalSpeed, &GCBot::SetVerticalSpeed)
        .addProperty("ButtonFlags", &GCBot::GetButtonFlags, &GCBot::SetButtonFlags)
        .addProperty("JumpTimestamp", &GCBot::GetJumpTimestamp, &GCBot::SetJumpTimestamp)
        .addProperty("ViewForward", &GCBot::GetViewForward, &GCBot::SetViewForward)
        .addProperty("PostureStackIndex", &GCBot::GetPostureStackIndex, &GCBot::SetPostureStackIndex)
        .endClass();
}