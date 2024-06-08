#include "../../../core/scripting/generated/classes/GCCommentarySystem.h"
#include "../core.h"

void SetupLuaClassGCCommentarySystem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCommentarySystem>("CCommentarySystem")
        .addProperty("CommentaryConvarsChanging", &GCCommentarySystem::GetCommentaryConvarsChanging, &GCCommentarySystem::SetCommentaryConvarsChanging)
        .addProperty("CommentaryEnabledMidGame", &GCCommentarySystem::GetCommentaryEnabledMidGame, &GCCommentarySystem::SetCommentaryEnabledMidGame)
        .addProperty("TeleportStage", &GCCommentarySystem::GetTeleportStage, &GCCommentarySystem::SetTeleportStage)
        .addProperty("CheatState", &GCCommentarySystem::GetCheatState, &GCCommentarySystem::SetCheatState)
        .addProperty("IsFirstSpawnGroupToLoad", &GCCommentarySystem::GetIsFirstSpawnGroupToLoad, &GCCommentarySystem::SetIsFirstSpawnGroupToLoad)
        .endClass();
}